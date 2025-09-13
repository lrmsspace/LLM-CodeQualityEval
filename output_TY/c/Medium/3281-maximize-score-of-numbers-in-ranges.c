/*
 You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].
 You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.
 Return the maximum possible score of the chosen integers.
 Example 1:
 Input: start = [6,0,3], d = 2
 Output: 4
 Explanation:
 The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which equals 4.
 Example 2:
 Input: start = [2,6,13,13], d = 5
 Output: 5
 Explanation:
 The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) which equals 5.
 Constraints:
 2 <= start.length <= 105
 0 <= start[i] <= 109
 0 <= d <= 109
*/

int maxPossibleScore(int* start, int startSize, int d) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    int a[1000000], b[1000000], c[1000000], dp[1000000];

    for (i = 0; i < startSize; i++) {
        a[i] = start[i];
        b[i] = start[i];
        c[i] = start[i];
    }
    for (i = 0; i < startSize; i++) {
        for (j = i; j < startSize; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < startSize; i++) {
        for (j = i; j < startSize; j++) {
            if (b[i] < b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }   

    for (i = 0; i < startSize; i++) {
        for (j = i; j < startSize; j++) {
            if (c[i] > c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    return (a[startSize - 1] + b[startSize - 1] + c[startSize - 1]);
}