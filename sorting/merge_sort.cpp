#include <vector>
#include <iostream>

using namespace std;

vector<int> merge (const vector<int>& A, const vector<int>& B) {
  vector<int> C;

  size_t iA = 0, iB = 0;
  while (iA < A.size() && iB < B.size()) {
    if (A[iA] < B[iB]) {
      C.push_back(A[iA]);
      iA++;
    }
    else {
      C.push_back(B[iB]);
      iB++;
    }
  }

  while (iA < A.size()) C.push_back(A[iA++]);
  while (iB < B.size()) C.push_back(B[iB++]);

  return C;
}


vector<int> sort (const vector<int>& elements) {
  if (1 == elements.size()) return elements;
  else {
    vector<int> A, B;
    for(size_t i = 0; i < elements.size() / 2; i++) {
      A.push_back(elements[i]);
      B.push_back(elements[elements.size() / 2 + i]);
    }
    return merge(sort(A), sort(B));
  }
}

int main () {
  int n, element;
  cin >> n;

  vector<int> elements;
  for(size_t i = 0; i < n; i++) {
    cin >> element;
    elements.push_back(element);
  }

  vector<int> sorted_elements = sort(elements);
  for(auto element : sorted_elements) {
    cout << element << ' ';
  }

  return 0;
}