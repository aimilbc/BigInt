//
//  BigInt.cpp
//  BigInt
//
//  Created by AIMI ROSS on 11/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <iomanip>
#include "BigInt.h"

BigInt::BigInt(){}

BigInt::~BigInt(){
    storage.clear();
}

BigInt::BigInt(string a){
    for (int i = 0; i<a.size(); i++){
        storage.push_back(a[i]-48);
    }
}

BigInt::BigInt(int n){  // pass by value, so n = 73265
    string a = to_string(n);
 
    for (int i = 0; i<a.size(); i++){
        storage.push_back(a[i]-48);
    }
}

//BigInt::BigInt(const BigInt &a) {
//    BigInt temp;
//    for (int i = 0; i < a.storage.size(); i++){
//        temp.storage.push_back(a.storage[i]);
//    }
//
//}

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

BigInt BigInt::operator=(BigInt &a)
{
    storage = a.storage;
    return (*this);
}

BigInt BigInt::operator++(int){
    
    cout << "this BigInt is "<< *this << endl;
    double dubBig = this->toDouble();
    dubBig += 1;
    BigInt temp(dubBig);
    cout << "now, the BigInt is "<< temp << endl;
    return temp;
}

BigInt BigInt::operator+(BigInt &a){
    vector<char> ::reverse_iterator it1;
    it1 = this->storage.rbegin();
    vector<char> ::reverse_iterator it2;
    it2 = a.storage.rbegin();
    
    BigInt largerNum;
    BigInt smallerNum;
    BigInt answer;
    BigInt tempo;
    
    int count1 = 0;
    int count2 = 0;
    int carry = 0;
    // checking which one has the larger digit
    while (it1 != this->storage.rend()){
        int &num = count1;
        it1++;
        num++;
    }
    while (it2 != a.storage.rend()){
        int &num = count2;
        it2++;
        num++;
    }
    // assign larger and smaller numbers
    if (count1 > count2){
        largerNum.storage = this->storage;
        smallerNum.storage = a.storage;
    }else if (count2 > count1){
        largerNum.storage = a.storage;
        smallerNum.storage = this->storage;
    }else
        if(this->storage.begin() > a.storage.begin()){
            largerNum.storage = this->storage;
            smallerNum.storage = a.storage;
        }else{
            largerNum.storage = a.storage;
            smallerNum.storage = this->storage;
        }
    it1 = largerNum.storage.rbegin();
    it2 = smallerNum.storage.rbegin();
    
    
    for (int i = 0; i<largerNum.storage.size(); i++){
        int a, b, temp;
        int &c = carry;
        if(it2 != smallerNum.storage.rend())
            b = *it2;
        else
            b = 0;
        a = *it1;
        temp = a + b + c;
        c = temp/10;
        temp %= 10;
        tempo.storage.push_back(temp);
        it1++;
        if(it2 != smallerNum.storage.rend())
           it2++;
    }
    cout << "answer is ";
    answer.print();
    cout << endl;
    it1 = tempo.storage.rbegin();
    for (int i = 0; i < tempo.storage.size(); i++){
        answer.storage.push_back(*it1);
        it1++;
    }
//    cout << "answer is now ................. ";
//    answer.print();
//    cout << endl;
    return answer;
}

ostream & operator << (ostream & out, const BigInt & b){
    BigInt num(b);
    double numbers = num.toDouble();
    
    if(num.storage.size()>12){
        out << numbers;
    }else
        out << fixed << setprecision(0) << numbers;
    
    return out;
}

bool operator <= (const BigInt &a, const int &i){
    BigInt temp(a);
    double num = temp.toDouble();
    if (num < i){
        return true;
    }
    else
        return false;
}
