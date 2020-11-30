#include "sudoku.h"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int main() {
  std::string name;
  double d_sum = 0, d_max = 0;
  int cnt = 0;
  while (cin >> name) {
    Sudoku s;
    cin >> s;

    // cout << s;
    auto t1 = chrono::high_resolution_clock::now();
    s.solve();
    auto t2 = chrono::high_resolution_clock::now();
    auto d_ms = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
    double d_sec = d_ms / 1.e6;
    cout << "Solved " << name << " in " << d_sec << " sec." << endl;
    
    d_max = max(d_sec, d_max);
    d_sum += d_sec;
    cnt++;
  }
  cout << "Average time: " << d_sum / cnt << " sec." << endl;
  cout << "Longest time: " << d_max << " sec." << endl;
  return 0;
}
