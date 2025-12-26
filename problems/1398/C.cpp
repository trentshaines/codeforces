#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;

  unordered_map<int, int> prefix_diff;
  long long cur = 0;
  long long sum = 0;

  prefix_diff[1] = 1;
  for (int i = 0; i < n; ++i) {
    int x = a[i] - '0';
    cur += x;
    sum += prefix_diff[cur - i - 1]++;
  }

  cout << sum << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
