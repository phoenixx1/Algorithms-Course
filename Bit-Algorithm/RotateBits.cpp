//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    cout << ((x<<n)|(x>>(16-n))) << endl;
    cout << ((x>>n)|(x<<(16-n)));
    return 0;
}