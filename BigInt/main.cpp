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

int goldRabbits(int);
BigInt goldRabbits(BigInt);
void pause(){
    cout << "Press Enter to continue...";
    getchar();
}

int main() {
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    cout << "Checking << operation for B1..." << endl<< B1 << endl;
    cout << "Checking << operation for B2..." << endl<< B2 << endl;
    BigInt B3(78394);
    cout << "Checking << operation for B3..." << endl << B3 << endl;
    cout << "\nchecking print() function..." << endl;
    B1.print();
    cout << endl;
    B3.print();
    cout << "\nChecking + operation from here " << endl << endl;
    cout << B1 + B3 << endl;
    BigInt B4(B1 + B3);
    B4.print();
    cout << endl;
    cout << B4 << endl;
    
    cout << endl;
    map<char, int> LetCount;
    map<char, int>::iterator mit;
    string sentence = "how now brown gerbil"; // we can treat as string[], or vector of charactor
    for(int i = 0; i < sentence.size(); i++){  // len(sentence) also works
        char letter = sentence[i];
        mit = LetCount.find(letter);
        if(mit == LetCount.end())
            LetCount[letter] = 1;
        else
            LetCount[letter]++;
    }
    
    mit = LetCount.begin();
    while(mit == LetCount.end()){ // this will sort the map with lower value of char(in this case, ' ','b','e' and so on)
        cout << mit->first;
        cout << ':';
        cout << mit->second;
        cout << endl;
        mit++;
    }
    
//    vector<int>::reverse_iterator rit;
//    vector<int>::iterator it;  // a smart pointr.
//    vector<int> v; // vector is like an array
//
//    for(int i =0; i<10; i++){
//        v.push_back(i);  // just as v.add in java. So v contains 0 - 9
//    }
//    cout << v.size();
//    for(int i =0; i<v.size(); i++){
//        cout << v[i];
//    }
//    cout << endl;
//
//    it = v.begin();  // now the iterator is pointing v[0]
//    while (it != v.end()){
//        cout << *it;  // cout << *it++;
//        it++;
//    }
//    cout << endl;
//    rit = v.rbegin(); // rbegin means revers begin, going to the end
//    while(rit != v.rend()){
//        cout << *rit++;
//    }
//    cout << endl;
//
//    int i = 10;
//    int* ptr = &i;;
//    cout << i << endl;
//    cout << ptr << endl;
//    cout << &ptr << endl;
//    cout << *ptr << endl;
//    char a = 65;
//    cout << a << endl;
    
    cout << endl;
    //pause();
    return 0;
}
