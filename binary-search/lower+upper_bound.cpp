#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
===========================================================
LOWER BOUND
-----------------------------------------------------------
Definition:
    First index i such that ar[i] >= target

Visual intuition:
    [ < target | >= target ]
      invalid      valid

Goal:
    Find FIRST valid position

Return:
    If not found → return n
===========================================================
*/
int lowerBoundBinarySearch(const vector<int>& ar, int target) {
  int low = 0, high = ar.size() - 1;
  int ans = ar.size();  // default (not found)

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (ar[mid] >= target) {
      ans = mid;
      high = mid - 1;  // go left
                        // we contine..... array may have duplications(ensure accuracy)
    } else {
      low = mid + 1;  // go right
    }
  }

  return ans;
}

/*
===========================================================
UPPER BOUND
-----------------------------------------------------------
Definition:
    First index i such that ar[i] > target

Visual intuition:
    [ <= target | > target ]
       invalid      valid

Goal:
    Find FIRST strictly greater element

Return:
    If not found → return n
===========================================================
*/
int upperBoundBinarySearch(const vector<int>& ar, int target) {
  int low = 0, high = ar.size() - 1;
  int ans = ar.size();  // default (not found)

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (ar[mid] > target) {
      ans = mid;
      high = mid - 1;  // go left
                       // we contine..... array may have duplications(ensure accuracy)
    } else {
      low = mid + 1;  // go right
    }
  }

  return ans;
}

/*
===========================================================
LINEAR UPPER BOUND (for understanding) — O(N)
-----------------------------------------------------------
*/
int upperBoundLinear(const vector<int>& ar, int target) {
  for (int i = 0; i < (int)ar.size(); i++) {
    if (ar[i] > target) {
      return i;
    }
  }
  return ar.size();
}

/*
===========================================================
FREQUENCY USING BOUNDS
-----------------------------------------------------------
count = upper_bound - lower_bound
===========================================================
*/
int countFrequency(const vector<int>& ar, int target) {
  int lb = lowerBoundBinarySearch(ar, target);
  int ub = upperBoundBinarySearch(ar, target);
  return ub - lb;
}

/*
===========================================================
MAIN (Examples + Understanding)
===========================================================
*/
int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> A = {4, 7, 10, 25, 650, 1};
  sort(A.begin(), A.end());

  /*
  Sorted:
  A = [1, 4, 7, 10, 25, 650]
  */

  int target = 7;

  int lb = lowerBoundBinarySearch(A, target);
  int ub = upperBoundBinarySearch(A, target);

  /*
  Example 1:
      A = [1, 3, 3, 3, 5]
      target = 3

      lower bound:
          first >= 3 → index = 1

      upper bound:
          first > 3 → index = 4

      frequency = 4 - 1 = 3
  */

  /*
  Detailed visual:

  Array:   [1, 3, 3, 3, 5]
  Index:    0  1  2  3  4

  Lower Bound (>= 3):
      [1 | 3 3 3 5]
       ^   ^
     <3   >=3 (first valid)

  Upper Bound (> 3):
      [1 3 3 3 | 5]
              ^
            >3 (first valid)
  */

  return 0;
}
}
