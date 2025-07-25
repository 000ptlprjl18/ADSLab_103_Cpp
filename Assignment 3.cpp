#include <iostream>
using namespace std;

/*
Program: Find the smallest number such that its factorial has at least 'n' trailing zeroes.

Description:
Trailing zeroes in a factorial are produced by factors of 10,
and 10 = 2 × 5. Since factors of 2 are more frequent, we count the number of 5s in the factorization.

Mathematical Logic:
To find the number of trailing zeroes in m!:
    trailing_zeroes = m/5 + m/25 + m/125 + ...
This gives the count of 5s in the prime factorization.

We apply a Divide and Conquer strategy (Binary Search) to find the smallest number 'm'
such that the number of trailing zeroes in m! is at least equal to the given value 'n'.

Time Complexity: O(log(n))
Space Complexity: O(1)
*/

int trailingZeroCount(int num) {
    int total = 0;
    while (num > 0) {
        total += num / 5;
        num /= 5;
    }
    return total;
}

int minimumFactorialWithZeroes(int target) {
    int start = 0, end = 5 * target;
    int result = -1;

    while (start <= end) {
        int middle = (start + end) / 2;
        int zeros = trailingZeroCount(middle);

        if (zeros >= target) {
            result = middle;
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    return result;
}

int main() {
    int requiredZeroes;
    cout << "Enter the number of trailing zeroes required: ";
    cin >> requiredZeroes;

    int smallest = minimumFactorialWithZeroes(requiredZeroes);
    cout << "Smallest number whose factorial has at least " << requiredZeroes << " trailing zeroes is: " << smallest << endl;

    return 0;
}
