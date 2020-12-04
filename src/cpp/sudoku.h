#include <vector>
#include <iostream>

class Sudoku {
 private:
  std::vector<std::vector<int>> grid;
  using mask = int;
  std::vector<mask> used_in_row;
  std::vector<mask> used_in_col;
  std::vector<mask> used_in_square;

 public:
  Sudoku()
    : grid(9, std::vector<int>(9, 0))
    , used_in_row(9)
    , used_in_col(9)
    , used_in_square(9) {}

  Sudoku(const std::vector<std::vector<int>>& grid_)
    : grid(grid_)
    , used_in_row(9)
    , used_in_col(9)
    , used_in_square(9) {
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
	if (auto dig = grid[r][c]; dig > 0) {
	  // Fills used_*
	  set(r, c, dig);
	}
      }
    }
  }

  bool solve() {
    return solve_at(0, 0);
  }

  const std::vector<int>& operator[](std::size_t i) const {
    return grid[i];
  }

  void set(int row, int col, int dig) {
    if (dig > 0) {
      used_in_row[row] += (1 << dig);
      used_in_col[col] += (1 << dig);
      used_in_square[square_index(row, col)] += (1 << dig);
    }

    grid[row][col] = dig;
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
    mask used_digs = used_in_row[row] |
      used_in_col[col] |
      used_in_square[square_index(row, col)];
    for (int dig = 1; dig <= 9; ++dig) {
      if (((1 << dig) & used_digs) == 0) {
	set(row, col, dig);
	if (solve_at(nrow, ncol)) {
	  return true;
	}
	reset(row, col);
      }
    }
    return false;
  }
  
  bool is_filled(int row, int col) const {
    return grid[row][col] > 0;
  }

  void reset(int row, int col) {
    int dig = grid[row][col];
    grid[row][col] = 0;

    used_in_row[row] -= (1 << dig);
    used_in_col[col] -= (1 << dig);
    used_in_square[square_index(row, col)] -= (1 << dig);
  }

  int square_index(int row, int col) const {
    return (row / 3) * 3 + (col / 3);
  }
};


std::istream& operator>>(std::istream& is, Sudoku& s) {
  int dig = 0;
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      is >> dig;
      s.set(r, c, dig);
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Sudoku& s) {
  for (int i = 0; i < 9; ++i) {
    for (int d : s[i]) {
      os << d << ' ';
    }
    os << "\n";
  }
  return os;
}
