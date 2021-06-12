#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::make_unique;
using std::stack;
using std::unique_ptr;
using std::vector;

template <typename T>
class BTreeNode {
public:
  BTreeNode (T&& v) : _value(v), _left(nullptr), _right(nullptr) {}

  T value() {
    return value;
  }

  std::unique_ptr< BTreeNode<T> >& left () {
    return *_left;
  }

  std::unique_ptr< BTreeNode<T> >& right () {
    return *_right;
  }

  std::unique_ptr< BTreeNode<T> > linkToLeft (BTreeNode<T> node) {
    _left = std::unique_ptr< BTreeNode<T> > (std::move(node));
    return left();
  }

  std::unique_ptr< BTreeNode<T> > linkToRight (BTreeNode<T> node) {
    _right = std::unique_ptr< BTreeNode<T> > (std::move(node));
    return right();
  }

private:
  T _value;
  std::unique_ptr< BTreeNode<T> > _left, _right;
};

template <typename T>
class BTree {
public:
  BTree () : _root(nullptr), _size(0) {}

  BTree (T&& value) : _root(make_unique< BTreeNode<T> >(std::move(value))), _size(1) {}

  BTree (unique_ptr< BTreeNode<T> > root) : _root(std::move(root)) {
    _size = nullptr != _root ? getSize(*_root) : 0;
  }

  BTree (BTreeNode<T> root) : _root(std::move(root)) {
    _size = nullptr != _root ? getSize(*_root) : 0;
  }

  vector<T> dataPreOrder() {
    vector<T> data;

    if (nullptr == _root) return data;

    stack< BTreeNode<T>& > nodes;
    nodes.push(*_root);

    while (!nodes.empty()) {
      BTreeNode<T>& node = nodes.top();
      nodes.pop();
      data.emplace_back(node.value());
      if (nullptr != node.left()) nodes.push(node.left());
      if (nullptr != node.right()) nodes.push(node.right());
    }

    return data;
  }

  BTreeNode<T>& root() {
    return *_root;
  }

  size_t size () {
    return _size;
  }

  static unique_ptr< BTree<T> > interactiveConstructor() {
    char ans;
    cout << "Is an empty tree? y/n ";
    cin >> ans;

    if ('y' == ans) return make_unique< BTree<T> >();

    unique_ptr< BTreeNode<T> > root = make_unique< BTreeNode<T> >(requestNodeData());
    recursiveTreeGenerator(*root);

    return root;
  }

private:
  size_t getSize(BTreeNode<T>& node) {
    size_t size = 1;
    if (nullptr != node.left()) size += getSize(*node.left());
    if (nullptr != node.right()) size += getSize(*node.right());

    return size;
  }

  static BTreeNode<T> requestNodeData(){
    T value;
    cout << "Enter node value: ";
    cin >> value;

    return BTreeNode<T>(std::move(value));
  }

  static void recursiveTreeGenerator(unique_ptr< BTreeNode<T> >& node, int depth = 0) {
    char ans;
    cout << "Has " << node.value() << " a left child? (depth: " << depth << ") y/n ";
    cin >> ans;
    if ('y' == ans) {
      node.linkToLeft(requestNodeData());
      recursiveTreeGenerator(node.left(), depth + 1);
    }

    cout << "Has " << node.value() << " a right child?(depth: " << depth << ")  y/n ";
    cin >> ans;
    if ('y' == ans) {
      node.linkToRight(requestNodeData());
      recursiveTreeGenerator(node.right(), depth + 1);
    }
  }

  unique_ptr< BTreeNode<T> > _root;
  size_t _size;
};
