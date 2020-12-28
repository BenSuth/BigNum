#include "BigNum.h"

/*****Constructors*****/
/*
 * Given a number as a string, intialize it as a BigNum 
 */
BigNum::BigNum(std::string n)
{
  if(n == "") this->number = "0";
  else this->number = n;

  if (n[0] == '-') 
  {
	  this->positive = false;
	  (this->number).erase((this->number).begin());  
  }  
  else this->positive = true;
}


/*
 * Given a number as a long long, intialize it as a BigNum 
 */
BigNum::BigNum(long long n)
{
  this->number = std::to_string(n);

  if (n < 0) 
  {
	  this->positive = false;
	  (this->number).erase((this->number).begin());  
  } 
  else this->positive = true;
}
/*****Constructors*****/

/*****Functions*****/
/*
 * Return BigNum as a string, add a negative sign if number is negative
 */
std::string BigNum::toString()
{
  if (!positive) return "-" + this->number;
  else return this->number;
}

/*
 * Return BigNum as a string, do not include negative sign
 */
std::string BigNum::abs()
{
  return this->number;
}

/*
 * get the length of a BigNum, sign does not contribute to length
 */
long long BigNum::length()
{
  return number.size();
}

/*
 * Overload this function with std::string
 * Change the number being stored by BigNum, this accounts for the sign
 */
void BigNum::setNumber(std::string n)
{
  this->number = n;

  if (n[0] == '-')      
  {
	  this->positive = false;
	  (this->number).erase((this->number).begin());  
  }  
  else this->positive = true;
}

/*
 * Overload function as long long
 * Change the number being stored by BigNum, this accounts for the sign
 */
void BigNum::setNumber(long long n)
{
  this->number = std::to_string(n);

  if (n < 0)       
  {
	  this->positive = false;
	  (this->number).erase((this->number).begin());  
  }  
  else this->positive = true;
}

/*
 * Returns true if the number is positive, false otherwise
 */
bool BigNum::getSign()
{
  return this->positive;
}

/*
 * Changes the sign of the number, equivalent to multiplying by -1
 */
bool BigNum::setSign(bool sign)
{
  return positive = sign;
}


/*
 * Static function
 * Given an integer between 1 and 64, convert the BigNum to the integer base
 * Throw exception if base is not between 1 and 64 inclusive
 */
BigNum BigNum::toBase(int base)
{
  try
  {
    if (base <= 0 || base >=65) throw base; // check for base errors

    // used to respresent all bases
    const std::string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const BigNum BASE(base);

    BigNum a = *this;
    a.setSign(true);
    BigNum result("");
    result.setSign(true);
    std::string newBase ="";

    /*
     * Modulus divide the BigNum by the base
     * insert remainder into beginning of the newBase string
     * divide the BigNum by base
     */
    while (a > ZERO) 
    {
      BigNum mod = a % BASE;
      a -= mod;
      if (a > ZERO) a /= BASE;
      newBase.insert(newBase.begin(), bases[stoi(mod.toString())]);
    }

    result.setNumber(newBase);
    result.setSign(positive);

    return result;
  }
  catch (int e)
  {
    std::cout << "Error, unable to convert to base, " << e << "." << std::endl;
  }
  return ZERO;
}

/*
 * Static function
 * Swap two instances of BigNum
 */
void BigNum::swap(BigNum *x,  BigNum *y) 
{ 
  BigNum temp = *x; 
  *x = *y; 
  *y = temp;

  x->setNumber(x->abs());
  y->setNumber(y->abs());
}    

/*
 * Static function
 * Computes the power of a BigNum base to a BigNum exponent
 * Throw exception if the exponent is negative because BigNum respresents integers 
 */
BigNum BigNum::pow(BigNum a, BigNum b)
{
  try
  {
    if (b < 0) throw ILLEGAL_NUMBER
    BigNum product = a;
    if (b == ONE) return a;
    if (b == ZERO) return ONE;
    for (BigNum i = ONE; i < b; i++)
    {
      product *= a;
    }

    product.setSign(false);
    return product;
  }

  catch (int e)
  {
    std::cout << "Error, second arguement must be a positive integer" << std::endl;
  }
  return ILLEGAL_NUMBER;
}
/*****Functions*****/


/*****Operators*****/
/* 
 * = operator 
 */
void BigNum::operator=(BigNum n)
{
  this->number = n.abs();
  this->positive = n.getSign();
}

/* 
 * == operator 
 * Return true if they have the same sign and their string numbers are equal
 */
bool BigNum::operator==(BigNum n) const
{
  if ((this->positive == n.getSign()) && (this->number == n.abs())) return true;
  else return false;
}

/* 
 * != operator
 * Return the negation of ==
 */
bool BigNum::operator!=(BigNum n) const
{
  return !(*this == n);
}

/* 
 * > operator
 * Comparisons are the same as integers
 * Check the signs, then inspect the number strings 
 * Return true if this instance is greater than BigNum n
 */
