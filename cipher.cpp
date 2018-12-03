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
void menu();

//Start Execution
int main(int argc, char** argv) {
    menu();
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
    int offset, temp;
    // generate longkey by repeating letters in key
    for (int i = 0; i < source.length(); i ++){
        longkey[i] = key[i % key.length()];
    }
    //Loop through and convert each Character
    for (int i = 0; i < source.length(); i++){
        //check for alphabetical character
        // get offset number
        if(isalpha(longkey[i])){
          if(isupper(longkey[i])){
            temp = longkey[i] - 65 + 1;
          }
          else{
            temp = longkey[i] - 97 + 1;
          }
        }
        if(isalpha(source[i])){
          //check for uppercase
          if (isupper(source[i])){
              //make offset the  source
              offset = int(source[i]);
              //add key value as integer and subtract so 'A' starts at 1
              offset +=  temp;
              //if total is higher than 'Z' mod back to 'A' 
              if (offset > 90){
                offset = offset - 90 + 65; 
              }
          }
          else{
              //make offset the  source
              offset = int(source[i]);
              //add key value as integer and subtract so 'a' starts at 1
              offset +=  temp;
              //if total is higher than 'z' mod back to 'a' 
              if (offset > 122){
                offset = offset - 122 + 97; 
              }
          }
        source[i] = char(offset);
        }
    }
    return source;
}
//******************** decrypt **********************
//* Purpose:  decrypt messages with key             *
//* Input: msg ->encyrpted message, key-> key       *
//* Output: string-> decrypted string               *
//***************************************************
string decrypt(string msg, string key){
    //declare variables
    string source = msg;
    string longkey(source.length(), ' ');
    int offset, temp;

    // generate longkey
    for (int i = 0; i < source.length(); i ++){
        longkey[i] = key[i % key.length()];
    }
    //Loop through and convert each Character
    for (int i = 0; i < source.length(); i++){
              // get offset number
        if(isalpha(longkey[i])){
          if(isupper(longkey[i])){
            temp = longkey[i] - 65 + 1;
          }
          else{
            temp = longkey[i] - 97 + 1;
          }
        }

        //check for alphabetical character
        if(isalpha(source[i])){
          //check for uppercase
          if (isupper(source[i])){
            //make offset converted source
            offset = int(source[i]);
            //subtract the key and add back up to 'A'
            offset = offset - temp;
            //if lower than 'A' then start from 'Z' and subtract the difference
            if (offset < 65){
            offset = 90 - (65 - offset); 
            }
          }
          else{
            //make offset converted source
            offset = int(source[i]);
            //subtract the key and add back up to 'a'
            offset = offset - temp;
            //if lower than 'a' then start from 'z' and subtract the difference
            if (offset < 97){
            offset = 122 - (97 - offset); 
            }
          }
        source[i] = char(offset);
        }
    }
    return source;
}
//********************   menu  **********************
//* Purpose: User Selects what function to use      *
//***************************************************
void menu(){
    char choice;
    string msg, key, encrypted, decrypted;
    //user select operation
    do{
      cout << "Enter 'E' for Encrypt, 'D' for Decrypt or 'X' to exit:\n   ";
      cin >> choice;
    } while(choice != 'E' && choice != 'D' && choice != 'X');
    // clear cin
    cin.ignore (); 
    switch(choice){
      case 'E': {
      //prompt for input
      cout << "\nEnter your message to be encrypted: ";
      getline(cin, msg);
      cout << "\nEnter you keyword: ";
      cin >> key;

      //encrypt message
      encrypted = encrypt(msg, key);
    
      cout << "Your encrypted message is: " << encrypted << endl;
      menu();
      } break;
      case 'D': {

      //prompt for input
      cout << "\nEnter your message to be decrypted: ";
      getline(cin, msg);
      cout << "\nEnter your key to decrypt: ";  
      cin >> key;
      decrypted = decrypt(msg, key);

      cout << "Your decrypted message is: " << decrypted << endl;
      menu();
      }break;
      case 'X': {
        cout << "Quitting Program...";
        exit(0);
      }
      default : cout << "Bad Input. Try Again.";
    }
}
