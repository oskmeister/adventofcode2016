#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> grid;
    {
        string line;
        while (getline(cin, line)) {
            grid.push_back(line);
        }
    }
    int num_points = 0;
    int start_r, start_c;

    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            const char cur = grid[r][c];
            if (cur == '0') {
                start_r = r;
                start_c = c;
            }
            if (cur >= '0' && cur <= '9') {
                num_points = max(num_points, cur - '0');
            }
        }
    }

    const int num_rows = grid.size();
    const int num_cols = grid[0].size();

    using State=pair<pair<int,int>,int>;

    map<State, int> distance;
    queue<State> queue;
    State start(make_pair(start_r, start_c), 0);
    distance[start] = 0;
    queue.push(start);

    while (!queue.empty()) {
        auto cur = queue.front();
        queue.pop();
        const int cur_dist = distance[cur];
        if (cur.second == (1<<num_points) - 1) {
            cout << cur_dist << endl;
            return 0;
        }
        const static vector<int> dr = {1, 0, -1, 0};
        const static vector<int> dc = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = cur.first.first + dr[i];
            int nc = cur.first.second + dc[i];
            if (nr < 0 || nr >= num_rows || nc < 0 || nc >= num_cols ||
                    grid[nr][nc] == '#') {
                continue;
            }
            auto new_point = make_pair(nr, nc);
            int mask = grid[nr][nc] >= '1' && grid[nr][nc] <= '9' ?
                (1<<(grid[nr][nc] - '0' - 1)) : 0;
            auto new_bitset = cur.second | mask;
            auto new_state = State(new_point, new_bitset);
            if (distance.count(new_state)) continue;
            distance[new_state] = cur_dist + 1;
            queue.push(new_state);
        }
    }
}
