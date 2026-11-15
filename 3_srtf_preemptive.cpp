#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int pid[100], at[100], bt[100], rt[100], ct[100], tat[100], wt[100];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    int completed = 0, current_time = 0;
    double total_tat = 0, total_wt = 0;

    while (completed != n) {
        int idx = -1;
        int min_rt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) {
                if (rt[i] < min_rt) {
                    min_rt = rt[i];
                    idx = i;
                } else if (rt[i] == min_rt) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            rt[idx]--;
            current_time++;

            if (rt[idx] == 0) {
                completed++;
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                total_tat += tat[idx];
                total_wt += wt[idx];
            }
        } else {
            current_time++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << pid[i] << " " << at[i] << " " << bt[i] << " " << ct[i] << " " << tat[i] << " " << wt[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << total_tat / n << "\n";
    cout << total_wt / n << "\n";

    return 0;
}