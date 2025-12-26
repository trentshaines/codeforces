#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

void solve() {
  int n;
  int l;
  cin >> n >> l;
  vector<int> arr(n);
  for (auto &x : arr) {
    cin >> x;
  }
  sort(arr.begin(), arr.end());
  double best = max(arr[0], l - arr[n - 1]);
  for (int i = 1; i < n; ++i) {
    best = max(best, (arr[i] - arr[i - 1]) / 2.0);
  }
  cout << best << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
