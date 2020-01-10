//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> x;
    while(x!=0){
        cin >> n;
        cout << ((0xF0 & (n<<4)) | (0x0F & (n>>4)));
        x--;
    }
    
    return 0;
}