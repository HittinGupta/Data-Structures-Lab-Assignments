// Q4 (Additional Q3): Network Delay Time using Dijkstra on directed weighted graph

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int N, E;
    cout << "Enter number of nodes N: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<pair<int, int>>> adj(N + 1);
    cout << "Enter edges (u v w) for directed graph, nodes numbered 1 to " << N << ":\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int K;
    cout << "Enter starting node K: ";
    cin >> K;

    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K});

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

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INT_MAX)
        {
            ans = -1;
            break;
        }
        ans = max(ans, dist[i]);
    }
    if (ans == -1)
        cout << "Some nodes cannot be reached. Answer: -1\n";
    else
        cout << "Time for all nodes to receive the signal: " << ans << endl;
    return 0;
}
