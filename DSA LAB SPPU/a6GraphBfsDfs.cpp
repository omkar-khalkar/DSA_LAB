/*
Experiment 13 : Represent a given grapg using adjacency matrix/list to perform DFS and using adjacency list to perform BFS.
                Use the map of the area around the college as a graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
Adjacency Matrix : using adj matrix -BFS(Que)
*/
#include <iostream>
#include <stack>
using namespace std;


int cost[10][10], i, j, k, n, qu[10], front, rear, v, visited[10];
int stk[10], top, visited1[10];

int main()
{
    int m;
    cout << "\nEnter Number Of Vertices:";
    cin >> n;
    cout << "\nEnter Number Of Edges:";
    cin >> m;

    for (k = 0; k < m; k++)
    {
        cout << "EDGE :";
        cin >> i >> j;
        cost[i][j] = 1; // adjecny matrix
        cost[j][i] = 1; // for unddirected graph
    }

    cout << "The Adjecency Matrix Of Given Graph is " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    cout << "Enter Initial Vertex : ";
    cin >> v;
    cout << "The BFS OF Graph : ";
    cout << v << " ";
    visited[v] = 1;
    k = 1;

    while (k <= n)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited[j] != 1)
            {
                visited[j] = 1;
                qu[rear++] = j;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;
    }
    cout << "\Enter Initial Vertex :";
    cin >> v;
    cout << "The DFS of Graph :";
    cout << v << endl;
    visited1[v] = 1;
    k = 1;
    while (k <= n)
    {
        for (j = n; j >= 1; j--)
        {
            if (cost[v][j] != 0 && visited1[j] != 1)
            {
                visited1[j] = 1;
                stk[top] = j;
                top++;
            }
        }
        v = stk[--top];
        cout << v << " ";
        k++;
       
    }

    return 0;
}