#include <iostream>
#include "bigInt.hpp"

int main(){
    BigIntContainer num1;
    num1.bignum = "1234412";
    num1.digitnum = num1.bignum.length();

    BigIntContainer num2;
    num2.bignum = "56781";
    num2.digitnum = num2.bignum.length();

    addition(num1, num2);

    return 0;
}