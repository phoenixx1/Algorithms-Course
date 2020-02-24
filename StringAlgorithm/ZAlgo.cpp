//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void zAlgo(string txt, string pat){
    string mergerd = pat + '$' + txt;
    int n = mergerd.size();
    //cout << mergerd;
    int Z[n];
    int R = 0, L = 0;
    for(int i=1; i<n; i++){
        if (i > R){
            L = R = i;
            while (R < n && mergerd.at(R-L) == mergerd.at(R)){
                R++;
            }
            Z[i] = R-L; 
            R--;
        }else{
            int k = i-L;
            if(Z[k] < R-i+1){
                Z[i] = Z[k];
            }else{
                L = i;
                while (R < n && mergerd.at(R-L) == mergerd.at(R)){
                    R++;
                }
                Z[i] = R-L; 
                R--;
            }
        }
    }
    for (int i = 0; i < n; ++i) 
    { 
        if (Z[i] == pat.size()) 
            cout << "Found pattern at index " << i - pat.size() -1 << endl; 
    } 
}

int main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    zAlgo(txt, pat);
}