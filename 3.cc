#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const vector<int> v) {
    int sum = accumulate(v.begin(), v.end(), 0);
    bool ok = true;
    for (int c : v) {
        if (sum - c <= c) ok = false;
    }
    return ok;
}

int main() {
    vector<vector<int>> input;
    for (;;) {
        int a, b, c;
        if (!(cin >> a)) break;
        cin >> b >> c;
        vector<int> row = {a,b,c};
        input.push_back(row);
    }
    int ans = 0;
    for (int i = 0; i < input.size(); i += 3) {
        for (int j = 0; j < 3; ++j) {
            ans += is_valid({input[i][j], input[i+1][j], input[i+2][j]});
        }
    }
    cout << ans << endl;
}
