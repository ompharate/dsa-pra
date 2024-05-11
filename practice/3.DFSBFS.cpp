#include <iostream>
#include <queue>
#include <stack>
#define MAX 100
using namespace std;
class Graph
{
    int V;
    int adj[MAX][MAX];

public:
    Graph(int v)
    {
        this->V = v;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start)
    {
        bool visited[MAX] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            cout << u;
            q.pop();

            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] && !visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    void DFS(int start)
    {
        bool visited[MAX] = {false};
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {

            int u = s.top();
            s.pop();
            if (!visited[u])
            {

                cout << u;
                visited[u] = true;

                for (int v = 0; v < V; v++)
                {
                    if (adj[u][v] && !visited[v])
                    {
                        s.push(v);
                        visited[v] = true;
                        cout << v;
                        break;
                    }
                }
            }
        }
    };
};
int main()
{
    int vertices, edges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;

    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    Graph graph(vertices);

    std::cout << "Enter the edges (u v):" << std::endl;
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        graph.addEdge(u, v);
    }

    std::cout << "Breadth First Search (BFS): ";
    graph.BFS(0);

    std::cout << "Depth First Search (DFS): ";
    graph.DFS(0);
    return 0;
}