#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int N;
  std::cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }
  std::sort(arr.begin(), arr.end());
  for (int i = 0; i < N; i++) {
    std::cout << " " << arr[i];
  }
  return 0;
}