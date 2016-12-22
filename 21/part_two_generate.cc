#include <algorithm>
#include <fstream>
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
    string a = "abcdefgh";
    do {
        string cur = a;
        string cp = cur;
        string word;
        ifstream file("test.mine");
        while (file >> word) {
            if (word == "rotate") {
                string word2;
                file >> word2;
                if (word2 == "based") {
                    file >> word2 >> word2 >> word2 >> word2;
                    char c; 
                    file >> c;
                    cur = rotate_based(cur, c);
                } else if (word2 == "left") {
                    int amount;
                    file >> amount >> word2;
                    cur = rotate(cur, amount);
                } else {
                    int amount;
                    file >> amount >> word2;
                    cur = rotate(cur, -amount);
                }
            } else if (word == "swap") {
                string word2;
                file >> word2;
                if (word2 == "position") {
                    int from, to;
                    file >> from >> word2 >> word2 >> to;
                    swap(cur[from],cur[to]);
                } else {
                    char a, b;
                    file >> a >> word2 >> word2 >> b;
                    size_t p_a = cur.find(a);
                    size_t p_b = cur.find(b);
                    swap(cur[p_a], cur[p_b]);
                }
            } else if (word == "reverse") {
                int from, to;
                file >> word >> from >> word >> to;
                std::reverse(cur.begin() + from, cur.begin() + to + 1);
            } else if (word == "move") {
                string word2;
                int from, to;
                file >> word2 >> from >> word2 >> word2 >> to;
                const char moved = cur[from];
                cur.erase(cur.begin() + from);
                cur.insert(to, 1, moved);
            }
        }
        if (cur == "fbgdceah")
            cout << cp << endl;
    } while (next_permutation(a.begin(), a.end()));
}
