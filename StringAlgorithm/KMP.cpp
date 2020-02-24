//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void PrefixFunc(char pat[], int M, int lps[]){  
    int len = 0; 
    lps[0] = 0;
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else{ 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}

void KMPSearch(char txt[], char pat[]){
    int N = strlen(txt);
    int M = strlen(pat);
    int lps[M];
    PrefixFunc(pat, M, lps);
    int i = 0; 
    int j = 0; 
    while (i < N) { 
        if(pat[j] == txt[i]){ 
            j++; 
            i++; 
        } 
        if(j == M){ 
            cout << "Found pattern at index " <<  i - j << endl; 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
}

int main(){
    char txtS[100], patS[100];
    cin.getline(txtS, 100);
    cin.getline(patS, 100);
    // string txt, pat;
    // for(int i=0; i<strlen(txtS); i++){
    //     txt += txtS[i];
    // }
    // for(int i=0; i<strlen(patS); i++){
    //     pat += patS[i];
    // }
    KMPSearch(txtS, patS);
}