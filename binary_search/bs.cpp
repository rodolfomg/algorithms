#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& v, int value) {
  int start = 0, finish = v.size() - 1, middle;

  while (finish - start > 1) {
    middle = (start + finish) / 2;
    if (value == v[middle]) return middle;
    if (value > v[middle]) start = middle;
    if (value < v[middle]) finish = middle;
  }

  if (value == v[start]) return start;
  return -1;
}

int main () {
  int n, num, value;
  
  cin >> n >> value;

  vector<int> v(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> v[i];
  }

  cout << binarySearch(v, value);
}