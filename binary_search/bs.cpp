#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& v, int value) {
  int i = 0, f = v.size() - 1, m;

  while (f - i > 1) {
    m = (i + f) / 2;

    cout << "i: " << i << "\tm: " << m << "\tf: " << f << endl;

    if (value == v[m]) return m;
    if (value > v[m]) i = m;
    if (value < v[m]) f = m;
  }

  if (value == v[i]) return i;
  if (value == v[f]) return f;

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