#include <iostream>
#include <vector>
using namespace std;

void dfsCC(int u, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            dfsCC(v, adj, vis);
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter " << E << " edges (u v) for an undirected graph, vertices 0 to " << V - 1 << ":\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    int components = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            components++;
            dfsCC(i, adj, vis);
        }
    }
    cout << "Number of connected components: " << components << endl;
    return 0;
}
