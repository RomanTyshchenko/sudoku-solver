class Sudoku:
    def __init__(self, grid):
        self.grid = grid  # 9x9 matrix with 0s for empty cells

    def __init__(self):
        # 9x9 matrix with 0s for empty cells
        self.grid = [[0 for c in range(9)] for r in range(9)]

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

    def read_stdin(self):
        self.grid = []
        for i in range(9):
            row = [int(x) for x in input().split()]
            self.grid.append(row)

    def __str__(self):
        lines = []
        sep_row = ('+' + ('-' * (3 + 4)) ) * 3 + '+'
        lines.append(sep_row)
        for i, row in enumerate(self.grid):
            chars = ['|']
            for j in range(3):
                chars.extend(str(d) if d > 0 else ' ' for d in row[3*j:3*j+3])
                chars.append('|')
            lines.append(' '.join(chars))
            if i % 3 == 2:
                lines.append(sep_row)
        return '\n'.join(lines)

    def solve(self):
        return self._solve_at(0, 0)

    def _solve_at(self, row, col):
        if row == 9:
            return True  # reached the end done
        next_row, next_col = self._next_cell(row, col)
        if self.at(row, col):  # skip filled cells
            return self._solve_at(next_row, next_col)
        else:
            valid_digits = self.valid_digits(row, col)
            if not valid_digits:
                return False
            for dig in valid_digits:
                self.set(row, col, dig)
                if self._solve_at(next_row, next_col):
                    return True
            self.reset(row, col)
            return False

    @staticmethod
    def _next_cell(row, col):
        if col == 8:
            return row + 1, 0
        return row, col + 1
