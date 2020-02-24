//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void naiveSearch(char txt[], char pat[]){
    int txtLen = strlen(txt);
    int patLen = strlen(pat);
    for(int i=0; i<=txtLen - patLen; i++){
        int j = 0;
        for(j=0; j<patLen; j++){
            if(txt[i+j] != pat[j]){
                break;
            }
        }
        if(j==patLen){
            cout << "Pattern found at index " << i << endl; 
        }
    }
}

int main(){
    char txtS[100], patS[100];
    cin.getline(txtS, 100);
    cin.getline(patS, 100);
    string txt, pat;
    // for(int i=0; i<strlen(txtS); i++){
    //     txt += txtS[i];
    // }
    // for(int i=0; i<strlen(patS); i++){
    //     pat += patS[i];
    // }
    naiveSearch(txtS, patS);
}