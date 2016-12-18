#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const string INPUT = ".^^^.^.^^^^^..^^^..^..^..^^..^.^.^.^^.^^....^.^...^.^^.^^.^^..^^..^.^..^^^.^^...^...^^....^^.^^^^^^^";

int main() {
    const int num_rows = 400000;
    const int num_cols = INPUT.length();

    int ans = 0;
    { 
        vector<bool> v(num_cols, false);
        for (int i = 0; i < num_cols; ++i) v[i] = INPUT[i] == '.';
        ans += count(v.begin(), v.end(), true);
        for (int i = 1; i < num_rows; ++i) {
            auto v2 = v;
            for (int j = 0; j < num_cols; ++j) {
                const bool a = j > 0 ? v[j-1] : true;
                const bool b = j < num_cols - 1 ? v[j+1] : true;
                v2[j] = a == b;
            }
            ans += count(v2.begin(), v2.end(), true);
            swap(v2, v);
        }
    }
    cout << ans << endl;
}
