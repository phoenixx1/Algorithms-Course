// To check if a strings can be chained to form a circle

//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> chain, vector<bool>& visited, int x);
bool chainFormed(vector<vector<int>> chain, vector<bool> visitedVertex, int x);
bool canBeChained(vector<string> a);

int main(){
    vector<string> a {"acd", "efg", "dbe", "gta"};
    if(canBeChained(a)){
        cout << "The given set of strings can be chained to form a circle" << endl;
    }else{
        cout << "The given set of strings can not be chained to form a circle" << endl;
    }
    return 0;
}

/*
Recursive DFS Approach
*/
void DFS(vector<vector<int>> chain, vector<bool>& visited, int x){
    visited[x] = true;
    for(int i = 0; i < chain[x].size(); i++){
        if(!visited[chain[x][i]]){
            DFS(chain, visited, chain[x][i]);
        }
    }
}

bool chainFormed(vector<vector<int>> chain, vector<bool> visitedVertex, int x){
    vector<bool> visited(26);
    
    DFS(chain, visited, x);

    for(int i = 0; i < 26; i++){
        if(visitedVertex[i] && !visited[i]){
            return false;
        }
    }
    return true;
}

bool canBeChained(vector<string> a){
    //creating a 2d vector to store the edges formed
    vector<vector<int>> chain(26);

    vector<int> inD(26), outD(26); 

    // To store if that character is in graph or not
    vector<bool> visitedVertex(26);

    int n = a.size(), first, last;

    for(int i = 0; i < n; i++){
        first = a[i][0] - 'a';
        last = a[i][a[i].size() - 1] - 'a';

        visitedVertex[first] = visitedVertex[last] = true;

        inD[last]++;
        outD[first]++;

        chain[first].push_back(last);
    }

    for(int i = 0; i < 26; i++){
        if(inD[i] != outD[i]){
            return false;
        }
    }

    return chainFormed(chain, visitedVertex, a[0][0] - 'a');
}