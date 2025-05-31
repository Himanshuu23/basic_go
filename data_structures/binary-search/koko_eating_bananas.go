/*
Koko loves bananas and has n piles of bananas, where the i-th pile has piles[i] bananas. She can eat at most k bananas per hour. Each hour, she chooses one pile and eats up to k bananas from it. If the pile has fewer than k, she eats all of them.
Given an integer h (the total number of hours she has), return the minimum integer k such that she can eat all the bananas within h hours.

Example:
Input:
piles = [3, 6, 7, 11]
h = 8

Output:
4

Explanation
We want the minimum eating speed k such that Koko can eat all the bananas in 8 hours.
Try k = 4:
    Pile 3 → 1 hour (3 < 4)
    Pile 6 → 2 hours (6 ÷ 4 = 1.5 → 2 hours)
    Pile 7 → 2 hours (7 ÷ 4 = 1.75 → 2 hours)
    Pile 11 → 3 hours (11 ÷ 4 = 2.75 → 3 hours)
Total: 1 + 2 + 2 + 3 = 8 hours ✅

If k = 3, total time would exceed 8 hours ❌, so minimum valid k = 4.

When to Apply Binary Search — Pattern to Recognize:
Use binary search on answer when:
    You're asked to minimize or maximize a value (e.g., smallest speed, largest possible size).
    The answer lies in a range, not necessarily in the array (like speed from 1 to max pile).
    There's a monotonic relationship: as the value increases/decreases, some condition transitions from false → true or vice versa.

In this problem:
Higher k ⇒ fewer hours needed (monotonic), so binary search fits.

*/
