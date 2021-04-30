# sudoku-solver
Solve Sudoku puzzles with rule based and backtracking approaches.

## Why?
It's interesting how hard it can be to solve sudoku only with rule based approach.

## The plan
- Find and add to this repo several sudoku puzzles with different difficulty levels (easy to expert) for testing purposes.
- Check whether backtracking alone will work in reasonable time.
- Add solving rules similar how I would solve it and check how far can I go (medium/hard) without backtracking.
- Add text based UI?

## Puzzles
The first set of puzzled I will take from 
http://lipas.uwasa.fi/~timan/sudoku/
because they are in text format which will be easy to read.
I would like to add more example later.

## First real commit
I've just made my first commit from terminal.
I added a puzzles directory with files from the site above.
1. copied names from the site + echo + grep txt
2. bash loop with wget over filenames
3. git add directory
4. git commit
5. git push # entered my credentials
and done)

## First code
Another commit: now with some code.
I can read/write sudoku puzzles, which is kind of nice.

## Backtracking
My backtracking solution works much better than I expected.
I thought that it won't solve anything in resonable time.
But it solved most puzzled well under 1 sec, the longest one took 3.4 sec.
I updated run.sh script to run solution over all puzzles.

## Measurements
How fast is Python vs C++ or Raspberry Pi vs Intel Xeon?

Measurements below are done running ./timeit.sh script.
All times are in seconds.

- RapsPi - Raspberry Pi 4 (Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.5GHz)
- S9 - Galaxy S9 Qualcomm Snapdragon 845 (Octa-core 4×2.8 GHz & 4×1.7 GHz)
- MBP - MacBook Pro 2015 (2.5GHz Intel Core i7-4870HQ)
- Pixelbook - Pixelbook Go from linux virtual machine (Intel Core i5 8th Gen)
- ThinkCentre - tiny ThinkCentre M93p under WSL on Windows (Intel i5-4570T 2.9 GHz up to 3.6 GHz)
- Xeon - linux workstation with Intel Xeon processor (turbo speed is over 4GHz).

Longest time:
Solution | RaspPi | S9 | MBP | Pixelbook | ThinkCentre | Xeon
----     | ----   |--- | --- | ---       | ---------   | ---
C++ -O2  | 0.65   |0.19| 0.54| 0.15      | 0.13        | 0.10
C++      | 5.4    | 5.9| 1.4 | 1.5       | 1.22        | 0.96
Python3  | 13.2   | 7.7| 3.7 | 3.1       | 2.8         | 1.7

Average time:
Solution | RaspPi  | S9 | MBP | Pixelbook | ThinkCentre |  Xeon 
----     | ----    | -- | --- | ---       | ---         | ---
C++ -O2  | 0.033  |0.012|0.027| 0.008     | 0.007       | 0.005
C++      | 0.27    | 0.3| 0.07| 0.08      | 0.06        | 0.05
Python3  | 0.66    |0.39|0.19 | 0.16      | 0.14        | 0.08

Summary:
- Old MacBook Pro is slow: slower than Pixelbook and S9 for running optimized C++. Maybe 4th gen intel i7 is so slow or ...
- Don't forget to turn on compiler optimization if you write C++ code, it's 10x faster.
- I was impressed how easy on Android phone with Termux to run git, python3, g++, bash.

## Next
Rule based approach which mimic how I would solve it myself.

## How to
### Clone repository
```bash
$ git clone https://github.com/RomanTyshchenko/sudoku-solver.git
```

### Run timing test
```bash
cd sudoku-solver
./timeit.sh
```

### Install C++ (if needed)
```bash
sudo apt-get install g++
```
