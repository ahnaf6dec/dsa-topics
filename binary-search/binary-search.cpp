#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'


using namespace std;

/**
 * PURPOSE: Performs a Manual Binary Search.
 * Binary search finds an item by repeatedly splitting the search area in half.
 * * @param arr    The sorted array to search in.
 * @param target The value we are looking for.
 * @param n      The size of the array.
 * @return       The index of the target if found, otherwise -1.
 */
int binarySearch(int arr[], int target, int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        // We use this formula instead of (low + high) / 2 to prevent 
        // "integer overflow" when working with very large numbers.
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Found it! Return the position.
        } 
        else if (arr[mid] < target) {
            low = mid + 1; // Target is in the right half.
        } 
        else {
            high = mid - 1; // Target is in the left half.
        }
    }

    return -1; // Target not found.
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> A = {4, 7, 10, 25, 650, 1};

    // 2. REQUIREMENT: The data MUST be sorted for Binary Search to work.
    sort(A.begin(), A.end());

    int target;
    cout << "Enter a number to find: ";
    cin >> target;

    // 3. Using C++ Built-in Binary Search
    // std::binary_search returns true (1) or false (0).
    bool found = binary_search(A.begin(), A.end(), target);

    // 4. Output results
    if (found) {
        cout << "YES, the number is in the list." << endl;
    } else {
        cout << "NO, the number is not there." << endl;
    }

    return 0;
}

/* --- QUICK STUDY NOTES ---

  1. PREREQUISITE: 
     The list must be SORTED. If it isn't, the results will be wrong.

  2. EFFICIENCY (Time Complexity):
     O(log N). This is very fast. For example, searching through 
     1,000,000 items takes only about 20 steps.

  3. BUILT-IN FUNCTIONS:
     - binary_search(): Returns true/false.
  4. OVERFLOW PREVENTION:
     Always use: mid = low + (high - low) / 2;
*/