#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int src, dest, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
  return e1.weight < e2.weight;
}

int findParent(vector<int>& parent, int u) {
  if (parent[u] != u) {
    parent[u] = findParent(parent, parent[u]);
  }
  return parent[u];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
  int xroot = findParent(parent, x);
  int yroot = findParent(parent, y);

  if (rank[xroot] < rank[yroot]) {
    parent[xroot] = yroot;
  } else if (rank[xroot] > rank[yroot]) {
    parent[yroot] = xroot;
  } else {
    parent[yroot] = xroot;
    rank[xroot]++;
  }
}

vector<Edge> KruskalsMST(vector<Edge>& edges, int V) {
  vector<Edge> result; // Stores edges in the MST
  vector<int> parent(V); // Stores parent of each vertex
  vector<int> rank(V, 0); // Stores rank of each vertex for efficient union-find

  sort(edges.begin(), edges.end(), compareEdges);
  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }

  int i = 0; // Index used to pick next edge
  while (result.size() < V - 1) {
    Edge next_edge = edges[i++];

    int x = findParent(parent, next_edge.src);
    int y = findParent(parent, next_edge.dest);

    if (x != y) {
      result.push_back(next_edge);
      unionSets(parent, rank, x, y);
    }
  }

  return result;
}

int main() {
  vector<Edge> edges = {
    {0, 1, 4}, {0, 2, 3}, {1, 2, 1}, {1, 3, 2}, {2, 3, 4}, {4, 5, 3}, {5, 6, 1}
  };
  int V = 7; 

  vector<Edge> mst = KruskalsMST(edges, V);

  cout << "Edges in the constructed MST: \n";
  for (Edge edge : mst) {
    cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
  }

  return 0;
}