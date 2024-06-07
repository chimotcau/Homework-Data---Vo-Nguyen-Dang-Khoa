#include <iostream>
bool BinarySearch(const int* start, const int* end, int target) {
  while (start < end) {
    const int* mid = start + (end - start) / 2;
    if (*mid == target) {
      return true;
    }
    if (*mid > target) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return false;
}
int main() {
  int numElements, numQueries;
  std::cin >> numElements;
  int* array = new int[numElements];
  for (int index = 0; index < numElements; ++index) {
    std::cin >> array[index];
  }
  std::cin >> numQueries;
  for (int query = 0; query < numQueries; ++query) {
    int startIndex, endIndex, target;
    std::cin >> startIndex >> endIndex >> target;
    if (BinarySearch(array + startIndex, array + endIndex, target)) {
      std::cout << "Yes" << '\n';
    } else {
      std::cout << "No" << '\n';
    }
  }
  delete[] array;
  return 0;
}
