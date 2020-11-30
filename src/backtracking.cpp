#include <iostream>
#include <vector>

using namespace std;

class Sudoku {
 public:
  Sudoku(const vector<vector<int>>& grid_):grid(grid_) {}

  bool is_filled(int row, int col) const {
    return grid[row][col] > 0;
  }

  void set(int row, int col, int dig) {
    grid[row][col] = dig;
  }

  void reset(int row, int col) {
    grid[row][col] = 0;
  }

  vector<int> valid_digits(int r, int c) const {
    vector<int> is_valid(10, 1);
    for (int d : row(r))
      is_valid[d] = 0;
    for (int d : column(c))
      is_valid[d] = 0;
    for (int d : square(r, c))
      is_valid[d] = 0;
    vector<int> res;
    for (int d = 1; d <= 9; ++d) {
      if (is_valid[d]) {
        res.push_back(d);
      }
    }
    return res;
  }
  
  vector<int> row(int r) const {
    return grid[r];
  }

  vector<int> column(int col) const {
    vector<int> res(9);
    for (int r = 0; r < 9; ++r) {
      res[r] = grid[r][col];
    }
    return res;
  }

  vector<int> square(int row, int col) const {
    vector<int> res;
    int sr = 3 * (row / 3);
    int sc = 3 * (col / 3);
    for (int r = sr; r < sr + 3; ++r) {
      for (int c = sc; c < sc + 3; ++c) {
        res.push_back(grid[r][c]);
      }
    }
    return res;
  }

  void print() const {
    for (const auto& row : grid) {
      for (int d : row) {
        cout << d << ' ';
      }
      cout << "\n";
    }
  }

 private:
  vector<vector<int>> grid;
};

bool solve_at(Sudoku& s, int row, int col) {
  if (row == 9) {
    return true;  // reached the end
  }
  int nrow = row, ncol = col + 1;
  if (ncol == 9) {
    nrow++;
    ncol = 0;
  }
  if (s.is_filled(row, col)) {
    return solve_at(s, nrow, ncol);
  }
  auto valid_digs = s.valid_digits(row, col);
  for (int dig : valid_digs) {
    s.set(row, col, dig);
    if (solve_at(s, nrow, ncol)) {
      return true;
    }
  }
  s.reset(row, col);
  return false;
}

bool solve(Sudoku& s) {
  return solve_at(s, 0, 0);
}


int main() {
  vector<vector<int>> grid(9, vector<int>(9));
  for (auto& row : grid) {
    for (auto& dig : row) {
      cin >> dig;
    }
  }
  Sudoku s(grid);
  s.print();
  if (solve(s)) {
    cout << "Solved:\n";
    s.print();
  } else {
    cout << "Can't solve this :(\n";
  }
  return 0;
}