bool BigNum::operator>(BigNum n) const 
{
  if (this->positive && !n.getSign()) return true;
  else if (!this->positive && n.getSign()) return false;

  if (this->number.size() > n.abs().size()) 
	return (this->positive) ? true : false;
  else if (this->number.size() < n.abs().size())
	return (this->positive) ? false : true;

  for (int i = 0; i < this->number.size(); i++)
  {
	if (this->number[i] != n.abs()[i])
	{
	  return (this->positive) 
	  ? this->number[i] > n.abs()[i]
	  : this->number[i] < n.abs()[i];
	 }
  }
  return false; 
} 

/* 
 * >= operator 
 * Return true if BigNum is equal to or greater than BigNum n
 */
bool BigNum::operator>=(BigNum n) const
{
  return (*this > n || *this == n);
}

/* 
 * >= operator 
 * Return the negation of >=
 */
bool BigNum::operator<(BigNum n) const
{
  return !(*this >= n);
}

/* 
 * >= operator 
 * Return true if BigNum is equal to or less than BigNum n
 */
bool BigNum::operator<=(BigNum n) const
{
  return (*this < n || *this == n);
}

/* 
 * + operator
 * Elementary addition
 * Start at end of both strings, compute the result at each index + the carry of the 
 * previous index and insert into a result string at the beginning
 * Insert remaining indices of larger BigNum into results string
 */
BigNum BigNum::operator+(BigNum b) const
{
  BigNum a(number);
  a.setSign(positive);

  /* a + (-b) = a - b */
  if (a.getSign() && !b.getSign())
  {
    b.setSign(true);
    return a - b;
  }

  /* -a + b = b - a*/
  else if (!a.getSign() && b.getSign())
  {
    a.setSign(true);
    return b - a;
  }

  BigNum result("");
  std::string rNumber = "";
  int carry = 0;
  int sum;

  if (a.abs().length() > b.abs().length()) swap(&a, &b); 
	
  for (int i=a.abs().length()-1; i>=0; i--) 
  { 
	  sum = 
	  (
		(a.abs()[i]-'0') 
		+ (b.abs()[i+ b.abs().length() - a.abs().length()]-'0') 
		+ carry
	  ); 
	  rNumber.insert(rNumber.begin(), sum%10 + '0'); 
	  carry = sum/10; 
  } 

  for (int i=b.abs().length() - a.abs().length()-1; i>=0; i--) 
  { 
    int sum = ((b.abs()[i]-'0') + carry); 
    rNumber.insert(rNumber.begin(), sum%10 + '0'); 
    carry = sum/10; 
  } 

  if (carry) rNumber.insert(rNumber.begin(),carry + '0');
	
  result.setNumber(rNumber);
  result.setSign(positive);
  return result;
  
  return BigNum("");

}

/*
 * += operator
 * set this = this + BigNum b
 */
void BigNum::operator+=(BigNum b)
{
  this->operator=(this->operator+(b));
}


/* 
 * - operator
 * Elementary subtraction
 * Start at end of both strings, compute the index at each index - the carry of the 
 * previous index and insert into a result string at the beginning
 * Insert remaining indices of larger BigNum into results string
 */
BigNum BigNum::operator-(BigNum b) const
{
  BigNum a(number);
  a.setSign(positive);

  /* -a - b = -a + (-b) */
  if (!a.getSign() && b.getSign())
  {
    b.setSign(false);
    a.setSign(false);
    return a + b;
  }

  /* -a - (-b) == b - a */
  else if (!a.getSign() && !b.getSign())
  {
    b.setSign(true);
    a.setSign(true);
    return b - a;
  }

  /* a - (-b) == a + b */
  else if (a.getSign() && !b.getSign())
  {
    b.setSign(true);
    return a + b;
  }

  std::string rNumber ="";
  bool carry = false;
  int difference;
  bool rSign = true;

  if (b > a) 
  {
    rSign = false;
    swap(&a, &b);
  }

  for (int i = b.abs().length() - 1; i >= 0; i--) 
  {
    difference = (
      (a.abs()[i + a.abs().length() - b.abs().length()] - '0') - (b.abs()[i] - '0')
      - carry);
    
    if (difference >= 0) carry = false;
    else
    {
      difference += 10;
      carry = true;
    }

    rNumber.insert(rNumber.begin(), difference + '0');
  } 

  for (int i = a.abs().length() - b.abs().length() - 1; i >= 0; i--) 
  {
    if (a.abs()[i] == '0' && carry) 
    {
      rNumber.insert(rNumber.begin(), '9');
      continue;
    }

    difference = ((a.abs()[i] - '0') - carry);
    
    if (difference > 0 || i > 0) rNumber.insert(rNumber.begin(), difference + '0');
    carry = false;
  }

  /* erase leading zeros */
  BigNum result
  (
    rNumber.erase(0, std::min(rNumber.find_first_not_of('0'), rNumber.length()-1))
  );

  result.setSign(rSign);
  return result;
}

/*
 * -= operator
 * set this = this - BigNum b
 */
void BigNum::operator-=(BigNum b)
{
  this->operator=(this->operator-(b));
}

/*
 * Pre-increment
 * this += 1
 */
BigNum& BigNum::operator++()
{
  *this += ONE;
  return *this;
}

