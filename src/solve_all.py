from sudoku_io import *
from grid import Sudoku
from backtracking import solve
import time
import sys

def read_name():
    name = sys.stdin.readline()
    if not name:
        return None
    name = name.strip()
    if name:
        return name
    return read_name()

ex_times = []
while True:
    name = read_name()
    if not name:
        break

    raw_puzzle = read_sudoku()
    p = Sudoku(raw_puzzle)
    # p.print()

    start_time = time.time()
    solve(p)
    time_sec = time.time() - start_time
    print(f'Solved {name} in {time_sec:.4f} sec.')
    # p.print()
    ex_times.append(time_sec)

print(f"Average time is {sum(ex_times) / len(ex_times):.4f} sec.")
print(f"Longest time is {max(ex_times):.4f} sec.")
