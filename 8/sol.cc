#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> rotate(vector<vector<bool>> v, bool row, int index, int amount) {
    for (int i = 0; i < amount; ++i) {
        if (row) {
            rotate(v[index].begin(),v[index].begin()+49,v[index].end());
        } else {
            vector<bool> col;
            for (int j = 0; j < 6; ++j) {
                col.push_back(v[j][index]);
            }
            rotate(col.begin(),col.begin()+5,col.end());
            for (int j = 0; j < 6; ++j) {
                v[j][index] = col[j];
            }
        }
    }
    return v;
}

int main() {
    vector<vector<bool>> v(6, vector<bool>(50, false)); 
    string word;
    while (cin >> word) {
        if (word == "rect") {
            string dims;
            cin >> dims;
            int width, height;

            bool seen_x = false;
            int curnum = 0;
            for (char c : dims) {
                if (c == 'x') {
                    width = curnum;
                    seen_x = true;
                    curnum = 0;
                    continue;
                } 
                curnum = curnum * 10 + (c - '0');
            }
            height = curnum;
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c) {
                    v[r][c] = true;
                }
            }
        }
        if (word == "rotate") {
            string a;

            cin >> a;
            const bool is_row = a == "row";

            cin >> a;
            bool go = false;
            int index = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (go) {
                    index = index * 10 + (a[i] - '0');
                }
                if (a[i] == '=') go = true;
            }

            cin >> a;
            cin >> a;
            int amount = 0;
            for (char c : a) {
                amount = amount * 10 + (c - '0');
            }

            v = rotate(v, is_row, index, amount);
        }
    }

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 50; ++j) {
                cout << (v[i][j] ? '#' : ' ');
            }
            cout << endl;
        }
        cout << endl;

    int ans = 0;
    for (auto cur : v) {
        ans += accumulate(cur.begin(), cur.end(), 0);
    }
    cout << ans << endl;
}
