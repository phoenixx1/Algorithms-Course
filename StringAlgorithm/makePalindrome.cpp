// author @Nishant

#include <bits/stdc++.h> 
using namespace std; 
  
bool checkPalindrome(string str, int st){ 
    int end = str.size() - 1;
    while(end>st){
        if(str.at(st++) != str.at(end--)){
            return false;
        }
    }
    return true;
} 
   
int findMinInsert(string str){ 
    for(int i=0; i<str.size(); i++){
        if(checkPalindrome(str, i)){
           return i;
        }else{
            continue;
        }
    }        
} 
  
int main() 
{ 
    string inputString;
    getline(cin, inputString);
    cout <<  findMinInsert(inputString); 
    return 0; 
} 