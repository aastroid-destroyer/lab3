#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, tq;
    if (!(cin >> n >> tq)) return 0;
    vector<int> at(n), bt(n), rt(n), ct(n), tat(n), wt(n);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }
    queue<int> q;
    int time = 0, completed = 0;
    int min_at = 1e9;
    for (int i = 0; i < n; i++) {
        if (at[i] < min_at) min_at = at[i];
    }
    time = min_at;
    for (int i = 0; i < n; i++) {
        if (at[i] <= time && !vis[i]) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (completed < n) {
        if (q.empty()) {
            int next_at = 1e9;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && at[i] < next_at) {
                    next_at = at[i];
                }
            }
            time = next_at;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && !vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        int idx = q.front();
        q.pop();
        int exec = min(tq, rt[idx]);
        rt[idx] -= exec;
        time += exec;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
        if (rt[idx] > 0) {
            q.push(idx);
        } else {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;
        }
    }
    double total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
        cout << i + 1 << " " << at[i] << " " << bt[i] << " " << ct[i] << " " << tat[i] << " " << wt[i] << "\n";
    }
    cout << fixed << setprecision(2);
    cout << total_wt / n << "\n";
    cout << total_tat / n << "\n";
}