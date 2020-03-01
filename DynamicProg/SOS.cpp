#include<bits/stdc++.h>
using namespace std;

int n;

void sumOfSubset(int cs, int level, int total, int w[], int sum){
    int x[level];
    if(cs + w[level] == sum){
        
    for (int i = 1; i <= level; i++) {
        cout << "Yes";
        return;
    }
    }else if(cs + w[level] + w[level+1] <= sum){
        sumOfSubset(cs + w[level], level + 1, total - w[level], w, sum);
    }
    
    if(cs + total - w[level] >= sum && cs + w[level+1] <= sum){
        x[level] = 0;
        sumOfSubset(cs, level+1, total - w[level], w, sum);
    }
}

int main(){
    cin >> n;
    int w[n+1];
    int total = 0, sum;

    for(int i = 1; i<n+1; i++){
        cin >> w[i];
        total += w[i];
    }
    cin >> sum;

    for (int i = 1; i<=n; i++){
        for (int j = 1 ; j<=n-1; j++){
            if(w[j] > w[j+1]) {
                int temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    if(total<sum)
        return 0;
    sumOfSubset(0, 1, total, w, sum);
    return 0;
}