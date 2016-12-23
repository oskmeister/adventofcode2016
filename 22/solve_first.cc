#include <cstdio>
#include <iostream>

using namespace std;

int used[50][50];
int avail[50][50];
int size[50][50];

int main() {
    int x, y;
    int at = 0;
    while (scanf("/dev/grid/node-x%d-y%d", &x, &y) == 2) {
        cout << x << " " << y << endl;
        int s, u, a;
        string ignore;
        cin >> s; cin.ignore();
        cin >> u; cin.ignore();
        cin >> a; cin.ignore();
        cin >> ignore;
        cin.ignore(); // eat newline
        size[x][y] = s;
        used[x][y] = u;
        avail[x][y] = a;
    }

    int ans = 0;
    for (int i = 0; i < 34; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 34; ++k) {
                for (int l = 0; l < 30; ++l) {
                    if (i == k && j == l) continue;
                    if (used[i][j] > 0 && avail[k][l] >= used[i][j]) ++ans;
                }
            }
        }
    }

    cout << ans << endl;
}
