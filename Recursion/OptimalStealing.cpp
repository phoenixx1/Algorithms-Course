#include <bits/stdc++.h>
using namespace std;

int max_stealing(int value[], int n, int i);
int max_value(int x, int y);
int main(){
    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout << max_stealing(value, n, 0);
    return 0;
}

int max_stealing(int value[], int n, int i){
    if (i >= n)
        return 0;
    return max_value(value[i] + max_stealing(value, n, i + 2), max_stealing(value, n, i + 1));
}

int max_value(int x, int y){
    if (x > y)
        return x;
    else
        return y;
}
    