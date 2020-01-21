#include<bits/stdc++.h>
using namespace std;

void printPrime(int n);
bool isPrime(int n);
unsigned int combination(unsigned int a, unsigned int b);

int main(){
    int n;
    cin >> n;
    printPrime(n);
    return 0;
}

bool isPrime(int n){
    if (n <= 1) 
        return false; 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 

unsigned int combination(unsigned int a, unsigned int b){
    unsigned int x = 10;
    while(b >= x)
        x *= 10;
    return a * x + b;
}

void printPrime(int n){ 
    vector<int> primes;
    for (int i = 2; i <= n; i++){ 
        if (isPrime(i)) 
            primes.push_back(i); 
    }
    int totalN = primes.size();
    set<int> combo;
    for(int i=0; i<totalN; i++){
        int x = primes.at(i);
        for(int j=i+1; j<totalN; j++){
            int y = primes.at(j);
            int xy = combination(x, y);
            int yx = combination(y, x);
            if(isPrime(xy)){
                combo.insert(xy);
            }
            if(isPrime(yx)){
                combo.insert(yx);
            }
        }
    }
    cout << combo.size();
} 