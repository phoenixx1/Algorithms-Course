//((a+b))
//(a-b*(c+d))

#include<bits/stdc++.h>
using namespace std;

bool redundant(string str){
    stack<char> s;
    if(str.length() == 0){
        return false;
    }
    /*for(int i=0; i<str.length(); i++){ // another method but not considering the other example
        if(str.at(i) == ')'){
            char currTop = s.top();
            s.pop();
            int n = 0;
            while(currTop != '('){
                n++;
                currTop = s.top();
                s.pop();
            }
            if(n<=1){
                return 1;
            }
        }else{
            s.push(str.at(i));
        }
    }
    return false;*/
    for(int i=0; i<str.length(); i++){
        if(str.at(i) == ')'){
            char t = s.top();
            s.pop();
            int flag = 1;
            while(t != '('){
                if(t =='+' || t =='-' || t =='*' || t =='/')
                    flag = 0;
                t = s.top();
                s.pop();
            }
            if(flag == 1){
                return 1;
            }
        }else{
            s.push(str.at(i));
        }
    }   
    return 0;
}

int main(){
    string str;
    cin >> str;
    if(redundant(str)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
