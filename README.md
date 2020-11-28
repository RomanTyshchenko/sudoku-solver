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

## Next
Rule based approach which mimic how I would solve it myself.
