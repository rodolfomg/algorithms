#include <iostream>
#include <vector>

using namespace std;

class segmentTree {
  struct Node {
    Node (size_t start, size_t finish)
      : range(make_pair(start, finish)),
        value(0),
        left(nullptr),
        right(nullptr) {}

    pair<size_t, size_t> range;
    int value;
    Node* left;
    Node* right;
  };

 public:
  segmentTree (const vector<int>& elements)
    : elements_(elements) {
    root_ = generateTree(0, elements_.size() - 1);
  }

  updateElement (size_t x) {
    updateTree(x, root_);
  }

 private:
  Node* generateTree (size_t i, size_t j) {
    Node* node = new Node(i, j);

    if (j - i == 0) { // Range with a single element
      node->value = elements_[i];
    }
    else { // Range with at least 2 elements
      node->left = generateTree(i, (i + j) / 2);
      node->right = generateTree((i + j) / 2 + 1, j);

      node->value = node->left->value + node->right->value;
    }

    return node;
  }

  void updateTree (size_t x, Node* node) {
    if (node->range.first == x && node->range.second == x) {
      node->value = elements_[x];
    }
    else {
      if (node->left->range.second <= x) { // x is in left range
        updateTree(x, node->left);
      }
      else {                               // x is in right range
        updateTree(x, node->right);
      }
      node->value = node->left->value + node->right->value;
    }
  }

  const vector<int>& elements_;
  Node* root_;
};

int main () {}