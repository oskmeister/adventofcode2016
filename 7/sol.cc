#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool a_z(char c) {
    return c >= 'a' && c <= 'z';
}

bool supports_tls(const string &str) {
    bool open = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '[') open = true;
        else if (str[i] == ']') open = false;
        else if (i + 2 < str.size()) {
            if (a_z(str[i]) && a_z(str[i+1]) && str[i] == str[i+2] && str[i] != str[i+1]) {
                if (!open) {
                    const char a = str[i];
                    const char b = str[i+1];
                    bool open_inner = false;
                    for (int j = i + 1; j < str.size(); ++j) {
                        if (str[j] == '[') open_inner = true;
                        else if (str[j] == ']') open_inner = false;
                        else if (open_inner && str[j] == str[j+2] && b == str[j] && a == str[j+1]) {
                            return true;
                        }
                    }
                } else {
                    const char a = str[i];
                    const char b = str[i+1];
                    bool open_inner = true;
                    for (int j = i + 1; j < str.size(); ++j) {
                        if (str[j] == '[') open_inner = true;
                        else if (str[j] == ']') open_inner = false;
                        else if (!open_inner && str[j] == str[j+2] && b == str[j] && a == str[j+1]) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int ans = 0;
    string input;
    while (cin >> input) {
        ans += supports_tls(input);
    }
    cout << ans << endl;
}
