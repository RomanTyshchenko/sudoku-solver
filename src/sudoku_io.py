def read_sudoku():
    puzzle = []
    for i in range(9):
        row = [int(x) for x in input().split()]
        puzzle.append(row)
    return puzzle


def pretty_print(puzzle):
    sep_row = ('+' + ('-' * (3 + 4)) ) * 3 + '+'
    print(sep_row)
    for i, row in enumerate(puzzle):
        chars = ['|']
        for j in range(3):
            chars.extend(str(d) if d > 0 else ' ' for d in row[3*j:3*j+3])
            chars.append('|')
        print(' '.join(chars))
        if i % 3 == 2:
            print(sep_row)