/*
 * Post-increment
 * this += 1
 */
BigNum BigNum::operator++(int n) 
{
  BigNum temp = *this;
  ++*this;
  return temp;
} 

/*
 * Pre-decrement
 * this -= 1
 */
BigNum& BigNum::operator--()
{
  *this -= ONE;
  return *this;
} 

/*
 * Post-decrement
 * this -= 1
 */
BigNum BigNum::operator--(int n)
{
  BigNum temp = *this;
  --*this;
  return temp;
}

/*
 * *operator
 * Function calculates the sign of the resulting BigNum
 * Use helper function to get the resulting string 
 */
BigNum BigNum::operator*(BigNum b)
{
  BigNum result("");
  result.setNumber(multiply(this->number, b.abs()));
  (this->positive == b.getSign()) ?
    result.setSign(true) 
    : result.setSign(false);
  return(result);
}

/*
 * Modified version of Karastuba algorithm
 * Perform multiplcation rescursively using divide and conquer
 * The big O of Karastuba  O(n^1.59) which is significantly faster
 * than the Elementary multiplcation approach of O(n^2)
 */
std::string BigNum::multiply(std::string x, std::string y)
{
  long long resultLength;

  if (x.length() >= y.length()) resultLength = x.length();
  else resultLength = y.length(); 

  while(x.length() < resultLength) x.insert(x.begin(), '0');
  while(y.length() < resultLength) y.insert(y.begin(), '0');
  if (resultLength == 1) return std::to_string((x[0] - '0')*(y[0]-'0'));
 
  BigNum xs1(x.substr(0, resultLength/2));
  BigNum xs2(x.substr(resultLength/2, resultLength - resultLength/2));
  BigNum ys1(y.substr(0, resultLength/2));
  BigNum ys2(y.substr(resultLength/2, resultLength - resultLength/2));

  BigNum product1(multiply(xs1.abs(), ys1.abs()));
  BigNum product2(multiply(xs2.abs(), ys2.abs()));
  BigNum product3(multiply((xs1 + xs2).abs(), (ys1 + ys2).abs()));

  BigNum difference = product3 - (product1 + product2);

  std::string p1 = product1.abs();
  std::string d1 = difference.abs();
  for (int i = 0; i < 2*(resultLength - resultLength/2); i++)
  {
    p1.append("0");
    if (i < resultLength - resultLength/2) d1.append("0");
  }

  product1.setNumber(p1);
  difference.setNumber(d1);

  std::string resultString = (product1 + product2 + difference).abs();

  return resultString.erase(0, std::min(resultString.find_first_not_of('0'), resultString.length()-1));
}

/*
 * *= operator
 * set this = this * BigNum b
 */
void BigNum::operator*=(BigNum b)
{
  this->operator=(this->operator*(b));
}

/*
 * / operator
 * Subtract divisor from divident, keep track of number of subtractions to get 
 * the divident <= 0
 * return the number of subtractions
 * Throw an exception to stop infininite loops with division by zero
 */
BigNum BigNum::operator/(BigNum b) const
{
  try
  {
    bool bSign = b.getSign();
    if (b == ZERO) throw ILLEGAL_NUMBER;

    if (b == ONE) return *this;

    BigNum a(number);
    a.setSign(true);
    b.setSign(true);
    BigNum count = BigNum("-1");

    if (a < b) return ZERO;

    while (a >= ZERO) 
    {
      a -= b;
      count++;
    }
    
    count.setSign((positive == bSign || count == ZERO)? true : false); 

    return count;
  }
  catch (int i)
  {
    std::cout << "Error, division by zero has occured." << std::endl;
  }
  return ILLEGAL_NUMBER;
}

/*
 * /= operator
 * set this = this / BigNum b
 */
void BigNum::operator/=(BigNum b)
{
  this->operator=(this->operator/(b));
}


/*
 * % operator
 * Perform division and return the remainder, using the same algorithm
 * that is used for division of BigNums
 * Throw an exception to stop infininite loops with division by zero
 */
BigNum BigNum::operator%(BigNum b) const
{
  try
  {
    bool bSign = b.getSign();

    if (b == ZERO) throw ILLEGAL_NUMBER;

    if (b == ONE) return ZERO;
    
    BigNum a(number);
    a.setSign(true);
    b.setSign(true);

    if (a < b) return a;

    while (a >= ZERO) 
    {
      a -= b;
    }
    
    BigNum result = a + b;
    result.setSign((positive == bSign || result == ZERO)? true : false); 
    return result;
  }
  catch (int i)
  {
    std::cout << "Error, division by zero has occured." << std::endl;
  }
  return ILLEGAL_NUMBER;
}

/*
 * %= operator
 * set this = this % BigNum b
 */
void BigNum::operator%=(BigNum b)
{
  this->operator=(this->operator%(b));
}
/*****Operators*****/


/*****IO Streams*****/
std::ostream& operator<<(std::ostream& os,BigNum& a)
{
  os << a.toString();
  return os;
}

std::istream& operator>>(std::istream& is, BigNum& a)
{
  is >> a.number;
  a.setNumber(a.number);
  return is;
}
/*****IO Streams*****/