#include <iostream>
#include <set>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> cars;  
  for (int i = 0; i < n; ++i) {
    char op;
    int val;
    cin >> op >> val;
    if (op == '+') {
      cars.insert(val);  
    } else if (op == '?') {
      auto it = cars.lower_bound(val);  
      if (it != cars.end()) {
        cout << *it << endl;  
      } else {
        cout << -1 << endl;  
      }
    }
  }
  return 0;
}
