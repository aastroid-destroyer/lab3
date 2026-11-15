#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    int pid[100], at[100], bt[100], ct[100], tat[100], wt[100], completed[100];
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> at[i] >> bt[i];
        completed[i] = 0;
    }
    int current_time = 0, completed_count = 0;
    double total_tat = 0, total_wt = 0;
    while (completed_count < n) {
        int idx = -1;
        int min_bt = 1000000000;
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && completed[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                } else if (bt[i] == min_bt) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1) {
            current_time += bt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_tat += tat[idx];
            total_wt += wt[idx];

            completed[idx] = 1;
            completed_count++;
        } else {
            current_time++;
        }
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" 
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "Average TAT: " << total_tat / n << "\n";
    cout << "Average WT: " << total_wt / n << "\n";
}