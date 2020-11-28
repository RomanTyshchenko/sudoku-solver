from sudoku_io import *

puzzle = read_sudoku()
print('\n'.join(str(row) for row in puzzle))
print('\n')
pretty_print(puzzle)
