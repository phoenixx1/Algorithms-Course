//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int *dist, bool *visit, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visit[i] && (minVertex == -1 || dist[i] < dist[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int n){
    int *dist = new int[n];
    bool *visit = new bool[n];
    int *pred = new int[n];
    for(int i=0; i<n; i++){
        dist[i] = 999;
        visit[i] = false;
        pred[i] = 0;
    }
    dist[0] = 0;
    int next;
    for(int i=0; i<n; i++){
        int minVertex = findMinVertex(dist, visit, n);
        visit[minVertex] = true;
        for(int j=0; j<n; j++){
            if(edges[minVertex][j] != 0 && !visit[j]){
                int distance = dist[minVertex] + edges[minVertex][j];
                if(distance < dist[j]){
                    dist[j] = distance;
                    next = i;
                }
            }
            if(!visit[j]){
                pred[j]=next;
            }
        }
    }
    int j;
    for(int i=1; i<n; i++){
        if(i != 0){
            cout << "\nDistance of node" << i << "=" << dist[i];
            cout << "\nPath=" << i;
            j = i;
            do{
                j=pred[j];
                cout << "<-" << j;
            }while(j != 0);
        }
    }
}

int main(){
    int N, wt;
    cin >> N;
    if(N>1){
        int **edges = new int*[N];
        for(int i=0; i<N; i++){
            edges[i] = new int[N];
            for(int j=0; j<N; j++){
                edges[i][j] = 0;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> wt;
                if(wt!=0){
                    edges[i][j] = wt;
                }else{
                    edges[i][j] = 0;
                }
            }
        }
        cin >> wt;
        dijkstra(edges, N);
    }
    
    return 0;
}