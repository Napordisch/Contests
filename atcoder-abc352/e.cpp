#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

template <typename T>
void Swap(T object_a, T object_b) {
  T buffer_object = object_a;
  object_a = object_b;
  object_b = buffer_object;
}

struct DisjointSetUnion {
  DisjointSetUnion() = default;

  explicit DisjointSetUnion(int size) {
    parents.resize(size);
    heights.resize(size, 0);
    for (int i = 0; i < size; ++i) {
      parents[i] = i;
    }
  }

  vector<int> parents;
  vector<int> heights;

  int Leader(int element) {
    if (parents[element] == element) {
      return element;
    }
    parents[element] = Leader(parents[element]);
    return parents[element];
  }

  void Unite(int element_a, int element_b) {
    int a = Leader(element_a);
    int b = Leader(element_b);
    if (heights[a] > heights[b]) {  // parent — the element with < height
      Swap(a, b);
    }
    heights[b] = std::max(heights[b], heights[a] + 1);
    parents[a] = b;
  }
};

struct Edge {
  Edge() = default;
  Edge(int one, int two, int w) {
    v1 = one;
    v2 = two;
    weight = w;
  }
  int v1 = 0;
  int v2 = 0;
  int weight = 0;
};

struct Graph {
  Graph() = default;

  explicit Graph(int vertexes_amount) {
    amount_of_vertexes = vertexes_amount;
    vertexes_DSU = DisjointSetUnion(amount_of_vertexes);
  }

  void DisplayEdges() {
    for (unsigned int i = 0; i < edges.size(); ++i) {
      cout << edges[i].v1 + 1 << ' ';
      cout << edges[i].v2 + 1 << ' ';
      cout << edges[i].weight << '\n';
    }
  }

  int amount_of_edges = 0;
  int amount_of_vertexes = 0;
  vector<Edge> edges;
  DisjointSetUnion vertexes_DSU;
  int min_spanning_tree_weight = 0;

  int Kruskal() {
    for (unsigned int i = 0; i < edges.size(); ++i) {
      Edge the_edge = edges[i];
      if (vertexes_DSU.Leader(the_edge.v1) != vertexes_DSU.Leader(the_edge.v2)) {
        vertexes_DSU.Unite(the_edge.v1, the_edge.v2);
        min_spanning_tree_weight += the_edge.weight;
      }
    }
    return min_spanning_tree_weight;
  }

  void ConnectSet(unsigned int k, int weight, vector<unsigned int> vertexes) {
    for (unsigned int u = 0; u < k; ++u) {
      for (unsigned int v = 0; v < k; ++v) {
        if (u < v) {
          edges.emplace_back(u, v, weight);
          amount_of_edges++;
        }
      }
    }
  }
  
};

int main() {
  unsigned int N = 0;
  unsigned int M = 0;
  cin >> N >> M;
  Graph g(N);
  for (unsigned int i = 0; i < M; ++i) {
    int k = 0;
    int c = 0;
    cin >> k >> c;
    vector<unsigned int> set;
    for (unsigned int j = 0; j < k; ++j) {
      unsigned int vertex = 0;
      cin >> vertex;
      set.push_back(vertex - 1);
    }
    g.ConnectSet(k, c, set);
  }
  cout <<  g.Kruskal() << '\n';
}
