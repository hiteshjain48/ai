#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

vector<vector<int>> adj;
void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void bfs(int start)
{
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];
		cout << vis << " ";
		q.erase(q.begin());
        #pragma omp parallel for
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) 
            #pragma omp critical
            {
				q.push_back(i);
				visited[i] = true;
			}
		}
	}
}
void bfs1 (int start) {
    vector<bool> visited(adj.size(), false);
    vector<int> q;

    q.push_back(start);
    visited[start] = true;

    int curr;
    while(!q.empty()) {
        curr = q[0];
        cout<<curr<<' ';
        q.erase(q.begin());

        for(int i=0; i<adj[curr].size(); i++){
            if(adj[curr][i]==1 && visited[curr]==false){
                q.push_back(curr);
                visited[curr] = true;
            }
        }
    }
}
int main()
{
int v = 5;
adj= vector<vector<int>>(v,vector<int>(v,0));
addEdge(0,1);
addEdge(0,2);
addEdge(1,3);
bfs(0);
}
