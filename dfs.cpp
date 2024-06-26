#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

vector<vector<int>> adj;

void addEdge(int x, int y) {
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void dfs(int start, vector<bool>& visited) {
    cout<<start<<" ";
    visited[start] = true;

    for(int i = 0; i < adj[start].size(); i++) {
        if(adj[start][i] == 1 && (!visited[i])) {
            #pragma omp task shared(visited)
            {
                #pragma omp critical 
                {
                    dfs(i, visited);
                }
            }
        }
    }
}


void dfs1(int start, vector<bool> visited) {
    cout<<start<<" ";
    visited[start] = true;

    for(int i = 0; i<adj[start].size(); i++) {
        if(adj[start][i]==1 && visited[i]==false){
            #pragma omp task shared(visited)
            {
                #pragma omp critical
                {
                    dfs(i,visited);
                }
            }
        }
    }
}
int main() {
    int v = 6;
    int e = 4;

    adj = vector<vector<int>>(v,vector<int>(v,0));

    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(0,4);
    addEdge(0,5);

    vector<bool> visited(v,false);
    dfs(0,visited);

}