//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void removeKdigits(vector<int> num, int k);

int main(){
    string number;
    int k;
    cin >> number;
    cin >> k;
    if(number.length()<=0 || k<=0){
        return 0;
    }
    int t = 0;
    int len = number.length();
    vector<int> num;
    while (len > 0){
        int x = number.at(t++);
        num.push_back(x-48);
        len--;        
    }
    if(k>=num.size()){
        return 0;
    }
    removeKdigits(num, k);
    return 0;
}

void removeKdigits(vector<int> num, int k){
    for(int i=0; i<k; i++){
        int x = 0;
        while(x < num.size() - 1 && num.at(x) <= num.at(x + 1)){
            x++;
        }
        num.erase(num.begin()+x);
    }
    for(int i=0; i<num.size(); i++){
        cout << num.at(i);
    }
}
