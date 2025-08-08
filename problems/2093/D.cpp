#include <iostream>
#include <utility>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;


// 1 4
// 3 2 

// to find the value:
    // find what quadrant we are in, add the offset, then recurse?
long long findValue(int n, int x, int y){
    if (n == 0) return 1;  // Base case
    // we range from 1 -> 2^n == 1 << (n)
    // just check if the bit is set.
    int q = 0;
    if(x & (1LL << (n-1))){
        q = 2;
    }
    if(y & (1LL << (n-1))){
        if (q == 2)
            q = 1;
        else
            q = 3;
    }
    // cout << "x " << x << " ";
    x &= ((1LL << (n-1)) - 1);  
    // cout << "y " << x << " ";
    y &= ((1LL << (n-1)) - 1);
    
    return q * (1LL << (n*2-2)) + findValue(n-1, x, y);
}

// to find the coordinate:
    // find the remainder of power of four, find which quadrant is last, recurse?
pair<int, int> findCoord(int n, long long value){
    if(n == 0) return make_pair(1,1);
    long long q = value / (1LL << (n*2-2));
    long long r = value % (1LL << (n*2-2)); 
    
    auto [x, y] = findCoord(n-1, r);
    if(q == 2 || q == 1)
        x += (1LL << (n-1));
    if(q == 3 || q == 1)
        y += (1LL << (n-1));

    return make_pair(x, y);
}

void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;

    // classic problem format, ex fibbonacci tree type where you need to turn a recursive problem into something a bit explicit

    // can DP be useful? I guess, but not cleanly?
    // 30 * 20k
    while(q--)
    {
        string sym;
        cin >> sym;
        if (sym == "->") {
            int x, y;
            cin >> x >> y;
            cout << findValue(n, x-1, y-1) << "\n";
        }
        else if (sym == "<-") {
            int v;
            cin >> v;
            auto [x, y] = findCoord(n, v-1);
            cout << x << " " << y << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
} 