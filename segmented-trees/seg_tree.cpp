#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
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
  SegmentTree (const vector<int>& elements)
    : elements_(elements) {
    root_ = generateTree(0, elements_.size() - 1);
  }

  SegmentTree& updateElement (size_t x) {
    updateTree(x, root_);
    return *this;
  }

  int getRangeSum (size_t x, size_t y) {
    return processSum(x, y, root_);
  }

 private:
  Node* generateTree (size_t i, size_t j) {
    Node* node = new Node(i, j);

    if (j - i == 0) { // Range with a single element
      node->value = elements_[i];
    }
    else { // Range with at least 2 elements
      size_t mid = (i + j) / 2;
      node->left = generateTree(i, mid);
      node->right = generateTree(mid + 1, j);

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

  int processSum (size_t x, size_t y, Node* node) {
    // When query range matches node range
    if (node->range.first == x && node->range.second == y) {
      return node->value;
    }

    // When query range is on one of the child
    if (node->left->range.first <= x && y <= node->left->range.second) {
      return processSum(x, y, node->left);
    }
    if (node->right->range.first <= x && y <= node->right->range.second) {
      return processSum(x, y, node->right);
    }

    // When query range is split in the two child
    size_t mid = (node->range.first + node->range.second) / 2;
    return processSum(x, mid, node->left) + processSum(mid + 1, y, node->right);
  }

  const vector<int>& elements_;
  Node* root_;
};

int main () {
  
}