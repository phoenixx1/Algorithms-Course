//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    
    int freq[26] = {0};
    for(int i=0; i<str.size(); i++){
        int pos = str.at(i) - 'a';
        freq[pos] += 1;
    }
    for(int i=0; i<26; i++){
        if(freq[i]!=0){
            cout << char(i+'a') << ":" << freq[i] << endl;
        }
    }
    return 0;
}
