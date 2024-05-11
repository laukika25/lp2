#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertexCount;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> parent;         // Vector to store the parent of each vertex
    map<string, int> cities;    // Map to store city names and their corresponding vertex indices
    map<int, string> invCities; // Map to store inverse mapping of vertex indices to city names

public:
    Graph()
    {
        cout << "Enter number of cities: ";
        cin >> vertexCount;

        // Initialize parent vector with each vertex being its own parent
        parent.resize(vertexCount);
        for (int i = 0; i < vertexCount; ++i)
        {
            parent[i] = i;
        }

        cout << "Enter city names: ";
        for (int i = 0; i < vertexCount; ++i)
        {
            string city;
            cin >> city;
            cities[city] = i;    // Assigning vertex index for each city name
            invCities[i] = city; // Assigning city name for each vertex index
        }

        // Input distances between cities and create edges
        cout << "Enter distances between cities: " << endl;
        for (int i = 0; i < vertexCount; ++i)
        {
            for (int j = i + 1; j < vertexCount; ++j)
            {
                int d;
                cout << "Distance from " << invCities[i] << " to " << invCities[j] << " : ";
                cin >> d;
                edges.push_back({d, {i, j}}); // Pushing edge with weight and vertex pair
            }
        }

        // Sort edges based on their weights
        sort(edges.begin(), edges.end());
    }

    void kruskal()
    {
        vector<pair<int, pair<int, int>>> mst; // Vector to store edges of Minimum Spanning Tree (MST)
        for (auto edge : edges)
        {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            // Find the sets to which vertices u and v belong
            int setU = find(u);
            int setV = find(v);

            // If u and v are not in the same set (i.e., adding edge (u,v) does not form a cycle)
            if (setU != setV)
            {
                mst.push_back({weight, {u, v}}); // Add edge (u,v) to MST
                parent[setU] = setV;             // Union operation: merge sets containing u and v
            }
        }

        // Print MST edges and their weights
        cout << "Minimum Spanning Tree (MST):" << endl;
        cout << "Edge \tWeight" << endl;
        for (auto edge : mst)
        {
            cout << invCities[edge.second.first] << " - " << invCities[edge.second.second] << "\t" << edge.first << endl;
        }
    }

private:
    // Find operation in disjoint-set data structure (with path compression)
    int find(int vertex)
    {
        if (parent[vertex] != vertex)
        {
            parent[vertex] = find(parent[vertex]); // Path compression
        }
        return parent[vertex];
    }
};

int main()
{
    Graph g;
    g.kruskal();
    return 0;
}
