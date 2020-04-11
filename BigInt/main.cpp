//
//  main.cpp
//  BigInt
//
//  Created by AIMI ROSS on 11/10/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <iostream>
#include "BigInt.h"
#include <map>
#include <vector>
using namespace std;

static map<int, BigInt> RabbitRecord;
static map<int, BigInt>::iterator mIT;

int goldRabbits(int);
BigInt goldRabbits(BigInt);

void pause(){
    cout << "Press Enter to continue...";
    getchar();
}

BigInt goldRabbits(BigInt big){
    mIT = RabbitRecord.begin();
    double dubBIG = big.toDouble();
    static int count = 0;
    count++;
    //cout << "\b\b\b\b\b\b\b\b" << count;
    cout << count;
    cout << "\ndubBIG is now " << dubBIG << endl;
    if (dubBIG == 0 || dubBIG == 1)
    {
        BigInt temp = 1;
        RabbitRecord[count] = temp;
        return RabbitRecord[count];
    }
    else
    {
        BigInt sum = RabbitRecord[count-1] + RabbitRecord[count-2];
        RabbitRecord[count] = sum;
        return RabbitRecord[count];}
    return NULL;
}


int main() {
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1: " << B1 << "\nB2: " << B2 << "\nMAX: " << MAX << endl;

    B1.print();
    cout << endl;
    B2.print();
    cout << endl;
    cout << "Before == operation, B2 is \n" << B2 << endl;
    cout << "Wait, B1 is " << B1 << endl;
    B2++;
    cout << "\nB2 is now " << B2;
    
//    pause();
//    cout << "\nB1: ";
//    B1.print();
//    cout << endl;
//    pause();
//    for (BigInt i = 0; i <= 3000; i++){
//        cout << "\ngoldRabbits(" << i << ") = " << goldRabbits(i);
//    }
//    pause();

    return 0;
}



