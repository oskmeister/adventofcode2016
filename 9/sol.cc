#include <cassert>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long LL;

map<pair<int,int>, LL> cache;
string str;

LL solve(int from, int to) {
    if (cache.count(make_pair(from, to))) return cache[make_pair(from, to)];
    LL resultlength = 0;
    for (int i = from; i < to; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ++resultlength;
        } else {
            assert(str[i] == '(');
            ++i;
            int length = 0;
            while (str[i] != 'x') {
                length = length * 10 + str[i] - '0';
                ++i;
            }
            ++i;
            int times = 0;
            while (str[i] != ')')  {
                times = times * 10 + str[i] - '0';
                ++i;
            }
            ++i;
            assert(str[i-1] == ')');
            LL decompressed_length = solve(i, i + length);
            resultlength += decompressed_length * times;
            i += length - 1;
        }
    }
    return resultlength;
}

int main() {
    cin >> str;
    cout << solve(0, str.size())<< endl;
}
