#include "sudoku.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  Sudoku s;
  cin >> s;

  cout << s;
  if (s.solve()) {
    cout << "Solved:\n";
    cout << s;
  } else {
    cout << "Can't solve this :(\n";
  }
  return 0;
}
