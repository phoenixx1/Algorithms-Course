#include<bits/stdc++.h>
using namespace std;

void permute(char str[], int n);

int main(){
    char str[20];
    cin >> str;
    int n = strlen(str);
    permute(str, n);
    return 0;
}

void permute(char str[], int n){
    int used[n] = {0};
    unsigned int fact = 1;
    for(int i = 1; i <=n; ++i)
    {
        fact *= i;
    }
    string combinations[fact];
    for(int i=0; i<n; i++){
        
    }
}