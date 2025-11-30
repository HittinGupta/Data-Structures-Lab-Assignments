#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

struct DSU
{
    vector<int> parent, r;
    DSU(int n)
    {
        parent.resize(n);
        r.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};

void bfs(int n, const vector<vector<pair<int, int>>> &adj)
{
    int src;
    cout << "Enter starting vertex for BFS (0 to " << n - 1 << "): ";
    cin >> src;
    vector<int> vis(n, 0);
    queue<int> q;
    vis[src] = 1;
    q.push(src);
    cout << "BFS traversal: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto p : adj[u])
        {
            int v = p.first;
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int u, const vector<vector<pair<int, int>>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    cout << u << " ";
    for (auto p : adj[u])
    {
        int v = p.first;
        if (!vis[v])
            dfsUtil(v, adj, vis);
    }
}

void dfs(int n, const vector<vector<pair<int, int>>> &adj)
{
    int src;
    cout << "Enter starting vertex for DFS (0 to " << n - 1 << "): ";
    cin >> src;
    vector<int> vis(n, 0);
    cout << "DFS traversal: ";
    dfsUtil(src, adj, vis);
    cout << endl;
}

void kruskal(int n, vector<Edge> edges)
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });
    DSU dsu(n);
    int total = 0;
    cout << "Edges in MST using Kruskal:\n";
    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
            total += e.w;
        }
    }
    cout << "Total weight of MST (Kruskal): " << total << endl;
}

void prim(int n, const vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(n, INT_MAX), parent(n, -1), inMST(n, 0);
    key[0] = 0;
    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        int u = -1, mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] && key[i] < mn)
            {
                mn = key[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        inMST[u] = 1;
        for (auto p : adj[u])
        {
            int v = p.first, w = p.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    int total = 0;
    cout << "Edges in MST using Prim:\n";
    for (int v = 1; v < n; v++)
    {
        if (parent[v] != -1)
        {
            cout << parent[v] << " - " << v << " (weight " << key[v] << ")\n";
            total += key[v];
        }
    }
    cout << "Total weight of MST (Prim): " << total << endl;
}

void dijkstra(int n, const vector<vector<pair<int, int>>> &adj)
{
    int src;
    cout << "Enter source vertex for Dijkstra (0 to " << n - 1 << "): ";
    cin >> src;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto p : adj[u])
        {
            int v = p.first, w = p.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << ": unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<Edge> edges;
    edges.reserve(m);
    cout << "Enter " << m << " edges (u v w) for an undirected weighted graph, vertices 0 to " << n - 1 << ":\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    int choice;
    do
    {
        cout << "\nGraph Algorithms Menu\n";
        cout << "1. Breadth First Search (BFS)\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Minimum Spanning Tree (Kruskal)\n";
        cout << "4. Minimum Spanning Tree (Prim)\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bfs(n, adj);
            break;
        case 2:
            dfs(n, adj);
            break;
        case 3:
            kruskal(n, edges);
            break;
        case 4:
            prim(n, adj);
            break;
        case 5:
            dijkstra(n, adj);
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
