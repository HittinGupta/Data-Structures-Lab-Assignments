#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Cell
{
    int dist, r, c;
    bool operator>(const Cell &other) const
    {
        return dist > other.dist;
    }
};

int main()
{
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid values (non-negative costs):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        Cell cur = pq.top();
        pq.pop();
        int d = cur.dist, r = cur.r, c = cur.c;
        if (d != dist[r][c])
            continue;
        if (r == m - 1 && c == n - 1)
            break;
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
                int nd = d + grid[nr][nc];
                if (nd < dist[nr][nc])
                {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }
    }

    cout << "Minimum total cost from (0,0) to (" << m - 1 << "," << n - 1 << "): "
         << dist[m - 1][n - 1] << endl;
    return 0;
}
