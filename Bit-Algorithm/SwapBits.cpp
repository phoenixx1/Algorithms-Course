//author @Nishant

#include<bits/stdc++.h>
#include<bitset>
using namespace std;

int main(){
    int n, p, q;
    cin >> n;
    cin >> p >> q;
    int temp = n;
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q)){
		n ^= (1 << p);
		n ^= (1 << q);
	}
    cout << n << endl;
    cout << bitset<8>(temp);
    return 0;
}