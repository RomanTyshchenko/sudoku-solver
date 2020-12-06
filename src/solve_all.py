from sudoku import Sudoku
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
    if not name:  # reached the end of the input
        break

    p = Sudoku()
    p.read_stdin()
    # p.print()

    start_time = time.time()
    ok = s.solve()
    time_sec = time.time() - start_time
    if not ok:
        print('The world is broken...')
        sys.exit()
    print(f'Solved {name} in {time_sec:.4f} sec.')
    # p.print()
    ex_times.append(time_sec)

print(f"Average time is {sum(ex_times) / len(ex_times):.4f} sec.")
print(f"Longest time is {max(ex_times):.4f} sec.")
