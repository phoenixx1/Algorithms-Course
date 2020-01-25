//author @Nishant

#include<bits/stdc++.h>
using namespace std;


int main(){
    int nodes, edges, start, end, weight;
    string type;
    
    cout << "Please enter the number of nodes in the graph ";
    cin >> nodes;
    cout << endl << "Please enter the number of edges in the graph ";
    cin >> edges;
    cout << endl << "Is the graph directed ";
    cin >> type;
    cout << endl << "Adjacency Matrix Representation:";
    int adMat[nodes][nodes];// = {0};
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            adMat[i][j] = 0;
        }
    }
    for(int i=0; i<nodes; i++){
        cout << endl;
        for(int j=0; j<nodes; j++){
            cout << adMat[i][j] << " ";
        }
    }
    for(int i=0; i<edges; i++){
        cout << endl << "Enter the start node, end node and weight of edge no " << i+1;
        cin >> start >> end >> weight;
        if(type == "yes"){
            adMat[start-1][end-1] = weight;
        }else{
            adMat[start-1][end-1] = weight;
            adMat[end-1][start-1] = weight;
        }
    }
    cout << endl << "Adjacency Matrix Representation:";
    for(int i=0; i<nodes; i++){
        cout << endl;
        for(int j=0; j<nodes; j++){
            cout << adMat[i][j] << " ";
        }
    }

}