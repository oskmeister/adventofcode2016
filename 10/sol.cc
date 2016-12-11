#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, pair<int,int>> tree; 
vector<vector<int>> robotvalues;

void propagate(int robot) {
    if (robot >= 1000) return;
    if (robotvalues[robot].size() < 2) return;
    assert (tree.count(robot));
    int a = robotvalues[robot][0], b = robotvalues[robot][1];
    if (a > b) swap(a, b);
    const auto pii = tree[robot];
    const auto l = pii.first;
    const auto r = pii.second;
    if (a == 17 && b == 61) cout << robot << endl;
    robotvalues[robot].clear();
    robotvalues[l].push_back(a);
    robotvalues[r].push_back(b);
    propagate(l);
    propagate(r);
}

int main() {
    string word;
    robotvalues.resize(2000);
    vector<pair<int,int>> inst;
    while (cin >> word) {
        if (word == "bot") {
            string bot, lo, hi; 
            bool output1 = false;
            bool output2 = false;
            cin >> bot >> lo >> lo >> lo >> lo;
            if (lo == "output") output1 = true;
            cin >> lo;
            cin >> hi >> hi >> hi >> hi;
            if (hi == "output") output2 = true;
            cin >> hi;
            int robot = stoi(bot);
            int left = stoi(lo) + output1 * 1000;
            int right = stoi(hi) + output2 * 1000;
            tree[robot] = make_pair(left, right);
        } else if (word == "value"){
            string value, to;
            cin >> value >> to >> to >> to >> to;
            int value_to_give = stoi(value);
            int robot_to_give = stoi(to);
            inst.push_back(make_pair(value_to_give, robot_to_give));
        } else assert(false);
    }
    for (auto p : inst) {
        const int robot_to_give = p.second;
        const int value_to_give = p.first;
        robotvalues[robot_to_give].push_back(value_to_give);
        propagate(robot_to_give);
    }

    for (int i = 1000; i < 1003; ++i) {
        auto v = robotvalues[i];
        for (int x : v) cout << x << endl;
    }
}
