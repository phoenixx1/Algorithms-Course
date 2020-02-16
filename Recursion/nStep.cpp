#include<bits/stdc++.h>
using namespace std;

long long int steps(long long int n, int currStep, int stepVisited[]){
    if(currStep>n)
        return 0;
    if(currStep == n)
        return 1;
    if(stepVisited[currStep] != -1){
        return stepVisited[currStep];
    }
    long long int totalWays = steps(n, currStep+1, stepVisited) + steps(n, currStep+2, stepVisited);
    stepVisited[currStep] = totalWays;
    return totalWays;
}

int visited(long long int n){
    int stepVisited[n+1];
    for(int i=0; i<=n; i++){
        stepVisited[i] = -1;
    }
    return steps(n, 0, stepVisited);
}

int main(){
    long long int step;
    cin >> step;
    cout << visited(step);
    return 0;
}
