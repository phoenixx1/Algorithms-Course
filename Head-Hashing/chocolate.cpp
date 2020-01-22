//author @Nishant

//using vector
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    vector<int> choco;
    for(int i=0; i<n; i++){
        cin >> k;
        choco.push_back(k);
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int maxV = *max_element(choco.begin(), choco.end());
        int maxPos = distance(choco.begin(), max_element(choco.begin(), choco.end()));
        choco[maxPos] = sqrt(maxV);
    }
    cout << accumulate(choco.begin(), choco.end(), 0);
}

/*
//using array

#include<bits/stdc++.h>
using namespace std;

int elementPos(int a[], int maxV, int n){
    for(int i=0; i<n; i++){
        if(a[i] == maxV){
            return i;
        }
    }
}

int main(){
    int n, k;
    cin >> n;
    int choco[n];
    for(int i=0; i<n; i++){
        cin >> choco[i];
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int maxV = *max_element(choco, choco+n);
        int maxPos = elementPos(choco, maxV, n);
        choco[maxPos] = sqrt(maxV);
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += choco[i];
    }
    cout << sum;

}
*/