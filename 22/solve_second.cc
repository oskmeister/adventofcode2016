#include <cmath>
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

    int empty_x, empty_y;
    for (int i = 0; i < 34; ++i) {
        for (int j = 0; j < 30; ++j) {
            int u  = used[i][j];
            int a =  avail[i][j];
            int s =  size[i][j];
            char c;
            if (u == 0) {
               c = '_';
               empty_x = i;
               empty_y = j;
            } else if (s >= 200) c = '#';
            else if (i == 33 && j == 0) c = 'G';
            else {
                c = '.';
            }
            cout << c << " ";
        }
        cout << endl;
    }

    int via_x = 1;
    int via_y = 2;

    int goal_x = 33;
    int goal_y = 0;

    int ans = abs(empty_x - via_x) + abs(empty_y - via_y);
    ans += abs(via_y - goal_y) + abs(via_x - goal_x);
    ans += 5 * (goal_x - 1);

    cout << ans << endl;

}
