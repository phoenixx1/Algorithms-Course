#include<bits/stdc++.h>
using namespace std;

stack<int> s1, s2;

void insert(int x){
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(x); 
  
    while (!(s2.empty())) { 
        s1.push(s2.top()); 
        s2.pop(); 
    } 
}

void print(int n){
    if(s1.empty()){
        return;
    }
    for(int i=0; i<n; i++){
        cout << s1.top() << " ";
        s1.pop();
    }
}

int main(){
    int n;
    int elements;
    cin >> n;
    if(n<=0){
        cout << "Queue is empty";
        return 0;
        
    }else{
        for(int i=0; i<n; i++){
            cin >> elements;
            insert(elements);
        }
        cout << "Enter the size of stack:" << endl;
        cout << "Enter the stack values:" << endl;
        cout << "Queue elements are:" << endl;
        print(n);
    }
    return 0;
}