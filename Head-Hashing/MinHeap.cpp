//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void min_heapify(int a[], int i, int n){
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while(j <= n){
        if(j < n && a[j + 1] < a[j]){
            j += 1;
        }
        if(temp < a[j]){
            break;
        }else if(temp >= a[j]){
            a[j / 2] = a[j];
            j = 2 * j; 
        }
    }
    a[j / 2] = temp;
    return;
}

void build_minheap(int a[], int n){
    for(int i=(n/2); i>=1; i--){
        min_heapify(a, i, n);
    }
}

int main()
{   
    int n;
    cout << "enter no of elements of array";
    cin >> n;
    int a[n+1];
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << "enter element" << i << endl;
        cin >> a[i];
    }
    build_minheap(a, n);
    cout << "Min Heap" << endl;
    for(int i=1; i<=n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
        