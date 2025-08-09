#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;



long long next_higher_msb(long long val){
    if (val <= 0) return 1;
    int msb_index = 63 - __builtin_clzll(val); // 0-based index of MSB
    return 1LL << (msb_index + 1);
}

void solve() {
    // Create an array of length N using numbers between l, r
    // If a bit is always set, then it must be set an odd number of times
    // If a bit is NOT always set, it must be set an even number of times.

    // the output should always assign the minimum possible number left to right
    // can we consider each bit? 
        // for MSB, 
        // to minimize the sequence, should we attempt to set or not set the bit
        // this depends on the range, but it si greedy?
        // we can repeat numbers

    // if N is odd, we can just set the minimum number n times -> always set each bit an odd number
    // otherwise, there will be no way to always set a bit an odd number of times.
        //  we need to find a way to set each individual bit an even number with minimum assignment
    // we can take L N-2 times then find the next number that has no overlapping bits with L (i.e ceil log), and take it twice? 
        // if the ceil log is > R, what to do?
        // no solution

    long long n; long long l; long long r; long long k;
    cin >> n >> l >> r >> k;

    if (n == 2){
        cout << -1 << "\n";
        return;
    }

    if (n % 2 == 1){
        cout << l << "\n";
        return;
    }

    long long next = next_higher_msb(l);
    // cout << "msb:" << next << " ";
    if(next > r){
        cout << -1 << "\n";
        return;
    }

    if (k > n-2){
        cout << next << "\n";
        return;
    }

    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
} 