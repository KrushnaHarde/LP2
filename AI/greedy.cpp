#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

struct Edge {
    int u, v, w;
};

// ---------- Selection Sort ----------
void selectionSort() {

    /*
    Sample Input:
    5
    64 25 12 22 11
    */

    int n;
    cin >> n;

    int a[n];

    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n-1;i++) {

        int minIndex = i;

        for(int j=i+1;j<n;j++) {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }

    cout << "Sorted Array:\n";

    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}

// ---------- Dijkstra ----------
void dijkstra() {

    /*
    Sample Input:
    4
    0 2 999 1
    2 0 3 2
    999 3 0 4
    1 2 4 0
    0
    */

    int n, source;
    cin >> n;

    int a[n][n], dist[n], visited[n]={0};

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    cin >> source;

    for(int i=0;i<n;i++)
        dist[i] = a[source][i];

    visited[source] = 1;

    for(int k=0;k<n-1;k++) {

        int min = 999, u;

        for(int i=0;i<n;i++) {

            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v=0;v<n;v++) {

            if(!visited[v] && dist[u] + a[u][v] < dist[v]) {
                dist[v] = dist[u] + a[u][v];
            }
        }
    }

    cout << "Shortest Distances:\n";

    for(int i=0;i<n;i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;
}

// ---------- Job Scheduling ----------
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling() {

    /*
    Sample Input:
    4
    A 2 100
    B 1 19
    C 2 27
    D 1 25
    */

    int n;
    cin >> n;

    Job jobs[n];

    for(int i=0;i<n;i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs, jobs+n, cmp);

    bool slot[n] = {0};

    cout << "Selected Jobs:\n";

    for(int i=0;i<n;i++) {

        for(int j=min(n, jobs[i].deadline)-1;j>=0;j--) {

            if(!slot[j]) {
                slot[j] = true;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }
}

// ---------- Kruskal ----------
int parent[10];

int find(int i) {

    while(parent[i])
        i = parent[i];

    return i;
}

void uni(int a, int b) {
    parent[b] = a;
}

bool cmpEdge(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskal() {

    /*
    Sample Input:
    5
    0 2 0 6 0
    2 0 3 8 5
    0 3 0 0 7
    6 8 0 0 9
    0 5 7 9 0
    */

    int n;
    cin >> n;

    int a[10][10];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    Edge e[20];
    int k = 0;

    for(int i=0;i<n;i++) {

        for(int j=i+1;j<n;j++) {

            if(a[i][j] != 0) {
                e[k++] = {i,j,a[i][j]};
            }
        }
    }

    sort(e, e+k, cmpEdge);

    int cost = 0;

    for(int i=0;i<k;i++) {

        int a = find(e[i].u);
        int b = find(e[i].v);

        if(a != b) {

            uni(a,b);

            cout << e[i].u << " - " << e[i].v
                 << " : " << e[i].w << endl;

            cost += e[i].w;
        }
    }

    cout << "Cost = " << cost;
}

// ---------- Main ----------
int main() {

    int choice;

    cout << "\n----- MENU -----\n";
    cout << "1. Selection Sort\n";
    cout << "4. Job Scheduling\n";
    cout << "6. Kruskal MST\n";
    cout << "7. Dijkstra Algorithm\n";

    cout << "\nEnter Choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            selectionSort();
            break;

        case 4:
            jobScheduling();
            break;

        case 6:
            kruskal();
            break;

        case 7:
            dijkstra();
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void dijkstra(int V, vector<vector<pii>>& adj, int src){

    vector<int> dist(V, INT_MAX);

    priority_queue<pii,
                   vector<pii>,
                   greater<pii>> pq;

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty()){

        int currDist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // Skip outdated entries
        if(currDist > dist[node])
            continue;

        for(auto neighbor : adj[node]){

            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if(currDist + edgeWeight < dist[adjNode]){

                dist[adjNode] =
                    currDist + edgeWeight;

                pq.push({
                    dist[adjNode],
                    adjNode
                });
            }
        }
    }

    cout << "Shortest Distances:\n";

    for(int i=0; i<V; i++){

        cout << src
             << " -> "
             << i
             << " = "
             << dist[i]
             << endl;
    }
}

int main(){

    /*
    Sample Input:
    5 6
    0 1 2
    0 3 1
    1 2 3
    3 2 1
    2 4 5
    3 4 4
    0
    */

    int V, E;

    cin >> V >> E;

    vector<vector<pii>> adj(V);

    for(int i=0; i<E; i++){

        int u,v,w;

        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src;

    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}