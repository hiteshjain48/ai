#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

vector<vector<int>> adj;

void addEdge(int x, int y) {
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start) {
    vector<bool> visited (adj.size(), false);
    vector<int> q;
    q.push_back(start);
    visited[start] = true;

    int curr;
    while(!q.empty()) {
        curr = q[0];
        cout<<curr<<" ";
        visited[curr] = true;
        q.erase(q.begin());
        #pragma omp parallel for
        for(int i = 0; i<adj[curr].size(); i++){
            if(adj[curr][i]==1 && visited[i]==false) {
                #pragma omp critical
                {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
}


void dfs(int start, vector<bool> visited) {
    cout<<start<<" ";
    visited[start] = true;

    for(int i = 0; i<adj[start].size(); i++) {
        if(adj[start][i]==1 && (!visited[i])) {
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



int main() {
    int v = 6;
    adj = vector<vector<int>>(v, vector<int>(v,0));
    vector<bool> visited(v, false);
    
    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(0,4);
    addEdge(0,5);

    cout<<"===================BFS==================="<<endl;
    bfs(0);
    cout<<endl;
    cout<<"===================DFS===================="<<endl;
    visited = vector<bool>(v,false);
    dfs(0,visited);
}
