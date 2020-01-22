//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int testC, n;
    cin >> testC;
    for(int i=0; i<testC; i++){
        cin >> n;
        cin >> str;
        int k = 0;
        int cc = 0, cv = 0;
        vector<int> ans;
        ans.push_back(0);
        for(int i=0; i<str.size(); i++){
            for(int j=i; j<str.size(); j++){
                if(str.at(j) == 'c'){
                    cc++;
                }else{
                    cv++;
                }
                if(cv == cc){
                    ans.push_back(cv);
                }
            }
            cc = 0;
            cv = 0;
        } 
        
        cout << (*max_element(ans.begin(), ans.end()))*2 << endl;
        ans.clear();
    }
    
    
}