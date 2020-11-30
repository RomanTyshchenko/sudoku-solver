#include "sudoku.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> grid(9, vector<int>(9));
  for (auto& row : grid) {
    for (auto& dig : row) {
      cin >> dig;
    }
  }
  Sudoku s(grid);
  s.print();
  if (s.solve()) {
    cout << "Solved:\n";
    s.print();
  } else {
    cout << "Can't solve this :(\n";
  }
  return 0;
}
