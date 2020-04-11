//
//  BigInt.h
//  BigInt
//
//  Created by AIMI ROSS on 11/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <vector>

using namespace std;

class BigInt{
    vector<char> storage;
public:
    BigInt();
    ~BigInt();
    BigInt(int);
    BigInt(string);
   // BigInt(const BigInt &);
    BigInt operator=(BigInt&);
    BigInt operator+(BigInt&);
    BigInt operator-(BigInt&);
    BigInt operator++(int);
    friend bool operator <= (const BigInt &a,const int &i);
    friend ostream & operator << (ostream &a, const BigInt &b);
    void print();
    double toDouble();
    
};

#endif /* BIGINT_H */
