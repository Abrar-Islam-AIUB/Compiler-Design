#include <iostream>
#include <vector>
#include "1.6.h"
using namespace std;

int returnSmallest(vector<int> arr, int n) {
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int returnLargest(vector<int> arr, int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}
/*
int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Please enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal = returnSmallest(arr, n);
    int maxVal = returnLargest(arr, n);

    cout << "Minimum value::" << minVal << endl;
    cout << "Maximum value::" << maxVal << endl;

    return 0;
}*/
