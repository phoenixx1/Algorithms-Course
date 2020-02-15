#include<bits/stdc++.h>
using namespace std;
int cal(char operation, int x, int y)
{
	if(operation == '+') 
        return x +y;
	else if(operation == '-') 
        return x - y;
	else if(operation == '*') 
        return x * y;
	else if(operation == '/') 
        return x / y;
	else 
        cout<<"Unexpected Error \n";
	
    return -1; 
}
int expEval(string exp){
    char s;
    int ans;
    stack<int> S;
    for(int i=0; i<exp.length(); i++){
        s = exp.at(i);
        if(s>='0' && s<='9'){
            S.push(s- '0');
        }else if(s == '+' || s == '-' || s == '*' || s == '/'){
            int x = S.top();
            S.pop();
            int y = S.top();
            S.pop();
            ans = cal(s, x, y);
            S.push(ans);
        }
    }
    return ans;
}

int main(){
    string exp;
    cin >> exp;
    int ans = expEval(exp);
    cout << "Answer is " << ans;
    return 0;
}