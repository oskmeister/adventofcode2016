#include <iostream>
#include <vector>

using namespace std;

// simulation is O(n lg n)

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 1);
    int at = 0;
    for (;;) {
        if (v[at] > 0) {
            int next = (at + 1) % n;
            while (v[next] == 0) next = (next + 1) % n;
            if (at == next) {
                cout << at + 1 << endl;
                return 0;
            }
            v[at] += v[next];
            v[next] = 0;
        }
        at = (at + 1) % n;
    }
}
