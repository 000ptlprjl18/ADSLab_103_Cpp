//PROBLEM STATEMENT: SORT AN ARRAY
//DESCRIPTION: Sort an integer array without built-in functions using divide and conquer.
//Sample Input: [5,2,3,1]
//Output : [1,2,3,4]

#include <iostream>
using namespace std;

// Function to merge two parts
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100]; 

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (int i = l, t = 0; i <= r; i++, t++)
        a[i] = temp[t];
}

// Merge Sort function
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {5, 2, 3, 1};
    int n = 4;

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
