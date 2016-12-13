#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define DIM 100

int mem[DIM][DIM][DIM*DIM];

int dp(int r, int c, int left) {
    const bool value = __builtin_popcount(r*r + 3*r + 2*r*c + c + c*c + 1362) % 2 == 0;
    if (!left || !value || r < 0 || c < 0) return 1<<25;
    if (r == 31 && c == 39) return 0;
    if (mem[r][c][left] != -1) return mem[r][c][left];
    int ans = 1<<25;
    ans = min(ans, 1 + dp(r+1, c, left-1));
    ans = min(ans, 1 + dp(r, c+1, left-1));
    ans = min(ans, 1 + dp(r, c-1, left-1));
    ans = min(ans, 1 + dp(r-1, c, left-1));
    mem[r][c][left] = ans;
    return ans;
}
 
int main() {
    memset(mem, -1, sizeof(mem));
    cout << dp(1, 1, 1000) << endl;
}
