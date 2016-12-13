#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define DIM 55

int dist[DIM][DIM];

int main() {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            dist[i][j] = 1 << 30;
        }
    }
    
    queue<pair<int,int>> q;
    dist[1][1] = 0;
    q.push(make_pair(1,1));
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        static vector<int> dr = {0, 1, 0, -1};
        static vector<int> dc = {1, 0, -1, 0};
        const int cur_dist = dist[cur.first][cur.second];
        if (cur_dist >= 50) continue;
        for (int i = 0; i < 4; ++i) {
            const int nr = cur.first + dr[i];
            const int nc = cur.second + dc[i];
            const bool ok = __builtin_popcount(nr*nr + 3*nr + 2*nr*nc + nc + nc*nc + 1362) % 2 == 0;
            if (!ok || nc < 0 || nr < 0 || dist[nr][nc] < (1<<30)) continue;
            dist[nr][nc] = cur_dist + 1;
            q.push(make_pair(nr,nc));
        }
    }
    int ans = 0;
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            ans += dist[i][j] < (1<<30);
        }
    }
    cout << ans << endl;
}

