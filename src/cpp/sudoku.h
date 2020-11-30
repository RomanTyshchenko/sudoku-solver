#include <vector>
#include <iostream>

class Sudoku {
 private:
  std::vector<std::vector<int>> grid;

 public:
  Sudoku(const std::vector<std::vector<int>>& grid_):grid(grid_) {}

  bool solve() {
    return solve_at(0, 0);
  }

  void print() const {
    for (const auto& row : grid) {
      for (int d : row) {
        std::cout << d << ' ';
      }
      std::cout << "\n";
    }
  }

 private:
  bool solve_at(int row, int col) {
    if (row == 9) {
      return true;  // reached the end
    }
    int nrow = row, ncol = col + 1;
    if (ncol == 9) {
      nrow++;
      ncol = 0;
    }
    if (is_filled(row, col)) {
      return solve_at(nrow, ncol);
    }
    auto valid_digs = valid_digits(row, col);
    for (int dig : valid_digs) {
      set(row, col, dig);
      if (solve_at(nrow, ncol)) {
        return true;
      }
    }
    reset(row, col);
    return false;
  }
  
  bool is_filled(int row, int col) const {
    return grid[row][col] > 0;
  }

  void set(int row, int col, int dig) {
    grid[row][col] = dig;
  }

  void reset(int row, int col) {
    grid[row][col] = 0;
  }

  std::vector<int> valid_digits(int r, int c) const {
    std::vector<int> is_valid(10, 1);
    for (int d : row(r))
      is_valid[d] = 0;
    for (int d : column(c))
      is_valid[d] = 0;
    for (int d : square(r, c))
      is_valid[d] = 0;
    std::vector<int> res;
    for (int d = 1; d <= 9; ++d) {
      if (is_valid[d]) {
        res.push_back(d);
      }
    }
    return res;
  }
  
  std::vector<int> row(int r) const {
    return grid[r];
  }

  std::vector<int> column(int col) const {
    std::vector<int> res(9);
    for (int r = 0; r < 9; ++r) {
      res[r] = grid[r][col];
    }
    return res;
  }

  std::vector<int> square(int row, int col) const {
    std::vector<int> res;
    int sr = 3 * (row / 3);
    int sc = 3 * (col / 3);
    for (int r = sr; r < sr + 3; ++r) {
      for (int c = sc; c < sc + 3; ++c) {
        res.push_back(grid[r][c]);
      }
    }
    return res;
  }
};


