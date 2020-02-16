#include<bits/stdc++.h>
using namespace std;

int totalWays(int cr, int cc, int dr, int dc){
    if(cr>dr || cc>dc)
        return 0;
    if(cr==dr && cc==dc)
        return 1;
    int ways = totalWays(cr, cc+1, dr, dc) + totalWays(cr+1, cc, dr, dc);
    return ways;
}
int totalWaysWrapper(int m, int n){
    return totalWays(0, 0, m-1, n-1);
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << totalWaysWrapper(m, n);
    return 0;
}