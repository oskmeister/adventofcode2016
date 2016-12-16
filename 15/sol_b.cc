#include <iostream>
#include <vector>

using namespace std;

int main() {
    string tmp;
    int n_pos, cur_pos;
    vector<int> totals, positions;
    int cur = 0;
    while (cin >> tmp) {
        cin >> tmp >> tmp >> n_pos >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> cur_pos >> tmp;
        totals.push_back(n_pos);
        positions.push_back(cur_pos);
        ++cur;
    }

    int t = 0; 
    for (;;) {
        bool ok = true;
        for (int i = 0; i < totals.size(); ++i) {
            int this_pos = (positions[i] + i + 1 + t) % totals[i]; 
            if (this_pos != 0) ok = false;
        }
        if (ok) break;
        ++t;
    }

    cout << t << endl;
}
