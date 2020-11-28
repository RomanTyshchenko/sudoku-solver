def solve(p):
    return solve_at(p, 0, 0)

def solve_at(p, row, col):
    if row == 9:
        return True  # reached the end done
    next_row, next_col = next_cell(row, col)
    if p.at(row, col):  # skip filled cells
        return solve_at(p, next_row, next_col)
    else:
        valid_digits = p.valid_digits(row, col)
        if not valid_digits:
            return False
        for dig in valid_digits:
            p.set(row, col, dig)
            if solve_at(p, next_row, next_col):
                return True
        p.reset(row, col)
        return False

def next_cell(row, col):
    if col == 8:
        return row + 1, 0
    return row, col + 1
