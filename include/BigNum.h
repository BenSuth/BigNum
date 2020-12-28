#ifndef BIGNUM_H
#define BIGNUM_H
#include <string>
#include <iostream>

#define ZERO BigNum("0")
#define ONE BigNum("1")
#define ILLEGAL_NUMBER -1;

class BigNum
{
  private:
    std::string number; // stores the number (absolute value)
    bool positive; // stores the sign of the number (true = positive, false = negative)
  public:
    BigNum(std::string n);
    BigNum(long long n);
    std::string toString();
    std::string abs();
    long long length();
    void setNumber(std::string n);
    void setNumber(long long n);
    bool getSign();
    bool setSign(bool sign);
    BigNum toBase(int base);
    static void swap(BigNum *x,  BigNum *y); 
    static BigNum pow(BigNum a, BigNum b);
    void operator=(BigNum n);
    bool operator==(BigNum n) const;
    bool operator!=(BigNum n) const;
    bool operator>(BigNum n) const;
    bool operator>=(BigNum n) const;
    bool operator<(BigNum n) const;
    bool operator<=(BigNum n) const;
    BigNum operator+(BigNum b) const;
    void operator+=(BigNum b);
    BigNum operator-(BigNum b) const; 
    void operator-=(BigNum b);
    BigNum& operator++();
    BigNum operator++(int n);    
    BigNum& operator--();       
    BigNum operator--(int n);
    BigNum operator*(BigNum b);
    void operator*=(BigNum b);
    std::string multiply(std::string x, std::string y);
    BigNum operator/(BigNum b) const;
    void operator/=(BigNum b);
    BigNum operator%(BigNum b) const;
    void operator%=(BigNum b);
    friend std::ostream& operator<<(std::ostream& os,BigNum& a);
    friend std::istream& operator>>(std::istream& is, BigNum& a);
};

#endif