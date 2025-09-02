#include <iostream>
using namespace std;

/*
Program: Minimum Hours of Work per Day to Finish Tasks in D Days

Description:
We are given an array of tasks where each element represents the amount of work 
required for that task. Each day only one task can be done, but the work for a 
single task can be split across multiple days. The goal is to find the minimum 
number of work hours required per day so that all tasks can be completed within 
at most D days.

Mathematical/Logical Idea:
1. If the daily limit is too small, some tasks will take many days, 
   exceeding the allowed D days.
2. If the daily limit is too large, all tasks can be finished sooner, 
   but we want the minimum possible limit.
3. Use Binary Search on the answer:
   - Range of daily work = [1, max(task)].
   - For each candidate value, check feasibility by counting how many days are 
     required when each task may need multiple days.
   - If total days ≤ D → feasible, try smaller value.
   - Else increase the limit.

Time Complexity: O(N log(max(task)))
Space Complexity: O(1)
*/

bool isFeasible(int task[], int N, int D, int limit) {
    int daysUsed = 0;
    for (int i = 0; i < N; i++) {
        daysUsed += (task[i] + limit - 1) / limit;
        if (daysUsed > D) return false;
    }
    return true;
}
int minimumHours(int task[], int N, int D) {
    int low = 1, high = task[0];
    for (int i = 1; i < N; i++) {
        if (task[i] > high) high = task[i];
    }
    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isFeasible(task, N, D, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
int main() {
    int N, D;
    cout << "Enter number of tasks: ";
    cin >> N;

    int task[100];
    cout << "Enter work for each task: ";
    for (int i = 0; i < N; i++) {
        cin >> task[i];
    }
    cout << "Enter number of days: ";
    cin >> D;
    int ans = minimumHours(task, N, D);
    cout << "Minimum hours required per day: " << ans << endl;
    return 0;
}
