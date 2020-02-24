//author @Nishant

#include <bits/stdc++.h> 
using namespace std; 

void longestSub(string str){

    vector<char> ans;
    vector<int> len;
    ans.push_back('a');
    int count = 0;
    ans.push_back(str.at(0));
    for(int i=0; i<str.size(); i++){
        if(find(ans.begin(), ans.end(), str.at(i)) == ans.end()){
            ans.push_back(str.at(i));
            count++;
        }else{
            len.push_back(count);
            count = 0;
            ans.clear();
            i = i - 1; 
        }
    }    
    len.push_back(count);
    cout << *max_element(len.begin(), len.end());

}

int main(){
    string str;
    getline(cin, str);
    if(str.size() == 0){
        return 0;
    }
    longestSub(str);
    return 0;
}