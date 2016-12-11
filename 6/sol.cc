#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> strings;
    string str;
    while (cin >> str) {
        strings.push_back(str);
    }
    
    for (int p = 0; p < strings[0].size(); ++p) {
        vector<int> cnt(26);
        for (const string &str : strings) {
            cnt[str[p] - 'a']++;
        }
        cout << char(int(min_element(cnt.begin(), cnt.end()) - cnt.begin()) + 'a');
    }
    cout << endl;
}
