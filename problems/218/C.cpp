#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

bool check(long long burgers, int b, int s, int c, int bc, int sc, int cc,
           int pb, int ps, int pc, long long k) {
  k -= (max(0LL, burgers * bc - b) * pb);
  k -= (max(0LL, burgers * sc - s) * ps);
  k -= (max(0LL, burgers * cc - c) * pc);
  return k >= 0;
}

void solve() {
  string recipe;
  cin >> recipe;
  int b, s, c;
  cin >> b >> s >> c;
  int pb, ps, pc;
  cin >> pb >> ps >> pc;
  long long k;
  cin >> k;

  int bc = 0;
  int sc = 0;
  int cc = 0;

  for (auto x : recipe) {
    switch (x) {
    case 'B':
      ++bc;
      break;
    case 'S':
      ++sc;
      break;
    case 'C':
      ++cc;
      break;
    }
  }

  long long l = 0;
  long long r = 10000000000000LL;

  long long res = -1;

  while (l <= r) {
    long long m = r + (l - r) / 2;
    if (check(m, b, s, c, bc, sc, cc, pb, ps, pc, k)) {
      res = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--)
  solve();

  return 0;
}
