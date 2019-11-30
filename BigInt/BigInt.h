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
    //vector<char>::iterator it;
public:
    BigInt();
    ~BigInt();
    BigInt(int);
    BigInt(string);
    void constructor();
    BigInt operator+(BigInt&);
    BigInt operator-(BigInt&);
    friend ostream & operator << (ostream &a, const BigInt &b);
    void print();
    double toDouble();
    
};

#endif /* BIGINT_H */
