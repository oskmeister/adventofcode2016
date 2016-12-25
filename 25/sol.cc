#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

map<string, int> memory;

string toggle(const string &instr) {
    stringstream ss;
    ss << instr;
    string word;

    vector<string> v;
    while (ss >> word) {
        v.push_back(word);
    }

    if (v.size() == 2) {
        if (v[0] == "inc") 
            v[0] = "dec";
        else
            v[0] = "inc";
    }

    if (v.size() == 3) {
        if (v[0] == "jnz") 
            v[0] = "cpy";
        else
            v[0] = "jnz";
    }

    string result;
    for (string s : v) {
        result += (result.empty() ? "" : " ") + s;
    }
    return result;
}

int main() {
    vector<string> program;

    {
        string row;
        while (getline(cin, row)) {
            program.push_back(row);
        }
    }

    int start_val = 0;
    for (;;) {
        memory.clear();
        memory["a"] = start_val++;
        int iters = 0;
        vector<int> printed;
        cout << endl << "trying val " << (start_val-1) << ": "; 
        for (int i = 0; i < program.size() && iters++ < 100000; ++i) {
            const string &s = program[i];

            stringstream ss;
            ss << s;

            string word;
            while (ss >> word) {
                if (word == "cpy") {
                    string mem, sval;
                    ss >> sval >> mem;
                    const int val = 
                        (sval == "a" || sval == "b" || sval == "c" || sval == "d") ?
                        memory[sval] : stoi(sval);
                    memory[mem] = val;
                } else if (word == "inc") {
                    string mem;
                    ss >> mem;
                    memory[mem]++;
                } else if (word == "dec") {
                    string mem;
                    ss >> mem;
                    memory[mem]--;
                } else if (word == "out") {
                    string mem;
                    ss >> mem;
                    const int val = 
                        (mem == "a" || mem == "b" || mem == "c" || mem == "d") ?
                        memory[mem] : stoi(mem);
                    cout << val << " ";
                    printed.push_back(val);
                } else if (word == "tgl") {
                    string mem;
                    ss >> mem;
                    int val = memory[mem] + i;
                    if (val < 0 || val >= program.size()) continue;
                    string toggled = toggle(program[val]);
                    program[val] = toggled;
                } else if (word == "jnz") {
                    string mem;
                    string pos;
                    ss >> mem >> pos;
                    const int val = 
                        (mem == "a" || mem == "b" || mem == "c" || mem == "d") ?
                        memory[mem] : stoi(mem);
                    const int ipos = 
                        (pos == "a" || pos == "b" || pos == "c" || pos == "d") ?
                        memory[pos] : stoi(pos);
                    if (val != 0) {
                        i = i + ipos - 1;
                    }
                }
            }
        }
        bool expect_zero = true;
        bool ok = true;
        for (int p : printed) {
            if (expect_zero && p == 1) {
                ok = false;
            }
            if (!expect_zero && p == 0) {
                ok = false;
            }
            expect_zero = !expect_zero;
        }
        if (ok) break;
    }

    cout << memory["a"] << endl;
}
