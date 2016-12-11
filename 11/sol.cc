#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// The first floor contains a thulium generator, a thulium-compatible microchip, a plutonium generator, and a strontium generator.
// The second floor contains a plutonium-compatible microchip and a strontium-compatible microchip.
// The third floor contains a promethium generator, a promethium-compatible microchip, a ruthenium generator, and a ruthenium-compatible microchip.
// The fourth floor contains nothing relevant.

// <>
// QG, QM, RG, RM
// PM, SM
// TG, TM, PG, SG

// 0
// 1<<0, 1<<4, 1<<1, 1<<5
// 1<<

// {P, Q, R, S, T} x {G, M}

const static int NUM = 7;

typedef pair<int, vector<int>> GameState;

inline int tr(const string &s) {
	int index = s[0] - 'P';
	if (s[1] == 'M') index += NUM;
	return 1 << index; 
}

inline bool is_valid(const int row) {
    for (int b1 = 0; b1 < NUM; ++b1) {
        // Lonely microchip.
        if ((row & (1<<b1) == 0) && (row & (1<<(b1 + NUM)))) {
            for (int b2 = 0; b2 < NUM; ++b2) {
                if (b2 == b1) continue;
                // Generator for other bit.
                if (row & (1 << b2)) return false;
            }
        }
    }
    return true;
}

inline bool is_valid(const vector<int> &state) {
    for (const auto &v : state) {
        if (!is_valid(v)) return false;
    }
    // if (state[0] && state[3]) return false;
    return true;
}

inline bool is_end(const vector<int> &state) {
    return state[3] == (1<<14) - 1;
}

vector<GameState> get_moves(const GameState &game_state) {
    vector<GameState> result;
    const int elevator_index = game_state.first;
    const int row = game_state.second[elevator_index];
    for (int b = 1; b < (1<<14); ++b) {
        if (__builtin_popcount(b) > 2) continue;
        if (((b & row) | ~b) == ~0) {
            if (elevator_index > 0) {
                GameState new_state1 = game_state;
                new_state1.second[elevator_index] ^= b;
                new_state1.second[elevator_index - 1] ^= b;
                new_state1.first--;
                if (is_valid(new_state1.second)) result.push_back(new_state1);
            }
            if (elevator_index < 3) {
                GameState new_state1 = game_state;
                new_state1.second[elevator_index] ^= b;
                new_state1.second[elevator_index + 1] ^= b;
                new_state1.first++;
                if (is_valid(new_state1.second)) result.push_back(new_state1);
            }
        }
    }
    return result;
}

int main() {
	vector<int> state {
		tr("TG") | tr("TM") | tr("PG") | tr("SG") | tr("UG") | tr("UM") | tr("VG") | tr("VM"),
		tr("PM") | tr("SM"),
		tr("QG") | tr("QM") | tr("RG") | tr("RM"),
		0	
	};

    GameState initial_state = {0, state};
    set<GameState> vis;
    queue<pair<GameState, int>> q;
    q.push(make_pair(initial_state,0));
    vis.insert(initial_state);

    int p_distance = -1;
    int seen = 0;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        GameState state = current.first;
        int distance = current.second;
        ++seen;
        if (distance != p_distance) { 
            cout << distance << ", states visited:" << seen << endl;
            p_distance = distance;
        }

        if (is_end(state.second)) {
            cout << distance << endl;
            return 0;
        }

        vector<GameState> moves = get_moves(state);
        for (auto s : moves) {
            if (vis.count(s) == 0) {
                q.push(make_pair(s, distance + 1));
                vis.insert(s);
            }
        }
    }
}
