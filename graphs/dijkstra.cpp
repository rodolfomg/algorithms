#include<bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cost(INT_MAX), prevNode(0), id(0) {}
  int cost, prevNode, id;
}

Node nodes[1000];

using NodeContainer = vector<Node>;

/** Dijkstra:
 *  Insertar el nodo inicial
 *  Mientras haya nodos en la priority queue
 *    Extraer nodo
 *
 *    Si nodo igual al nodo_final
 *      Terminar algoritmo
 *
 *    Revisar los nodos adyacentes
 *      Si el nuevo costo es menor al costo del nodo_adyacente
 *        Actualizar costo y nodo_anterior del nodo_adyacente
 *        Incluir nodo en la priority queue
**/
void findPaths(vector< vector< pair<int, int> > > conections, int start, int end) {
  for (size_t i = 0; i < connections.size(); i++) {
    nodes[i].cost = INT_MAX;
    nodes[i].id = i;
  }
  auto cmp = [](const Node& lhs, const Node& rhs) {
    return lhs.cost < rhs.cost;
  }
  priority_queue<Node, NodeContainer, decltype(cmp)> queue(cmp);

  nodes[start].cost = 0;
  queue(nodes[start]);
  while (!queue.empty) {
    Node node = queue.top();
    queue.pop();

    if (node.id == end) break;

    for (auto con : connections[node.id]) {
      if (node.cost + con.second < nodes[con.first].cost) {
        nodes[con.first].cost = node.cost + con.second;
        nodes[con.first].prevNode = node.id;
        queue.push(nodes[con.first]);
      }
    }
  }

  int i = end;
  while (i != start) {
    cout << i << ' ';
    i = nodes[i].prevNode;
  }
  cout << i;
}


int main () {
  // int n;
  // cin >> n;
  // for (size_t i = 0; i < n; i++) {
  //   /* code */
  // }
  return 0;
}
