#include <iostream>

using std::cin;
using std::cout;

int main() {
  unsigned int n = 0;
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;

  cin >> n >> x >> y >> z;

  if (y > x) {
    if (z > x && z <= y) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
    return 0;
  }

  if (y < x) {
    if (z >= y && z < x) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
    return 0;
  }

}
