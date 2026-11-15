#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pid[100], at[100], bt[100], pr[100], rem_bt[100];
    int ct[100], tat[100], wt[100], is_completed[100];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> at[i] >> bt[i] >> pr[i];
        rem_bt[i] = bt[i];
        is_completed[i] = 0;
    }

    int current_time = 0;
    int completed = 0;
    double total_tat = 0, total_wt = 0;

    while (completed != n) {
        int idx = -1;
        int min_pr = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && is_completed[i] == 0) {
                if (pr[i] < min_pr) {
                    min_pr = pr[i];
                    idx = i;
                }
                else if (pr[i] == min_pr) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            rem_bt[idx]--;
            current_time++;

            if (rem_bt[idx] == 0) {
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                total_tat += tat[idx];
                total_wt += wt[idx];

                is_completed[idx] = 1;
                completed++;
            }
        } else {
            current_time++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << pid[i] << " " << at[i] << " " << bt[i] << " " << pr[i] << " " << ct[i] << " " << tat[i] << " " << wt[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << total_tat / n << "\n";
    cout << total_wt / n << "\n";

    return 0;
}