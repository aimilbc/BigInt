//
//  BigInt.cpp
//  BigInt
//
//  Created by AIMI ROSS on 11/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include "BigInt.h"

BigInt::BigInt(){
    storage.push_back(0);
}

BigInt::~BigInt(){
    storage.clear();
}

BigInt::BigInt(string a){
    for (int i = 0; i<a.size(); i++){
        storage.push_back(a[i]-48);
    }
//    vector<char> ::reverse_iterator it;
//    it = storage.rbegin();
//    int count = 0;
//    double number = 0;
//    double &num2 = number;
//
//    while (it != storage.rend()){
//        double num = pow(10, count);
//        //cout << "*it is " << *it << endl;
//        num2 += (((double)*it)) * num;
//        //cout << "num2 is " << scientific << num2 << endl;
//        it++;
//        count++;
//    }
//    cout << "number is... " << number << " now....!!!!" << endl;
}

BigInt::BigInt(int n){  // pass by value, so n = 73265
    string a = to_string(n);
 
    for (int i = 0; i<a.size(); i++){
        storage.push_back(a[i]-48);
    }
//        vector<char> ::reverse_iterator it;
//        it = storage.rbegin();
//        int count = 0;
//        double number = 0;
//        double &num2 = number;
//        while (it != storage.rend()){
//            double num = pow(10, count);
//            //cout << "*it is " << *it << endl;
//            num2 += (((double)*it)) * num;
//            //cout << "num2 is " << scientific << num2 << endl;
//            it++;
//            count++;
//        }
//        cout << "number is... " << number << " now....!!!!" << endl;
}

void BigInt::print(){
    vector<char> ::iterator it;
    it = storage.begin();
    while (it != storage.end()){
        cout << *it + 0;
        // change char iterator format to int
        // example: char of decimal 1 won't display anything, and adding int to change the format to int
        it++;
    }
}

double BigInt::toDouble(){
    vector<char> ::reverse_iterator it;
    it = storage.rbegin();
    int count = 0;
    double number = 0;
    double &num2 = number;
    
    while (it != storage.rend()){
        double num = pow(10, count);
        num2 += (((double)*it)) * num;
        it++;
        count++;
    }
    return number;
}

BigInt BigInt::operator+(BigInt &a){
    a.print();
    cout << "\nabove is a and below is this " << endl;
    this->print();
    cout << endl;
    BigInt answer;
    double aInt = a.toDouble();
    string aSt = to_string(aInt);
    cout << "aSt is " << aSt << endl;
    double thisInt = this->toDouble();
    string thisSt = to_string(thisInt);
    cout << "thisSt is " << thisSt << endl;
    double ansInt = aInt + thisInt;
    cout << "ansInt is  " << ansInt << endl;
    string st = to_string(ansInt);
    cout << "st is " << st << endl;
    for (int i = 0; i<st.size(); i++){
        answer.storage.push_back(st[i]-48);
    }
    return answer;
}

ostream & operator << (ostream & out, const BigInt & b){
    BigInt num(b);
    double numbers = num.toDouble();
    out << numbers;
    return out;
}

