#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

void solve() {
  int n;
  cin >> n;

  long long left_splits = 0;
  long long res = 0;

  vector<long long> prefix(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    prefix[i] = prefix[i - 1] + x;
  }

  long long total = prefix[n];
  if (total % 3 != 0 || n < 3) {
    cout << 0 << "\n";
    return;
  }

  for (int i = 1; i < n; ++i) {
    if (prefix[i] == total * 2 / 3) {
      res += left_splits;
    }

    if (prefix[i] == total / 3) {
      left_splits++;
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
