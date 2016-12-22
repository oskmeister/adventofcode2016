#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string rotate(string &s, int offset) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
        result.push_back(s[(i + offset + s.size() * 10) % s.size()]);
    }
    return result;
}

string rotate_based(string &s, char c) {
    size_t index = s.find(c);
    int amount = (index >= 4 ? index + 1 : index) + 1;
    return rotate(s, -amount);
}

int main(int argc, char *argv[]) {
    string cur(argv[1]);
    string word;
    while (cin >> word) {
        if (word == "rotate") {
            string word2;
            cin >> word2;
            if (word2 == "based") {
                cin >> word2 >> word2 >> word2 >> word2;
                char c; 
                cin >> c;
                cur = rotate_based(cur, c);
            } else if (word2 == "left") {
                int amount;
                cin >> amount >> word2;
                cur = rotate(cur, amount);
            } else {
                int amount;
                cin >> amount >> word2;
                cur = rotate(cur, -amount);
            }
        } else if (word == "swap") {
            string word2;
            cin >> word2;
            if (word2 == "position") {
                int from, to;
                cin >> from >> word2 >> word2 >> to;
                swap(cur[from],cur[to]);
            } else {
                char a, b;
                cin >> a >> word2 >> word2 >> b;
                size_t p_a = cur.find(a);
                size_t p_b = cur.find(b);
                swap(cur[p_a], cur[p_b]);
            }
        } else if (word == "reverse") {
            int from, to;
            cin >> word >> from >> word >> to;
            std::reverse(cur.begin() + from, cur.begin() + to + 1);
        } else if (word == "move") {
            string word2;
            int from, to;
            cin >> word2 >> from >> word2 >> word2 >> to;
            const char moved = cur[from];
            cur.erase(cur.begin() + from);
            cur.insert(to, 1, moved);
        }
    }
    cout << cur << endl;
}
