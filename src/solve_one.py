from sudoku import Sudoku
import time

p = Sudoku()
p.read_stdin()
print(p)

start_time = time.time()
ok = p.solve()
exe_time_sec = time.time() - start_time
if ok:
    print(f'Solution was found in {exe_time_sec:.3f} sec:')
    print(p)
else:
    print('Sorry, cannot solve it.')

