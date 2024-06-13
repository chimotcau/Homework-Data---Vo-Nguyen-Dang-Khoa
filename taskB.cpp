#include <iostream>
#include <vector>
void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
int Partition(std::vector<int>& elements, int low, int high) {
  int pivot = elements[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (elements[j] <= pivot) {
      ++i;
      Swap(elements[i], elements[j]);
    }
  }
  Swap(elements[i + 1], elements[high]);
  return i + 1;
}
int QuickSelect(std::vector<int>& elements, int low, int high, int k) {
  if (low <= high) {
    int partitionIndex = Partition(elements, low, high);
    if (partitionIndex == k) {
      return elements[partitionIndex];
    } else if (partitionIndex > k) {
      return QuickSelect(elements, low, partitionIndex - 1, k);
    } else {
      return QuickSelect(elements, partitionIndex + 1, high, k);
    }
  }
  return -1;  
}
int main() {
  int numElements, k, firstElement, secondElement;
  std::cin >> numElements >> k >> firstElement >> secondElement;
  std::vector<int> elements;
  elements.reserve(numElements);
  elements.push_back(firstElement);
  elements.push_back(secondElement);
  for (int index = 2; index < numElements; ++index) {
    int nextElement =
        (secondElement * 123 + firstElement * 45) % (10000000 + 4321);
    elements.push_back(nextElement);
    firstElement = secondElement;
    secondElement = nextElement;
  }
  int kthElement = QuickSelect(elements, 0, elements.size() - 1, k - 1);
  std::cout << kthElement << std::endl;
  return 0;
}
