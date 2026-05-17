#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Cell {
    int x, y;
};

int h(int x, int y, int dx, int dy) {
    return abs(x - dx) + abs(y - dy); // Manhattan distance
}

void printPath(vector<vector<Cell>>& parent, int x, int y) {
    if (x == -1 || y == -1) return;

    printPath(parent, parent[x][y].x, parent[x][y].y);
    cout << "(" << x << "," << y << ") ";
}

void astar(vector<vector<int>>& grid,
           int sx, int sy,
           int dx, int dy) {

    vector<vector<int>> g(n, vector<int>(m, 1e9));

    vector<vector<Cell>> parent(n, vector<Cell>(m, {-1,-1}));

    // (f_cost , (x,y))
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;       

    g[sx][sy] = 0;
    pq.push({h(sx,sy,dx,dy), {sx,sy}});

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!pq.empty()) {

        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == dx && y == dy)
            break;

        for (auto &d : dir) {

            int nx = x + d[0];
            int ny = y + d[1];

            if (nx >= 0 && ny >= 0 &&
                nx < n && ny < m &&
                grid[nx][ny] == 0) {

                int newG = g[x][y] + 1;

                if (newG < g[nx][ny]) {

                    g[nx][ny] = newG;

                    int f = newG + h(nx,ny,dx,dy);

                    pq.push({f, {nx,ny}});

                    parent[nx][ny] = {x,y};
                }
            }
        }
    }

    if (g[dx][dy] == 1e9) { 
        cout << "No Path Found\n";
        return;
    }

    cout << "Shortest Path:\n";
    printPath(parent, dx, dy);

    cout << "\nCost = " << g[dx][dy] << endl;
}

int main() {

    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> grid[i][j];

    int sx, sy, dx, dy;

    cin >> sx >> sy;
    cin >> dx >> dy;

    astar(grid, sx, sy, dx, dy);

    return 0;
}

// Sample Input:

// 5 5

// 0 0 0 0 0
// 1 1 0 1 0
// 0 0 0 1 0
// 0 1 1 0 0
// 0 0 0 0 0

// 0 0
// 4 4