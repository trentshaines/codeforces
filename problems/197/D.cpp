#include <algorithm>
#include <bit>
#include <cassert>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;

void construct_layer(vector<int> &tree, int layer, bool is_or) {
  int start = pow(2, layer);
  int end = start * 2;

  for (int i = start; i < end; ++i) {
    tree[i] = (is_or) ? (tree[i * 2] | tree[i * 2 + 1])
                      : (tree[i * 2] ^ tree[i * 2 + 1]);
  }
}

// [l, r)
int query(vector<int> &tree, int root, int l, int r, int p, int b) {
  // find which side has the edit, or or xor it.
  int mid = r + (l - r) / 2;
  bool is_or = (31 - __builtin_clz((unsigned int)r - l)) % 2 == 1;
  // cout << p << " " << b << ":" << l << " " << r - 1 << "\n";

  int root_val;
  if (r == l + 1) {
    assert(l == p);
    root_val = b;
  } else if (p >= mid) {
    int next_query = query(tree, root * 2 + 1, mid, r, p, b);
    root_val =
        is_or ? (tree[root * 2] | next_query) : (tree[root * 2] ^ next_query);
  } else {
    int next_query = query(tree, root * 2, l, mid, p, b);
    root_val = is_or ? (tree[root * 2 + 1] | next_query)
                     : (tree[root * 2 + 1] ^ next_query);
  }

  tree[root] = root_val;
  return root_val;
}

void solve() {
  int n;
  cin >> n;

  int m;
  cin >> m;

  // construct tre
  // Ignore element 0.
  int offset = pow(2, n);
  int tree_size = offset * 2;
  vector<int> tree(tree_size, 0);

  // construct leaves
  for (int i = offset; i < tree_size; ++i) {
    cin >> tree[i];
  }

  // construct layers
  bool is_or = true;
  for (int i = n - 1; i >= 0; --i) {
    construct_layer(tree, i, is_or);
    is_or = !is_or;
  }

  // query through layers
  while (m--) {
    int p, b;
    cin >> p >> b;
    --p;

    int res = query(tree, 1, 0, offset, p, b);
    cout << res << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
