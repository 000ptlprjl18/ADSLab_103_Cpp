#include <iostream>
using namespace std;

int main() 
{
    int a[10], n, count = 0;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == 1) {
            if (a[mid + 1] == 1) {
                low = mid + 1;
            } else {
                cout << "Count = " << n - mid - 1 << endl;
                break;
            }
        } else if (a[mid] == 0) {
            if (a[mid + 1] == 0) {
                if (a[mid - 1] == 0) {
                    high = mid - 1;
                } else {
                    cout << "Count = " << n - mid << endl;
                    break;
                }
            }
        } else {
            cout << "Invalid input";
        }
    }

    return 0;
}
