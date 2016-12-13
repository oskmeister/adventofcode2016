#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

map<string, int> memory;

int main() {
    vector<string> program;

    {
        string row;
        while (getline(cin, row)) {
            program.push_back(row);
        }
    }


    memory["c"] = 1;
    for (int i = 0; i < program.size(); ++i) {
        const string &s = program[i];
/*        for (string s : {"a","b","c","d"}) {
            cout << memory[s] << ", ";
        }
        cout << endl;
        cout << s << endl;*/
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
            } else if (word == "jnz") {
                string mem;
                int pos;
                ss >> mem >> pos;
                const int val = 
                    (mem == "a" || mem == "b" || mem == "c" || mem == "d") ?
                    memory[mem] : stoi(mem);
                if (val != 0) {
                    i = i + pos - 1;
                }
            } 
        }
    }

    cout << memory["a"] << endl;
}
