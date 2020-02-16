#include<bits/stdc++.h>
using namespace std;
#define MAXROW 20

unsigned int computeTimeWrapper(int ir, int ic, int tr, int tc);
void computeInfectTime(int currRow, int currCol, int tr, int tc, unsigned int infectTime[][20], unsigned int currTime);


int main(){
    int ir, ic, tr, tc;
    cin >> tr >> tc;
    cin >> ir >> ic;
    cout << computeTimeWrapper(ir, ic, tr, tc);
    return 0;
}

unsigned int computeTimeWrapper(int ir, int ic, int tr, int tc){
    unsigned int infectTime[MAXROW][MAXROW];
    for(int i=0; i<tr; i++){
        for(int j=0; j<tc; j++){
            infectTime[i][j] = -1;
        }
    }
    computeInfectTime(ir, ic, tr, tc, infectTime, 1);
    int max = infectTime[0][0];
    for(int i=0; i<tr; i++){
        for(int j=0; j<tc; j++){
            if(max < infectTime[i][j])
                max = infectTime[i][j];
        }
    }
    return max;
}
void computeInfectTime(int currRow, int currCol, int tr, int tc, unsigned int infectTime[][MAXROW], unsigned int currTime){
    if(currRow>=tr || currRow<0 || currCol>=tc || currCol<0)
        return;
    if(currTime>=infectTime[currRow][currCol])
        return;
    infectTime[currRow][currCol] = currTime;
    computeInfectTime(currRow, currCol+1, tr, tc, infectTime, currTime+1);
    computeInfectTime(currRow+1, currCol, tr, tc, infectTime, currTime+1);
    computeInfectTime(currRow, currCol-1, tr, tc, infectTime, currTime+1);
    computeInfectTime(currRow-1, currCol, tr, tc, infectTime, currTime+1);
    return;
}
