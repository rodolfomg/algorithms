#include <iostream>
#include <vector>

using namespace std;

/**
 * Realizar multiples conexiones entre personas
 * Dada una persona, encontrar a cuantas persanas les llega una notica usando
 * a dicha persona como punto de partida.
**/

class DisjointSet {
public:
  struct Node {
    Node (size_t p) : parent(p), rank(1), size(1) {}
    size_t parent, rank, size;    
  };

  DisjointSet () = default;
  DisjointSet (int size) {
    for (size_t i = 0; i < size + 1; i++) vec.emplace_back(Node(i));
  }

  size_t find (size_t i) {
    if (i != vec[i].parent) {
      vec[i].parent = find(vec[i].parent);
      return vec[i].parent;
    }
    else {
      return i;
    }
  }

  void unionRank (size_t i, size_t j) {
    i = find(i);
    j = find(j);

    if (i == j) return;

    if (vec[i].rank > vec[j].rank) {
      vec[j].parent = i;
      vec[i].size += vec[j].size;
    }
    else {
      vec[i].parent = j;
      vec[j].size += vec[i].size;
      if (vec[i].rank == vec[j].rank) vec[j].rank++;
    }
  }

  size_t groupSize (size_t i) {
    i = find(i);
    return vec[i].size;
  }

private:
  vector<Node> vec;
};

int main(int argc, char const *argv[]){
  size_t n, k, x, y;
  char op;
  cin >> n >> k;

  ios_base::sync_with_stdio(0);cin.tie(0);

  DisjointSet set(n);

  for (int i = 0; i < k; ++i) {
    cin >> op;
    if (op == 'A') { // agrupar dos elementos
      cin >> x >> y;
      set.unionRank(x, y);
    }
    if (op == 'E') { // dar noticia
      cin >> x;
      cout << '\n' << set.groupSize(x);
    }
  }

  return 0;
}

