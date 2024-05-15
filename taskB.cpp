#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int n, k, a0, a1;
  std::cin >> n >> k >> a0 >> a1;
  std::vector<int> elements;
  elements.reserve(n);
  elements.push_back(a0);
  elements.push_back(a1);
  for (int i = 2; i < n; ++i) {
    int new_one = (a1 * 123 + a0 * 45) % (10000000 + 4321);
    elements.push_back(new_one);
    a0 = a1;
    a1 = new_one;
  }
  std::nth_element(elements.begin(), elements.begin() + k - 1, elements.end());
  std::cout << elements[k - 1] << std::endl;
  return 0;
}