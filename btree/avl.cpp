#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

class AVLTree {
  struct Node {
    Node (int v) : value(v), height(0), left(nullptr), right(nullptr) {}
    int value, height;
    Node* left;
    Node* right;
  };

public:
  AVLTree () : _root(nullptr) {}

  AVLTree& insert (int value) {
    if (!_root) {
      _root = new Node(value);
      return *this;
    }

    balanceTree(value, _root);
    _root = balanceSubTree(_root);
    return *this;
  }

  AVLTree& print () {
    inOrder(_root);
    cout << endl;
    bfs();
    cout << endl << endl;
    return *this;
  }

private:
  // left_child > parent > right_child
  void inOrder (Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->value << ' ';
    inOrder(node->right);
  }

  void bfs () {
    queue<Node*> nodes;
    nodes.emplace(_root);

    size_t counter = 0, level = 0;

    while (!nodes.empty()) {
      Node* current_node = nodes.front(); nodes.pop();

      if (current_node) {
        cout << current_node->value << ' ';
        nodes.emplace(current_node->left);
        nodes.emplace(current_node->right);
      }
      else {
        cout << "_ ";
      }

      counter++;
      if (counter == pow(2, level)) {
        cout << endl;
        counter = 0;
        level++;
      }
    }
  }

  int checkBalance (Node* node) {
    int left_height, right_hight;

    left_height = node->left ? node->left->height : -1;
    right_hight = node->right ? node->right->height: -1;

    return left_height - right_hight;
  }

  size_t checkNodeHeight (Node* node) {
    int left_height = node->left ? node->left->height : -1;
    int right_hight = node->right ? node->right->height: -1;

    return max(left_height, right_hight) + 1;
  }

  Node* rotateLeft (Node* old_root) {
    Node* new_root = old_root->right;
    old_root->right = new_root->left;
    new_root->left = old_root;

    old_root->height = checkNodeHeight(old_root);
    new_root->height = checkNodeHeight(new_root);

    return new_root;
  }

  Node* rotateRight (Node* old_root) {
    Node* new_root = old_root->left;
    old_root->left = new_root->right;
    new_root->right = old_root;

    old_root->height = checkNodeHeight(old_root);
    new_root->height = checkNodeHeight(new_root);

    return new_root;
  }

  Node* balanceSubTree (Node* root) {
    int balance = checkBalance(root);
    if (-1 <= balance && balance <= 1) return root;

    if (balance > 0) { // left-heavy
      if (!root->left->left) root->left = rotateLeft(root->left);
      return rotateRight(root);
    }
    else { // right-heavy
      if (!root->right->right) root->right = rotateRight(root->right);
      return rotateLeft(root);
    }
  }

  void balanceTree (int value, Node* current_node) {
    // Return new Node or balanced subtree Root
    auto insert_and_balance = [&] (Node* child) {
      current_node->height++;

      if (child) {
        balanceTree(value, child);
        return balanceSubTree(child);
      }
      else {
        return new Node(value);
      }
    };

    if (value < current_node->value) {
      current_node->left = insert_and_balance(current_node->left);
    }
    else {
      current_node->right = insert_and_balance(current_node->right);
    }
  }

  Node* _root;
};

int main () {
  size_t n;
  int value;
  AVLTree tree = AVLTree();

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> value;
    tree.insert(value);
  }

  tree.print();
}


