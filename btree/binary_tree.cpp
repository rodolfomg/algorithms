#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Tree {
public:
  // Internal Node Structure
  struct Node {
    Node (int val) : value(val) {}
    int value;
    Node* left;
    Node* right;
  };

  // Empty Constructor
  Tree () : root_(nullptr) {}

  // Creates a new Tree and store first value on root
  Tree (int value) : root_(new Node(value)) {}

  // Checks if Tree is empty
  bool empty () {
    return nullptr == root_;
  }

  // Returns a pointer to root
  Node* root () {
    return empty() ? 0 : root_->value;
  }

  // Insert new elements while mantaining the tree balanced (Does not generate a BST)
  Tree& insert (int value) {
    if (empty()) {
      root_ = new Node(value);
    }
    else {
      queue<Node*> nodes;
      nodes.emplace(root_);

      while (!nodes.empty()) {
        Node* current = nodes.front();
        nodes.pop();
        if (nullptr == current->left) {
          current->left = new Node(value);
          break;
        }
        else {
          nodes.emplace(current->left);
        }
        if (nullptr == current->right) {
          current->right = new Node(value);
          break;
        }
        else {
          nodes.emplace(current->right);
        }
      }
    }
    return *this;
  }


  // Prints the Tree performing a transversal as a list
  Tree& print () {
    queue<Node*> nodes;
    nodes.emplace(root_);

    while(!nodes.empty()) {
      Node* current = nodes.front();
      nodes.pop();

      cout << current->value << ' ';

      if (current->left) nodes.emplace(current->left);
      if (current->right) nodes.emplace(current->right);
    }

    cout << '\n';
    return *this;
  }

  /** Binary Search O(LogN) ? (Only if the tree is balanced)
   *  Params:
   *    int, Value to look for
   *
   *  Return:
   *    Node*, to the node where the value is store in the Tree
   *    nullptr, if the value is not part of the Tree
  **/
  Node* bs (int value) {
    return bsr (value, root_);
  }

  /** Breadth First Search O(N) 
   *  Params:
   *    int, Value to look for
   *
   *  Return:
   *    Node*, to the node where the value is store in the Tree
   *    nullptr, if the value is not part of the Tree
  **/
  Node* bfs (int value) {
    if (nullptr == root_) return nullptr;

    queue<Node*> nodes;
    nodes.emplace(root_);

    while (!nodes.empty()) {
      Node* current = nodes.front();
      nodes.pop();

      if (value == current->value) return current;
      if (current->left) nodes.emplace(current->left);
      if (current->right) nodes.emplace(current->right);

      cout << current->value << ' ';
    }

    return nullptr;
  }

  /** Deep First Search O(N)
   *  Params:
   *    int, Value to look for
   *
   *  Return:
   *    Node*, to the node where the value is store in the Tree
   *    nullptr, if the value is not part of the Tree
   *
   *  Transversing Patterns:
   *    - In-Order
   *    - Pre-Order
   *    - Post-Order
  **/
  void dfs (int value) {
    if (nullptr == root_) return nullptr;

    stack<Node*> nodes;
    nodes.emplace(root_);

    while (!nodes.empty()) {
      Node* current = nodes.front();
      nodes.pop();

      if (value == current->value) return current;
      if (current->right) nodes.emplace(current->right);
      if (current->left) nodes.emplace(current->left);

      cout << current->value << ' ';
    }

    return nullptr;
  }

  /** In-Order (Left->Current->Right)
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  vector<int> inOrder () {
    vector<int> elements;
    InOrder(root_, elements);
    return elements;
  }

  /** Pre-Order (Current->Left->Right)
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  vector<int> preOrder () {
    vector<int> elements;
    PreOrder(root_, elements);
    return elements;
  }

  /** Post-Order (Left->Right->Current)
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  vector<int> postOrder () {
    vector<int> elements;
    PostOrder(root_, elements);
    return elements;
  }

private:
  /** Binary Search O(LogN) - (Only if the tree is balanced)
   *  Params:
   *    int, Value to look for
   *    
   *
   *  Return:
   *    Node*, to the node where the value is store in the Tree
   *    nullptr, if the value is not part of the Tree
  **/
  Node* bsr (int value, Node* current) {
    if (!current) return nullptr;
    if (value == current->value) return current;

    cout << current->value << ' ';

    if (value < current->value) return bsr(value, current->left);
    if (value > current->value) return bsr(value, current->right);
    return nullptr;
  }

  /** In-Order (Left->Current->Right)
   *  Params:
   *    Node*, Current node
   *    vector<int>&, Reference to the vector where the visited nodes will be stored
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  void InOrder (Node* node, vector<int>& elements) {
    if (nullptr == node) return;
    InOrder(node->left, elements);
    elements.emplace_back(node->value);
    InOrder(node->right, elements);
  }

  /** Pre-Order (Current->Left->Right)
   *  Params:
   *    Node*, Current node
   *    vector<int>&, Reference to the vector where the visited nodes will be stored
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  void PreOrder (Node* node, vector<int>& elements) {
    if (nullptr == node) return;
    elements.emplace_back(node->value);
    PreOrder(node->left, elements);
    PreOrder(node->right, elements);
  }

  /** Post-Order (Left->Right->Current)
   *  Params:
   *    Node*, Current node
   *    vector<int>&, Reference to the vector where the visited nodes will be stored
   *
   *  Return:
   *    vector<int>, A list of the visited elements of the Tree
   *
  **/
  void PostOrder (Node* node, vector<int>& elements) {
    if (nullptr == node) return;
    PostOrder(node->left, elements);
    PostOrder(node->right, elements);
    elements.emplace_back(node->value);
  }

  Node* root_;
};

/*
  Input:
  4 2 6 1 3 5 7

  Tree:
     4
   2   6
  1 3 5 7

  Output:
  InOrder   - 1 2 3 4 5 6 7
  PreOrder  - 4 2 1 3 6 5 7 
  PostOrder - 1 3 2 5 7 6 4
*/

int main () {
  int n;
  Tree tree;

  cin >> n;

  for (size_t i = 0; i < n; ++i) {
    int value;
    cin >> value;
    tree.insert(value);
  }

  cout << "InOrder: ";
  auto ordered_elements = tree.inOrder();
  for (auto element : ordered_elements) {
    cout << element << ' ';
  }

  cout << "\nPreOrder: ";
  auto pre_ordered_elements = tree.preOrder();
  for (auto element : pre_ordered_elements) {
    cout << element << ' ';
  }

  cout << "\nPostOrder: ";
  auto post_ordered_elements = tree.postOrder();
  for (auto element : post_ordered_elements) {
    cout << element << ' ';
  }
}