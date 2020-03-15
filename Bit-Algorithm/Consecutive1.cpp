//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int ones(int x){ //faster cool 
    int count = 0;
    while(x != 0){
        x = (x & (x << 1));
        count++;
    }
    return count++;
}
int main(){
    int x;
    cin >> x;
    cout << ones(x);
    cout << endl << 1;
    return 0;    
}
//alternative
/*
int main(){
    
    int x, x1 = 0, count = 0;
    cin >> x;
    vector<int> a;
    while(x>0){
        x1 = (x & 1);
        if(x1 == 0){
            a.push_back(count);
            count = 0;
        }else{
            count += 1;
        }
        x = x>>1;
    }
    a.push_back(count);
    cout << *max_element(a.begin(), a.end());
    
}
*/