class Sudoku:
    def __init__(self, grid):
        self.grid = grid  # 9x9 matrix with 0s for empty cells

    def at(self, row, col):
        res = self.grid[row][col]
        return res if res > 0 else None

    def set(self, row, col, value):
        self.grid[row][col] = value

    def reset(self, row, col):
        self.grid[row][col] = 0

    def valid_digits(self, row, col):
        if self.at(row, col):
            return [self.at(row, col)]
        from itertools import chain
        used_digs = chain(self.row(row), self.column(col), self.square(row, col))
        used_digs = set(used_digs)
        return [dig for dig in range(1, 10) if dig not in used_digs] 

    def row(self, row):
        return self.grid[row]

    def column(self, col):
        return (row[col] for row in self.grid)

    def square(self, row, col):
        sr = 3 * (row // 3)
        sc = 3 * (col // 3)
        return (dig for row in self.grid[sr:sr+3] \
                        for dig in row[sc:sc+3])

    def print(self):
        from sudoku_io import pretty_print
        pretty_print(self.grid)

