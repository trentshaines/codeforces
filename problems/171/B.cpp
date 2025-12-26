#include <algorithm>
#include <array>
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
  int t;
  cin >> t;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int l = 0;
  int r = 0;
  int res = 0;
  int sum = 0;

  while (r < n) {
    while (r < n && (sum + a[r]) <= t) {
      sum += a[r++];
    }

    // inclusive, exclusive
    res = max(res, r - l);

    sum -= a[l++];
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
