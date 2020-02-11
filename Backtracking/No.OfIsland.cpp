//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int totalBridges(int **mat, int n, int m);
void removeIsland(int **mat, int n, int m, int i, int j);
bool isSafe(int n, int m, int i, int j);

int main(){
    int m, n;
    cin >> n >> m;
    int **mat = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        mat[i] = (int *)malloc(m * sizeof(int));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    // for(int i=0; i<m; i++){
    //     cout << endl;
    //     for(int j=0; j<n; j++){
    //         cout << mat[i][j] << "\t";
    //     }
    // }
    cout << totalBridges(mat, n, m);
    return 0;
}

int totalBridges(int **mat, int n, int m){
    int count = 0;
    //cout << mat[0][0] << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1){
                count++;
                removeIsland(mat, n, m, i, j);
            }
        }
    }
    return count - 1;
}

void removeIsland(int **mat, int n, int m, int i, int j){
    if(isSafe(n, m, i, j) && mat[i][j]==1){
        mat[i][j] = 0;
        removeIsland(mat, n, m, i - 1, j - 1);
        removeIsland(mat, n, m, i - 1, j);
        removeIsland(mat, n, m, i - 1, j + 1);
        removeIsland(mat, n, m, i, j - 1);
        removeIsland(mat, n, m, i, j + 1);
        removeIsland(mat, n, m, i + 1, j - 1);
        removeIsland(mat, n, m, i + 1, j);
        removeIsland(mat, n, m, i + 1, j + 1);
    }
}

bool isSafe(int n, int m, int i, int j){
    if(i<0 || i>=n){
        return false;
    }
    if(j<0 || j>=m){
        return false;
    }
    return true;
}