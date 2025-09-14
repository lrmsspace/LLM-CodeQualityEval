/**https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/ */
//You are given an integer array rolls of length n and an integer k. You roll a k sided dice numbered from 1 to k, n times, where the result of the ith roll is rolls[i].
//Return the length of the shortest sequence of rolls so that there's no such subsequence in rolls.
//A sequence of rolls of length len is the result of rolling a k sided dice len times.
// 
//Example 1:
//Input: rolls = [4,2,1,2,3,3,2,4,1], k = 4
//Output: 3
//Explanation: Every sequence of rolls of length 1, [1], [2], [3], [4], can be taken from rolls.
//Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can be taken from rolls.
//The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
//Note that there are other sequences that cannot be taken from rolls.
//Example 2:
//Input: rolls = [1,1,2,2], k = 2
//Output: 2
//Explanation: Every sequence of rolls of length 1, [1], [2], can be taken from rolls.
//The sequence [2, 1] cannot be taken from rolls, so we return 2.
//Note that there are other sequences that cannot be taken from rolls but [2, 1] is the shortest.
//Example 3:
//Input: rolls = [1,1,3,2,2,2,3,3], k = 4
//Output: 1
//Explanation: The sequence [4] cannot be taken from rolls, so we return 1.
//Note that there are other sequences that cannot be taken from rolls but [4] is the shortest.
// 
//Constraints:
//	n == rolls.length
//	1 <= n <= 105
//	1 <= rolls[i] <= k <= 105
int shortestSequence(int* rolls, int rollsSize, int k) {
    int i, j, l, m, n, count = 0, max = 0;
    int *dp = (int *)malloc(sizeof(int) * (k + 1));
    memset(dp, 0, sizeof(int) * (k + 1));
    for (i = 0; i < rollsSize; i++) {
        dp[rolls[i]] = 1;
        for (j = 1; j <= k; j++) {
            if (dp[j] == 0) {
                continue;
            }
            for (l = 1; l <= k; l++) {
                if (j == l) {
                    continue;
                }
                m = 0;
                for (n = i + 1; n < rollsSize; n++) {
                    if (rolls[n] == l) {
                        m++;
                    }
                }
                if (m > max) {
                    max = m;
                }
            }
        }
        count += max;
        max = 0;
    }
    return count;    
}