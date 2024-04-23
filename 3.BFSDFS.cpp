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

        visited[start] = true;
        s.push(start);
        std::cout << start << " ";

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            for (int v = 0; v < V; ++v)
            {
                if (adjMatrix[u][v] && !visited[v])
                {
                    visited[v] = true;
                    s.push(v);
                    std::cout << v << " ";
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    std::cout << "Breadth First Search (BFS): ";
    graph.BFS(0);

    std::cout << "Depth First Search (DFS): ";
    graph.DFS(0);

    return 0;
}
