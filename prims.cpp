#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertexcnt;                 // Number of vertices in the graph
    vector<vector<int>> adjMatrix; // Adjacency matrix to represent the graph
    map<string, int> cities;       // Map to store city names and their corresponding vertex indices
    map<int, string> inv_cities;   // Map to store inverse mapping of vertex indices to city names

public:
    Graph()
    {
        cout << "Enter number of cities: " << endl;
        cin >> vertexcnt;

        // Resize the adjacency matrix and initialize all elements to 0
        adjMatrix.resize(vertexcnt, vector<int>(vertexcnt, 0));

        cout << "Enter city names: " << endl;
        for (int i = 0; i < vertexcnt; i++)
        {
            string city;
            cin >> city;
            cities[city] = i;     // Assigning vertex index for each city name
            inv_cities[i] = city; // Assigning city name for each vertex index
        }

        // Input distances between cities and update adjacency matrix accordingly
        cout << "Enter distances between cities: " << endl;
        for (int i = 0; i < vertexcnt; i++)
        {
            for (int j = i + 1; j < vertexcnt; j++)
            {
                int d;
                cout << "Distance from " << inv_cities[i] << " to " << inv_cities[j] << " : ";
                cin >> d;
                adjMatrix[i][j] = adjMatrix[j][i] = d; // Update distance between cities i and j
            }
        }
    }

    void prim()
    {
        int n = vertexcnt;           // Number of vertices
        vector<int> parent(n, -1);   // Vector to store parent of each vertex in MST
        vector<int> key(n, INT_MAX); // Vector to store minimum key value for each vertex
        vector<bool> MST(n, false);  // Vector to mark vertices included in MST

        key[0] = 0; // Start with the first vertex as the root of MST
        for (int i = 0; i < n - 1; i++)
        {
            int u = minimumkey(key, MST); // Find vertex with minimum key value that is not yet in MST
            MST[u] = true;                // Mark vertex as included in MST

            // Update key values and parent pointers for vertices adjacent to u
            for (int v = 0; v < n; v++)
            {
                // If vertex v is adjacent to u, not in MST, and the weight of edge (u, v) is less than current key value of v
                if (adjMatrix[u][v] && !MST[v] && adjMatrix[u][v] < key[v])
                {
                    parent[v] = u;            // Update parent of v to u
                    key[v] = adjMatrix[u][v]; // Update key value of v
                }
            }
        }

        // Print the Minimum Spanning Tree (MST)
        cout << "Minimum Spanning Tree (MST): " << endl;
        cout << "Edge \tWeight" << endl;
        for (int i = 1; i < n; i++)
        {
            cout << inv_cities[parent[i]] << " - " << inv_cities[i] << "\t" << adjMatrix[i][parent[i]] << endl;
        }
    }

private:
    // Function to find the vertex with minimum key value that is not yet included in MST
    int minimumkey(vector<int> &key, vector<bool> &MST)
    {
        int minkey = INT_MAX, minindex = -1;
        for (int v = 0; v < vertexcnt; v++)
        {
            // If vertex v is not yet included in MST and its key value is less than current minimum
            if (!MST[v] && key[v] < minkey)
            {
                minkey = key[v]; // Update minimum key value
                minindex = v;    // Update index of vertex with minimum key value
            }
        }
        return minindex;
    }
};

int main()
{
    Graph g;
    g.prim(); // Find and print the Minimum Spanning Tree (MST) using Prim's algorithm
    return 0;
}
