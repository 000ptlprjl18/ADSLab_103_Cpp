#include <iostream>
using namespace std;

/*
Program: Move all zeroes to the end of an array using Divide and Conquer.

Description:
The goal is to move all zero elements in the array to the end while preserving 
the relative order of non-zero elements.

Mathematical Approach:
- We use the Divide and Conquer technique similar to Merge Sort.
- The array is recursively divided into two halves.
- After solving the subarrays, we merge them:
    - During merge, we first collect all non-zero elements from both halves.
    - Then, we count how many elements were removed (i.e., zeroes),
      and add that many zeroes at the end.
- This ensures that all zeroes are pushed to the end during each merge step.

Time Complexity:
- The method follows a recurrence relation similar to T(n) = 2T(n/2) + O(n),
  which results in a total time complexity of O(n log n).

Space Complexity:
- A temporary array of size O(n) is used during merging.
*/

void combineZeroFree(int data[], int start, int middle, int end) {
    int tempArray[100];
    int k = 0;

    for (int i = start; i <= middle; i++) {
        if (data[i] != 0)
            tempArray[k++] = data[i];
    }

    for (int i = middle + 1; i <= end; i++) {
        if (data[i] != 0)
            tempArray[k++] = data[i];
    }

    int totalElements = end - start + 1;

    for (int i = 0; i < k; i++) {
        data[start + i] = tempArray[i];
    }

    for (int i = k; i < totalElements; i++) {
        data[start + i] = 0;
    }
}

void shiftZerosToEnd(int data[], int low, int high) {
    if (low >= high) return;

    int middle = (low + high) / 2;
    shiftZerosToEnd(data, low, middle);
    shiftZerosToEnd(data, middle + 1, high);
    combineZeroFree(data, low, middle, high);
}

int main() {
    int numbers[100], size;
    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter the array elements (0 and non-zero values): ";
    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    shiftZerosToEnd(numbers, 0, size - 1);

    cout << "Array after pushing all zeroes to the end: ";
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    return 0;
}
