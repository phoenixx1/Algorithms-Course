//author @Nishant

#include<bits/stdc++.h>
using namespace std;

bool check(int x, int pow[], int k, int i){
    for(int j=k; j<i; j++){
        if(pow[j] == x){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int power[n];
    for(int i=0; i<n; i++){
        cin >> power[i];
    }
    int sum = 0;
    vector<int> ans;
    int k = 0;
    for(int i=0; i<n; i++){
        if(check(power[i], power, k, i)){
            sum += power[i];
        }else{
            ans.push_back(sum);
            k = i;
            i = i-1;
            sum = 0;
        }
    }
    ans.push_back(sum);
    cout << *max_element(ans.begin(), ans.end());
}