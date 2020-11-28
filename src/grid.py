class Sudoku:
    def __init__(self, grid):
        self.grid = grid  # 9x9 matrix with 0 for empty cells

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
        vd = set(range(1,10))
        for dig in self.row(row):
            vd.discard(dig)
        for dig in self.column(col):
            vd.discard(dig)
        for dig in self.square(row, col):
            vd.discard(dig)
        return sorted(vd)

    def row(self, row):
        return self.grid[row]

    def column(self, col):
        return [self.grid[ri][col] for ri in range(9)]

    def square(self, row, col):
        sr = 3 * (row // 3)
        sc = 3 * (col // 3)
        return [self.grid[i][j] for i in range(sr, sr+3) \
                                    for j in range(sc, sc+3)]

    def print(self):
        from sudoku_io import pretty_print
        pretty_print(self.grid)

