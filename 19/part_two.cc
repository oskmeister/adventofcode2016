#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
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
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) cout << "n = " << i << ": " << solve(i) << endl;
}
