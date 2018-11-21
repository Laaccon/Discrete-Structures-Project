/* 
 * File:   main.cpp
 * Author: N
 *
 * Created on November 19, 2018, 9:33 PM
 */

//System Library
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Function Prototypes
string encrypt(string, string);
string decrypt(string, string);

//Start Execution
int main(int argc, char** argv) {
    //declare variables
    string msg, key, encrypted;
    
    //prompt for input
    cout << "Enter your message to be encrypted: ";
    getline(cin, msg);
    cout << "Enter you keyword: ";
    cin >> key;
    
    //encrypt message
    encrypted = encrypt(msg, key);
    
    cout << "Your encrypted message is: " << encrypted;
    return 0;
}
//******************** encrypt **********************
//* Purpose:  encrypt messages with key             *
//* Input: msg -> the message, key-> key            *
//* Output: string-> encrypted string               *
//***************************************************
string encrypt(string msg, string key){
    //declare variables
    string source = msg;
    string longkey(source.length(), ' ');
    int offset;
    // generate longkey
    for (int i = 0; i < source.length(); i ++){
        longkey[i] = key[i % key.length()];
    }
    //output key for debugging
    cout << "Extended key: " << longkey << endl;
    for (int i = 0; i < source.length(); i++){
        //check for space
        if(source[i] != ' '){
            offset = int(source[i]) + int(longkey[i]);
            if (offset > 126){
            offset = offset % 61 + 65;
            }
        source[i] = char(offset);
        }
    }
    cout << "Encrypted: " << source << endl;
    return source;
}

