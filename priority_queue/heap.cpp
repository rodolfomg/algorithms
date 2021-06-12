#include <iostream>

using namespace std;

/**
  Max Heap
  Para cada nodo, la prioridad de sus hijos es menor que la del padre.

  insert: 9

            9
       8          6
    0     2    1     5
  -3 -4  0 1  _ _   _ _     

  left_child = parent * 2 + 1
  right_child = parent * 2 + 2
  parent = (child - 1) / 2

    0  1  2  3  4  5  6  7  8  9  10
  [ 9  8  6  0  2  1  5 -3 -4  0  1 ]
**/

// Max Heap
class Heap {
public:
  Heap(size_t size) : _last(0) {
    _data = make_unique<int[]>(size);
  };

  int top () {
    return _data[0];
  }

  Heap& insert (int value) {
    // Insert value in the most left available position in the last level
    _data[_last] = value;

    // Calculate Parent
    size_t current = _last++;
    size_t parent = (current - 1) / 2;

    // While new value has higher priority than parent => swap
    while (current && _data[current] > _data[parent]) {
      swap(_data[current], _data[parent]);
      current = parent;
      parent = (current - 1) / 2;
    }

    return *this;
  }

  /**
   *  Removes the top element from the Heap
   *
   *  Return: int - Highest priority element
   *
   *  Steps:
   *    - Swap root with last element
   *    - While current < left || right
   *      - if current < left && right
   *        - Swap current with max(left, right)
   *      - if current < left
   *        - Swap current with left
   *      - if current < right
   *        - Swap current with right
   *      - Update current
   *    - Return last element
   *
   *  [9, 8, 6, 0, 2, 1, 5, -3, -4, 0, 1]
   *  [-4, -3, 0, 0, 1, 1, 2, 5, 6, 8, 9]
  **/
  Heap& pop () {
    // Swap root with last element
    swap(_data[0], _data[_last - 1]);

    _last--;

    // While current < left || right
    size_t current = 0;

    auto highest_prio_child = [&] () {
      size_t left = current * 2 + 1;
      size_t right = current * 2 + 2;
      if (right >= _last) return left;
      return _data[left] > _data[right] ? left : right;
    };

    while (current * 2 + 1 < _last) {
      if (_data[current] < _data[highest_prio_child]) {
        swap(_data[current], _data[highest_prio_child]);
        current = highest_prio_child;
      }
      else break;
    }

    return *this;
  }

private:
  size_t _last;
  unique_ptr<int[]> _data;
};

int main(int argc, char const *argv[]) {
  Heap heap(10);

  cout << heap.insert(4).top() << endl;
  cout << heap.insert(10).top() << endl;
  cout << heap.insert(0).top() << endl;
  cout << heap.insert(24).top() << endl;

  return 0;
}