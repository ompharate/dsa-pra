#include <iostream>
#include <queue>
#include <stack>

#define MAX 100

class Graph
{
private:
    int V;
    int adjMatrix[MAX][MAX];

public:
    Graph(int vertices)
    {
        V = vertices;

        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void BFS(int start)
    {
        bool visited[MAX] = {false};
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            std::cout << u << " ";
            q.pop();

            for (int v = 0; v < V; ++v)
            {
                if (adjMatrix[u][v] && !visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int start)
    {
        bool visited[MAX] = {false};
        std::stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visited[u])
            {
                std::cout << u << " ";
                visited[u] = true;

                // Push unvisited neighbors onto the stack
                for (int v = V - 1; v >= 0; --v)
                {
                    if (adjMatrix[u][v] && !visited[v])
                    {
                        s.push(v);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
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
