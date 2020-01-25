//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int source, destination, weight;
};

bool compare(edge e1, edge e2){
    return e1.weight<e2.weight;
}

int findParent(int edge, int *parent){
    if(parent[edge]==edge){
        return edge;
    }
    return findParent(parent[edge], parent);
}

void kruskals(edge *input, int N, int edges){
    sort(input, input+edges, compare);
    edge *out = new edge[N-1];
    int *parent = new int[N];
    for(int i=0; i<N; i++){
        parent[i] = i;
    }
    int count = 0;
    int k = 0;
    while(count != N-1){
        edge currEdge = input[k];
        int source = findParent(currEdge.source, parent);
        int dest = findParent(currEdge.destination, parent);
        
        if(source!=dest){
            out[count++] = currEdge;
            parent[source] = dest;
        }
        k++;
    }
    int minCost = 0;
    for(int i=0; i<N-1; i++){
        minCost += out[i].weight;
    }
    cout << "Minimum cost = " << minCost;
}

int main(){
    int N, wt, edges = 0;
    cin >> N;
    edge *temp = new edge[100];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> wt;
            if(wt!=0){
                temp[edges].source = i;
                temp[edges].destination = j;
                temp[edges].weight = wt;
                edges++;
            }
        }
    }
    kruskals(temp, N, edges);
}