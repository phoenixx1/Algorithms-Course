#include<bits/stdc++.h>
using namespace std;

long long int survived(long long int n, long long int k){
    long long int sum = 0; 
    for (int i = 2; i <= n; i++) 
        sum = (sum + k) % i; 
  
    return sum + 1; 
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << survived(n,k);
    return 0;
}