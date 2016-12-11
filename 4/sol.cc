#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ans = 0;
    for (;;) {
        string message;
        int number;
        string code;
        if (!(cin >> message)) break;
        cin >> number >> code;

        for (char c : message) {
            int ci = c;
            cout << char(int('a') + ((ci - int('a') + number) % 26));
        }
        cout << " " << number << endl << endl;

        /*
        vector<pair<int,char>> v;
        for (int i = 0; i < 26; ++i) {
            v.push_back(make_pair(count[i], i)); 
        }

        string most_common;
        sort(v.begin(), v.end());
        for (int i = 0; i < 5; ++i) {
            if (v[i].first < 0)
                most_common.push_back(v[i].second + 'a');
        }

        cout << most_common << endl;
        if (most_common == code) ans += number;
        */
    }
    cout << ans << endl;
}
