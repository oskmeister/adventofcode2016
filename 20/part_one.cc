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
    int open = 0;
    int prev_end = -1;
    for (auto p : e) {
        if (open == 0 && prev_end != -1 && prev_end < p.first-1) {
            cout << prev_end + 1 << endl;
            return 0;
        }
        open += p.second;
        if (p.second == 1) prev_end = p.first;
    }
}
