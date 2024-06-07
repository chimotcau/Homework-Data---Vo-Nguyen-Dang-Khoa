#include <cstdint>
#include <iostream>
#include <vector>
void countingSort(std::vector<unsigned long long>& arr, unsigned int byteNum) {
  std::vector<int> count(256, 0);
  for (unsigned long long num : arr) {
    unsigned char byte = (num >> (byteNum * 8)) & 0xFF;
    count[byte]++;
  }

  for (int i = 1; i < 256; ++i) {
    count[i] += count[i - 1];
  }

  std::vector<unsigned long long> result(arr.size());
  for (int i = arr.size() - 1; i >= 0; --i) {
    unsigned char byte = (arr[i] >> (byteNum * 8)) & 0xFF;
    result[--count[byte]] = arr[i];
  }

  arr = result;
}

void radixSort(std::vector<unsigned long long>& arr) {
  for (unsigned int byteNum = 0; byteNum < sizeof(unsigned long long);
       ++byteNum) {
    countingSort(arr, byteNum);
  }
}

int main() {
  int N;
  std::cin >> N;

  std::vector<unsigned long long> arr(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  radixSort(arr);

  for (unsigned long long num : arr) {
    std::cout << num << std::endl;
  }

  return 0;
}