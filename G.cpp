#include <bits/stdc++.h>

using namespace std;

struct Solver {
public:
    void solve();
};


void Solver::solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ids(n + 2, vector<int>());

    vector<int> tree_ids;
    bool fail = false;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        ids[x].push_back(i);

        int sz = ids[x].size();
        if (sz > 3) {
            cout << 'x' << endl;
            fail = true;
        }

        if (sz == 3) {
            tree_ids.push_back(x);
        }

    }

    if (fail) {
        return;
    }
    vector<bool> used(n + 2);
    used[0] = 1;
    used[n + 1] = 1;

    vector<char> ans(m);
    for(int i : tree_ids) {
        int left = ids[i][0];
        int right = ids[i][1];
        int center = ids[i][2];

        if (used[i - 1] || used[i] || used[i + 1]) {
            cout << 'x' << endl;
            return;
        }

        used[i - 1] = true;
        used[i] = true;
        used[i + 1] = true;

        ans[left] = '-';
        ans[center] = '0';
        ans[right] = '+';
    }

    for (int i = 1; i <= n; ++i) {
        if (ids[i].size() != 2) {
            continue;
        }

        int center = ids[i][1];
        ids[i].pop_back();

        if (used[i]) {
            cout << 'x' << endl;
            return;
        }

        used[i] = true;
        ans[center] = '0';
    }

    for (int i = 1; i <= n; ++i) {
        if (ids[i].size() != 1) {
            continue;
        }

        int item = ids[i][0];

        if (!used[i - 1]) {
            used[i - 1] = 1;
            ans[item] = '-';
            continue;
        }

        if (!used[i]) {
            used[i] = 1;
            ans[item] = '0';
            continue;
        }

        if (!used[i + 1]) {
            used[i + 1] = 1;
            ans[item] = '+';
            continue;
        }

        cout << 'x' << endl;
        return;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i];
    }
    cout << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        Solver solver;
        solver.solve();
    }

    return 0;
}