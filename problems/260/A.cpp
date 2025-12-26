// Alex doesn't like boredom. That's why whenever he gets bored, he comes up
// with games. One long winter evening he came up with a game and decided to
// play it. Given a sequence a consisting of n integers. The player can make
// several steps. In a single step he can choose an element of the sequence
// (let's denote it ak) and delete it, at that all elements equal to ak + 1 and
// ak - 1 also must be deleted from the sequence. That step brings ak points to
// the player. Alex is a perfectionist, so he decided to get as many points as
// possible. Help him.

// We really have buckets. If we want to take a number, we can take all the
// numbers of that value as well This is a DP problem, each number is take or
// skip. House robber leetcode.

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

  array<int, MAX_N> counts{};
  while (n--) {
    int x;
    cin >> x;
    counts[x]++;
  }

  long long take = 0;
  long long skip = 0;
  for (int i = 0; i < MAX_N; ++i) {
    long long next_take = max(skip + (long long)counts[i] * i, take);
    skip = take;
    take = next_take;
  }

  cout << take << "\n";
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
