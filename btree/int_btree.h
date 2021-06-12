#include <vector>
#include <stack>

using std::stack;
using std::vector;

struct BSTreeNode {
  BSTreeNode (const int& v) : value(v), left(nullptr), right(nullptr) {}
  int value;
  BSTreeNode* left;
  BSTreeNode* right;
};

class BSTree {
public:
  BSTree () : root(nullptr) {}

  BSTree (const vector<int>& nodes) {
    for (int value : nodes) {
      insertNode(value);
    }
  }

  BSTreeNode* insertNode (int value) {
    if (!root) {
      root = new BSTreeNode(value);
      return root;
    }
    return insert(value, root);
  }

  vector<int> dataInOrder () {
    vector<int> result;
    inOrder(root, result);
    return result;
  }

  vector<int> dataPreOrder () {
    vector<int> result;
    preOrder(root, result);
    return result;
  }

  vector<int> dataPostOrder () {
    vector<int> result;
    postOrder(root, result);
    return result;
  }

  int distance (int value) {
    return searchDistance(root, value);
  }

private:
  int searchDistance (BSTreeNode* node, int value) {
    if (node == nullptr) return -1;
    if (value == node->value) return 0;
    else {
      int d;
      if (value < node->value) d = searchDistance(node->left, value);
      if (value > node->value) d = searchDistance(node->right, value);
      return d == -1 ? -1 : d + 1;
    }
  }

  int searchDistance (BSTreeNode* node, int value) {
    if (node == nullptr) return -1;
    if (value == node->value) return 0;
    else {
      int d;
      if (value < node->value) d = searchDistance(node->left, value);
      if (value > node->value) d = searchDistance(node->right, value);
      return d == -1 ? -1 : d + 1;
    }
  }

  void inOrder (BSTreeNode* node, vector<int>& result) {
    if (node->left) inOrder(node->left, result);
    result.emplace_back(node->value);
    if (node->right) inOrder(node->right, result);
  }

  void preOrder (BSTreeNode* node, vector<int>& result) {
    result.emplace_back(node->value);
    if (node->left) inOrder(node->left, result);
    if (node->right) inOrder(node->right, result);
  }

  void postOrder (BSTreeNode* node, vector<int>& result) {
    if (node->left) inOrder(node->left, result);
    if (node->right) inOrder(node->right, result);
    result.emplace_back(node->value);
  }

  BSTreeNode* insert (int value, BSTreeNode* node) {
    if (value < node->value) {
      if (node->left) return insert(value, node->left);
      else {
        node->left = new BSTreeNode(value);
        return node->left;
      }
    }
    else {
      if (node->right) return insert(value, node->right);
      else {
        node->right = new BSTreeNode(value);
        return node->right;
      }
    }
  }

  BSTreeNode* root;
};
