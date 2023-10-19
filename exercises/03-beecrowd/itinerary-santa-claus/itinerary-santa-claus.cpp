#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_VERTICES 40050
#define MAX_EDGES 40000

struct Edge {
    int start, end, weight;
};

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

int compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findComponent(int vertex) {
    if (vertex == parent[vertex])
        return vertex;
    return parent[vertex] = findComponent(parent[vertex]);
}

int kruskal(int edgeCount) {
    int totalWeight = 0;
    for (int i = 0; i < edgeCount; ++i) {
        int startComponent = findComponent(edges[i].start);
        int endComponent = findComponent(edges[i].end);
        if (startComponent != endComponent) {
            parent[startComponent] = endComponent;
            totalWeight += edges[i].weight;
        }
    }
    return totalWeight;
}

int main() {
    int numVertices, numEdges, i;

    while (cin >> numVertices >> numEdges, numVertices && numEdges) {
        fill(edges, edges + numEdges, Edge());
        fill(parent, parent + numVertices + 1, 0);

        for (i = 0; i < numEdges; ++i)
            cin >> edges[i].start >> edges[i].end >> edges[i].weight;

        sort(edges, edges + numEdges, compareEdges);

        for (i = 1; i <= numVertices; ++i)
            parent[i] = i;

        cout << kruskal(numEdges) << endl;
    }

    return 0;
}
