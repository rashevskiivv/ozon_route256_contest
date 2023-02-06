#include <bits/stdc++.h>

using namespace std;

struct Solver {
public:
    void solve();
};


void Solver::solve() {
    constexpr size_t N = 8;
    constexpr size_t MAX_L = 5;
    constexpr int MAX_ANS = 1000;

    int field[N][N] = {0};

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            char c;
            cin >> c;

            if (c == '.') {
                field[i][j] = 0;
            }
            else {
                field[i][j] = 1;
            }
        }
    }

    int k, l;
    cin >> k;

    if (k > 1) {
        return;
    }

    cin >> l;
    int figure[MAX_L][MAX_L] = {0};

    for (size_t i = 0; i < l; ++i) {
        for (size_t j = 0; j < l; ++j) {
            char c;
            cin >> c;

            if (c == '.') {
                figure[i][j] = 0;
            }
            else {
                figure[i][j] = 1;
            }
        }
    }

    int min_ans = MAX_ANS;

    for (size_t dx = 0; dx < N; ++dx) {
        if (dx + l > N) {
            continue;
        }

        for (size_t dy = 0; dy < N; ++dy) {
            if (dy + l > N) {
                continue;
            }

            bool fail = false;

            for (size_t i = 0; i < l; ++i) {
                if (fail) {
                    break;
                }

                for (size_t j = 0; j < l; ++j) {
                    size_t field_x = dx + i;
                    size_t field_y = dy + j;

                    if (field[field_x][field_y] == 1 && figure[i][j] == 1) {
                        fail = true;
                        break;
                    }
                }
            }

            if (fail) {
                continue;
            }

            int used[N][N] = {0};

            for (size_t i = 0; i < N; ++i) {
                for (size_t j = 0; j < N; ++j) {
                    used[i][j] = field[i][j];
                }
            }

            for (size_t i = 0; i < l; ++i) {
                for (size_t j = 0; j < l; ++j) {
                    size_t field_x = dx + i;
                    size_t field_y = dy + j;

                    if (figure[i][j] == 1) {
                        used[field_x][field_y] = 1;
                    }
                }
            }

            bool is_empty_raw[N] = {0};
            bool is_empty_column[N] = {0};

            for (size_t i = 0; i < N; ++i) {
                bool found_empty = false;

                for (size_t j = 0; j < N; ++j) {
                    if (used[i][j] == 0) {
                        found_empty = true;
                        break;
                    }
                }

                if (!found_empty) {
                    is_empty_raw[i] = true;
                }
            }

            for (size_t j = 0; j < N; ++j) {
                bool found_empty = false;

                for (size_t i = 0; i < N; ++i) {
                    if (used[i][j] == 0) {
                        found_empty = true;
                        break;
                    }
                }

                if (!found_empty) {
                    is_empty_column[j] = true;
                }
            }

            int used_fields = 0;

            for (size_t i = 0; i < N; ++i) {
                if (is_empty_raw[i]) {
                    continue;
                }

                for (size_t j = 0; j < N; ++j) {
                    if (is_empty_column[j]) {
                        continue;
                    }

                    if (used[i][j]) {
                        used_fields++;
                    }

                }
            }

            min_ans = min(min_ans, used_fields);

        }
    }

    if (min_ans == MAX_ANS) {
        cout << -1 << endl;
    }
    else {
        cout << min_ans << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        Solver solver;
        solver.solve();
    }

    return 0;
}