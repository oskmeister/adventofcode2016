#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
    LL a, b;
    vector<pair<LL, int>> e;
    while (scanf("%lld-%lld", &a, &b) == 2) {
        pair<LL,int> start(a, -1);
        pair<LL,int> end(b, 1);
        e.push_back(start); e.push_back(end);
    }
    sort(e.begin(), e.end());
    LL blocked_numbers = 0;
    LL prev = -1;
    LL last_counted = -1;
    int open = 0;
    for (auto p : e) {
        if (open == 0) {
            // First point on interval. Add it.
            ++blocked_numbers;
        }
        if (open && prev != -1) {
            // Accumulate.
            blocked_numbers += p.first - prev;
        }
        open += p.second;
        prev = p.first;
    }
    cout << 4294967296LL - blocked_numbers << endl;
}
