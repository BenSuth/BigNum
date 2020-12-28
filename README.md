# BigNum
A Big integer implementation in C++, similar to Java's Math.BigInteger

## Contents
* [Usage](#usage)
* [Instances](#instances)
* [Operators](#operators)
* [Functions](#functions)

## Usage
* Compiles with C++11/14/17, no additional dependencies besides the standard library
* Download BigNum.cpp and BigNum.h into your project directory
* To use BigNum include `#include "BigNum.h"` in your code.

## Instances
* Creating a new BigNum object 
```cpp
  BigNum a("-500");
  BigNum b(-500); 
```
BigNum objects can be initialized with a string representation of a number or an integer (up to long long)

## Operators
* Assignments `=, +=, -=, *=, /=, %=` <br/>
  You can only set an instance of BigNum equal to another instance of BigNum
  ```c++
  BigNum a("-500");
  BigNum b = a;
  b += a; // b = b + a
  a /= b; // a = a / b
  ```
  
* Relational `>, >=, <, <=, ==, !=` <br/>
  Comparisons are done between two BigNum objects
  ```c++
  BigNum a("-500");
  BigNum b(500);
  
  if (b == a) ...
  while (b > a)...
  do { ... } while (b != a)
  for (;b <=a;) ...
  ```
  
* Binary Arthimetic `+, -, *, /, %` <br/>
  Operations are performed between two BigNum objects
  ```c++
  BigNum a("-500");
  BigNum b(500);
  BigNum c = ("0");
  
  c = a + b;
  c = a - b;
  c = a * b;
  c = a / b;
  c = a % b;
  ```
  
* Increments and Decrements `++, --` <br/>
  Operations are performed between two BigNum objects
  ```c++
  BigNum a("500");
  ++a; // a = 501
  a++; // a = 502
  
  --a; // a = 501
  a--; // a = 500
  ```  
  
* I/O Stream `>>, <<` <br/>
  ```c++
  BigNum a("500");
  
  std::cin >> a;
  std::cout << a;
  ```    

## Functions
1. `std::string toString()` <br/>
  Returns a signed string representation of a BigNum
    ```c++
    BigNum a("-500");
    std::string number = a.toString(); // number = "-500"
    ```
2. `std::string abs()` <br/>
  Returns an unsigned string representation of a BigNum
    ```c++
    BigNum a("-500");
    std::string number = a.abs(); // number = "500"
    ```
3. `long long length()` <br/>
  Returns the number of digits in a BigNum
    ```c++
    BigNum a("500");
    long long digits = a.length(); // digits = 3
    ```
4. `void setNumber(long long n)` <br/>
  Sets a BigNum equal to an integer (up to long long)
    ```c++
    BigNum a("-500");
    a.setNumber(1000);
    ```
5. `bool getSign()` <br/>
  Returns true if the BigNum is positive, false otherwise
    ```c++
    BigNum a("-500");
    a.getSign() // false
    ```
6. `void setSign(bool)` <br/>
  To chance a number to positive, pass in true, pass in false for negative
    ```c++
    BigNum a("500");
    a.setSign(false);
    a.getNumber() // "-500"
    ```   
7. `BigNum toBase(int)` <br/>
  Returns a BigNum converted to a given base, exceptions thrown if base is not 
  within 1 to 64 inclusive.
    ```c++
    BigNum a("5");
    BigNum b = a.toBase(2) // b.toNumber() == "101"
    ```   
8. `static void swap(BigNum *x,  BigNum *y)` <br/>
  Swaps the sign and number of two BigNum objects
    ```c++
    BigNum a("5");
    BigNum b("-8");
    
    BigNum::swap(&a, &b); // a.toNumber() == "-8", b.toNumber() == "5"
    ```   
    
9. `static BigNum pow(BigNum a, BigNum b);` <br/>
  Computes BigNum a to the power of BigNum b
    ```c++
    BigNum a("5");
    BigNum b("2");
    
    BigNum c = BigNum::pow(a,b); // c == "25"
    ```    
    
    
    
  
