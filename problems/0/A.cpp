/*

Robin meets a series of people, each carrying a certain amount of gold given by
the list `gold`. If a person has gold ≥ k, Robin takes all of it. If a person
has 0 gold, Robin gives them 1 gold—if he has any. Robin starts with 0 gold.
Return the number of people who receive gold from Robin.

Example 1:
gold = [2, 0], k = 2
Robin takes 2 gold from the first person and gives 1 gold to the second person.
People who receive gold: 1

Example 2:
gold = [3, 0, 0], k = 2
Robin takes 3 gold from the first person and gives 1 gold to the second and
third persons. People who receive gold: 2

Example 3:
gold = [0, 3, 0, 0, 0, 0], k = 2
Robin takes 3 gold from the second person and gives 1 gold to the 3rd, 4th, and
5th persons. The 6th person does not receive gold because Robin has none left.
People who receive gold: 3

Example 4:
gold = [5, 4], k = 5
Robin takes 5 gold from the first person, but gives none since the second person
is not poor (has 4 gold). People who receive gold: 0
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

int minSlimePathLength(vector<int> &a, int start, bool searchLeft) {
  long long sum = 0LL;
  unordered_set<int> values;
  int n = a.size();
  int end = searchLeft ? 0 : n - 1;
  int i = start;
  int startVal = a[start];
  // running sum > value we want to eat
  // non empty
  // everything is not the same

  while (i != end) {
    searchLeft ? --i : ++i;
    sum += a[i];
    values.insert(a[i]);
    // cout << "start" << start << " i" << i << " values size:" << values.size()
    // << " sum: " << sum << "\n";

    if (sum > startVal && (abs(i - start) == 1 || values.size() != 1)) {
      return abs(i - start);
    }
  }
  return 1e6;
  // int minSlimePathLength = 1e6;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    // search left
    int leftPath = minSlimePathLength(a, i, true);
    int rightPath = minSlimePathLength(a, i, false);
    int lowestPath = min(leftPath, rightPath);
    cout << (lowestPath == 1e6 ? -1 : lowestPath) << " ";
  }
  cout << "\n";
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
