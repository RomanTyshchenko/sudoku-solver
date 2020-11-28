from sudoku_io import *
from grid import Sudoku
from backtracking import solve
import time

raw_puzzle = read_sudoku()

p = Sudoku(raw_puzzle)
p.print()

start_time = time.time()
if solve(p):
    exe_time_sec = time.time() - start_time
    print(f'Solution was found in {exe_time_sec:.3f} sec:')
    p.print()
    print()
else:
    print('Sorry, cannot solve it.')

