//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices, edges, start, end;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << endl << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<int> > adMat(vertices);
    for(int i=0; i<edges; i++){
        cout << endl << "Enter the Start node and End node of edge " << i+1;
        cin >> start >> end;
        adMat[start].push_back(end);
        adMat[end].push_back(start);
    }
    int j = 0;
    cout << endl << "Adjacency List:";
    for(int i=0; i<vertices; i++){
        j=0;
        cout << endl;
        cout << i << "--->";
        while(j != adMat[i].size()){
            cout << adMat[i].at(j) << " ";
            j++;
        }
    }
}