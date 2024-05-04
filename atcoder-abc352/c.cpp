#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

struct Giant {
  Giant(int new_A, int new_B) {
    A = new_A;
    B = new_B;
  }
  int A = 0;
  int B = 0;
  int HeadShoulDerdifference() {
    return B - A;
  }
};

class Comparator {
 public:
  bool operator()(Giant one, Giant two) {
    if (one.HeadShoulDerdifference() < two.HeadShoulDerdifference()) {
      return false;
    }
    return true;
  }
};

void DisplayQueue(priority_queue<Giant, vector<Giant>, Comparator> q){
  while (!q.empty()) {
    cout << q.top().A << ' ' << q.top().B << '\n';
    q.pop();
  }
}

int main() {
  int N = 0;
  cin >> N;
  int first_A;
  int first_B;
  cin >> first_A >> first_B;
  Giant first_giant(first_A, first_B);
  priority_queue<Giant, vector<Giant>, Comparator> giants;
  for (unsigned int i = 1; i < N; ++i) {
    int Ai = 0;
    int Bi = 0;
    cin >> Ai >> Bi;
    giants.emplace(Ai, Bi);

  }

  unsigned long long height = first_A;
  for (unsigned int i = 1; i < N - 1; ++i) {
    height+=giants.top().A;
    giants.pop();
  }
  height+= giants.top().B;
  giants.pop();
  cout << height << '\n';
}
