#include <iostream>
#include <vector>

using namespace std;

template<size_t N>
int printCycleRecursively (const int current_node, const vector<vector<int>>& connections, bitset<N>& visited) {
  visited[current_node] = 1;

  for(auto node : connections[current_node]) {
    if (!visited[node]) {
      int last_node = printCycleRecursively(node, connections, visited);

      // Node is part of the cycle
      if (last_node != -1) {
        cout << current_node << ' ';

        // Cycle ended
        if (current_node == last_node) return -1;
        // cycle continues
        else return last_node
      }
    }
    else {
      return current_node;
    }
  }

  return -1;
}

/**
 * [
 *   0: [1],
 *   1: [2, 6],
 *   2: [1, 3, 4],
 *   3: [],
 *   4: [2, 5],
 *   5: [4, 6],
 *   6: [5, 1]
 * ]
 * */
void printCycle (const vector<vector<int>>& connections) {
  bitset<connections.size()> visited; // Bit

  for(int node=0; node<connections.size(); node++) {
    printCycleRecursively(node, connections, visited);
  }
}

int main () {
  // Process/Read node connections

  printCycle(connections);
}