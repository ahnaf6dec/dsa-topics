#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

/*
------------------------------------------------------------
Topic: Binary Search on Answer
------------------------------------------------------------

Main idea:
----------
We do NOT know the answer directly.
But we can GUESS an answer and CHECK if it works.

So:
- Guess a value
- Check if it satisfies the condition
- Based on result, move left or right

This works when answers follow a pattern like:

Time:   1  2  3  4  5  6
State:  F  F  F  T  T  T

Once it becomes TRUE, all next values are also TRUE.

Goal:
-----
Find the FIRST TRUE value (minimum valid answer)
*/


/*
------------------------------------------------------------
Problem: Noodles Cooking Time
------------------------------------------------------------

You are cooking noodles.

You want to find the minimum time (in minutes)
such that noodles are properly cooked.

Rules:
------
- If time is small -> noodles are RAW (false)
- If time is enough -> noodles are COOKED (true)
- Once cooked, it stays cooked for all larger times

Goal:
-----
Find the smallest time when noodles become cooked
*/


/*
------------------------------------------------------------
Check Function
------------------------------------------------------------

This function tells:
"Is this time enough to cook noodles?"

For this example, assume:
Noodles become cooked at time >= 5
*/

bool isPossible(int time) {
    return (time >= 5);
}


/*
------------------------------------------------------------
Brute Force Solution
------------------------------------------------------------

Try every value one by one:
1, 2, 3, 4, 5...

Stop when first valid answer is found

Time Complexity: O(N)
*/

void noodlesCookingMinTimeBrute() {
    for (int t = 1; t <= 10; ++t) {

        // check if noodles are cooked at time t
        if (isPossible(t)) {
            cout << "Min cooking time: " << t << " mins" << endl;
            break; // stop at first valid time
        }
    }
}


/*
------------------------------------------------------------
Optimized Solution (Binary Search on Answer)
------------------------------------------------------------

We search in the answer space instead of checking all values.

Steps:
------
1. Define search range:
   low = minimum possible answer
   high = maximum possible answer

2. Find mid

3. Check:
   - If mid works -> store answer and go LEFT (to find smaller)
   - If mid fails -> go RIGHT

Time Complexity: O(log N)
*/

void noodlesCookingOptimized() {
    int low = 1;     // minimum possible time
    int high = 10;   // maximum possible time (assumed)
    int ans = -1;    // store final answer

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(mid)) {
            // mid works (noodles are cooked)

            ans = mid;          // store possible answer
            high = mid - 1;     // try to find smaller valid time

        } else {
            // mid does NOT work (noodles are still raw)

            low = mid + 1;      // need more time
        }
    }

    cout << "Min cooking time: " << ans << " mins" << endl;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    // Brute force (slow)
    // noodlesCookingMinTimeBrute();

    // Optimized (Binary Search on Answer)
    noodlesCookingOptimized();

    return 0;
}