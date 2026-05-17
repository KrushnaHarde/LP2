#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, bool> visited;


unordered_map<int, vector<int>> graphs;
unordered_map<int, bool> vis;

void DFS(int node){
    vis[node] = true;
    cout<<node<<" ";
    for(int n : graphs[node]){
        if(!vis[n]) DFS(n);
    }
}

queue<int> q;
// q.push(src);

void BFS(){
    if(q.empty())   return;

    int cur = q.front(); q.pop();

    cout<<cur<<" ";

    for(int n : graphs[cur]){
        if(!vis[n]){
            vis[n] = true;
            q.push(n);
        }
    }
    BFS();
}

// DFS
void dfs(int node){

    visited[node] = true;

    cout << node << " ";

    for(int adj : graph[node]){

        if(!visited[adj]){

            dfs(adj);
        }
    }
}

// BFS
void bfs(int start){

    unordered_map<int, bool> visit;

    queue<int> q;

    q.push(start);

    visit[start] = true;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int adj : graph[node]){

            if(!visit[adj]){

                visit[adj] = true;

                q.push(adj);
            }
        }
    }
}

int main(){

    /*
    Sample Input:
    4 3
    10 20
    10 30
    20 40
    10
    */

    int e, n;

    cout << "Enter number of nodes and edges: ";

    cin >> n >> e;

    cout << "Enter edges:\n";

    for(int i=0; i<e; i++){

        int u,v;

        cin >> u >> v;

        graph[u].push_back(v);

        graph[v].push_back(u);
    }

    int start;

    cout << "Enter starting node: ";

    cin >> start;

    cout << "\nDFS Traversal:\n";

    dfs(start);

    cout << "\n\nBFS Traversal:\n";

    bfs(start);

    return 0;
}