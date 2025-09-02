#include <iostream>
using namespace std;

/*
Program: Maximum Shops Visited by K Persons

Description:
We are given the start and end times of several shops, along with K persons available 
to visit them. Each person can visit one shop at a time, and a shop can only be visited 
if the person is free when it opens. The goal is to maximize the total number of shops 
that can be visited.

Mathematical/Logical Idea:
This is a variant of the **Activity Selection Problem** (Greedy Algorithm).
Steps:
1. Represent each shop with its start and end time.
2. Sort all shops by their end times (earliest finishing shop first).
3. Maintain an array of size K to store the current end time of each person.
4. Iterate through each shop:
   - Assign it to the first available person whose end time is less than or equal 
     to the shop's start time.
   - Update that person’s end time to the current shop’s end time.
   - Increase the shop visit count.

This greedy approach ensures that shops are allocated optimally.

Time Complexity: O(N^2 + N*K)
    - Sorting shops: O(N^2) (bubble sort used here)
    - Assigning shops to persons: O(N*K)
    - Can be optimized to O(N log N) with efficient sorting.

Space Complexity: O(N + K)
    - N shops storage
    - K persons' end times
*/


class Shop {
public:
    int start;
    int end;
};
void sortByEndTime(Shop shops[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (shops[i].end > shops[j].end) {
                Shop temp = shops[i];
                shops[i] = shops[j];
                shops[j] = temp;
            }
        }
    }
}
int maxShopsVisited(int S[], int E[], int N, int K) {
    Shop shops[100];
    int endTimeOfPerson[10], count = 0;
    for (int i = 0; i < N; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }
    sortByEndTime(shops, N);
    for (int i = 0; i < K; i++)
        endTimeOfPerson[i] = 0;
    for (int i = 0; i < N; i++) {
        for (int p = 0; p < K; p++) {
            if (endTimeOfPerson[p] <= shops[i].start) {
                endTimeOfPerson[p] = shops[i].end;
                count++;
                break;
            }
        }
    }
    return count;
}
int main() {
    int S[] = {1, 3, 0, 5, 8, 5};
    int E[] = {2, 4, 6, 7, 9, 9};
    int N = 6, K = 2;
    cout << maxShopsVisited(S, E, N, K);
}


