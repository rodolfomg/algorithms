#include <iostream>
#include "btree.h"
// #include "int_btree.h"

using namespace std;

int main () {
  unique_ptr< BTree<int> > tree = BTree<int>::interactiveConstructor();

  BTree* root = BTree<int>::interactiveConstructor();

  // cout << tree->size() << endl;
  //
  // vector<int> data = tree->dataPreOrder();
  // for (size_t i = 0; i < tree->size(); i++) {
  //   cout << data[i] << ' ';
  // }


  // vector<int> values = { 4, 2, 25, 24, 13, 9, 7, 10, 14, 1 };
  // BSTree tree(values);

  // vector<int> result = tree.dataInOrder();
  // for (auto value : result) {
  //   cout << value << ' ';
  // }
  //
  // cout << '\n';
  // result = tree.dataPreOrder();
  // for (auto value : result) {
  //   cout << value << ' ';
  // }
  //
  // cout << '\n';
  // result = tree.dataPostOrder();
  // for (auto value : result) {
  //   cout << value << ' ';
  // }

  // 3
  cout << tree.distance(13) << '\n';

  // 5
  cout << tree.distance(10) << '\n';

  // 0
  cout << tree.distance(4) << '\n';

  // -1
  cout << tree.distance(12) << '\n';
}
