#include <iostream>
bool BinarySearch(const int* begin, const int* end, int target) {
  while (begin < end) {
    const int* mid = begin + (end - begin) / 2;
    if (*mid == target) {
      return true;
    }
    if (*mid > target) {
      end = mid;
    } else {
      begin = mid + 1;
    }
  }
  return false;
}
int main() {
  int N, Q;
  std::cin >> N;
  int* arr = new int[N];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }
  std::cin >> Q;
  for (int k = 1; k <= Q; k++) {
    int i, j, t;
    std::cin >> i >> j >> t;
    if (BinarySearch(arr + i, arr + j, t)) {
      std::cout << "Yes" << '\n';
    } else {
      std::cout << "No" << '\n';
    }
  }
  delete[] arr;
  return 0;
}
