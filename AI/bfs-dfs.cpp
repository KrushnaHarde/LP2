#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

// DFS
void dfs(int node)
{
    visited[node] = true;

    cout << node << " ";

    for(int adj : graph[node])
    {
        if(!visited[adj])
            dfs(adj);
    }
}


queue<int> q;

void bfs(){

    if(q.empty())
        return;

    int node = q.front();
    q.pop();

    cout << node << " ";

    for(int adj : graph[node]){

        if(!visited[adj]){

            visited[adj] = true;

            q.push(adj);
        }
    }

    bfs();
}


// BFS
void bfs(int start)
{
    bool visit[100] = {false};

    queue<int> q;

    q.push(start);
    visit[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int adj : graph[node])
        {
            if(!visit[adj])
            {
                visit[adj] = true;
                q.push(adj);
            }
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";

    for(int i=0; i<e; i++)
    {
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



// try->
vector<bool> vis(n, false);
void dfs(int node){
    vis
}