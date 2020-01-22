//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    int M, Q, N;
    cin >> M >> Q >> N;
    int values[10000] = {0};
    
    for(int i=0; i<N; i++){
        int t1;
        cin >> t1;
        values[t1] += 1;
        for(int j=1; j<=Q; j++){
            int t2 = t1 + (M * j);
            values[t2] += 1;
            t2 = t1 - (M * j);
            if(t2 > 0){
                values[t2] += 1;
            }
        }
    }
    cout << *max_element(values, values + 10000);
}