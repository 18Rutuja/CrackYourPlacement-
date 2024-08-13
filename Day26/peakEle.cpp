#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to find the minimum cost to make all elements equal
int minCostToMakeElementEqual(int arr[], int N) {
    // Sort the array
    sort(arr, arr + N);

    // Find the median
    int median = arr[N / 2];

    // Compute the cost to make all elements equal to the median
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost += abs(arr[i] - median);
    }

    return cost;
}

// Driver code to test the function
int main() {
    int arr[] = { 1, 100, 101 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum cost to make all elements equal: "
         << minCostToMakeElementEqual(arr, N) << endl;

    return 0;
}
