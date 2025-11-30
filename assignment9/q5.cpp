// Q5 (Additional Q4): Number of Islands in a 2D grid using DFS

#include <iostream>
#include <vector>
using namespace std;

int R, C;

void dfsIsland(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    vis[r][c] = 1;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++)
    {
        int nr = dr[k] + r;
        int nc = dc[k] + c;
        if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
            !vis[nr][nc] && grid[nr][nc] == '1')
        {
            dfsIsland(nr, nc, grid, vis);
        }
    }
}

int main()
{
    cout << "Enter number of rows: ";
    cin >> R;
    cout << "Enter number of columns: ";
    cin >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    cout << "Enter grid values (0 or 1) row-wise:\n";
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    vector<vector<int>> vis(R, vector<int>(C, 0));
    int islands = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                islands++;
                dfsIsland(i, j, grid, vis);
            }
        }
    }
    cout << "Total number of islands: " << islands << endl;
    return 0;
}
