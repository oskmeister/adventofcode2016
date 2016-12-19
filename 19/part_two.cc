#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int solve_fast(int n) {
    n -= 2;
    int at = 0;
    int pow = 1;
    for (;;) {
        if (at + pow*2 > n) break;
        at += pow * 2;
        pow *= 3;
    }
    n -= at;
    if (n < pow) return n;
    return (pow - 1) + 2 * (n - at);
}

int solve_slow(int n) {
    vector<int> v(n, 1);
    int at = 0;
    int left = n;
    for (;;) {
        if (v[at] > 0) {
            int next = at;
            int seen = 0;
            while (seen < left / 2) {
                if (v[next]) ++seen;
                next = (next + 1) % n;
            }
            while (!v[next]) next = (next + 1) % n;
            v[next] = 0;
            --left;
        }
        at = (at + 1) % n;
        if (left == 1) break;
    }
    return (max_element(v.begin(), v.end()) - v.begin());
}

int main() {
/*
    // Run some tests
    for (int i = 2; i <= 1000; ++i) {
        assert(solve_fast(i) == solve_slow(i));
    }
*/
    int n;
    cin >> n;

    cout << solve_fast(n)+1 << endl;
}
