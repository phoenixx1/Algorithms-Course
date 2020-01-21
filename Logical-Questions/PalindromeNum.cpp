//author @Nishant 

#include<bits/stdc++.h>
using namespace std;

int countPalindrome(int n){
    int x = pow(10, (n-1)/2); 
    return (9 * x); 
}

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += countPalindrome(i);
    }
    cout << sum;
    return 0;
}