//author @Nishant

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> binary, int n){
    int i, j;
    for(i=0, j=n-1; i<n; i++, j--){
        if(binary[i]==binary[j]){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int main(){
    /*
    int x;
    cin >> x;
    vector<int> binary;
    while(x>=1){
        binary.push_back(x%2);
        x /= 2;
    }
    if(check(binary, binary.size()))
        cout << "yes";
    else
        cout << "no";
    */
    int n; 
    cin >> n;
    int n1 = 0;
    int temp = n;
    while(n>0){
        n1 = n1 << 1;
        n1 = n1 | (n & 1);
        n = n >> 1;
    }
    if(temp==n1)
        cout << "yes";
    else
        cout << "no";
    return 0;    
}
