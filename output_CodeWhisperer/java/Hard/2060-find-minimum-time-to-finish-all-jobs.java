/**https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/ */
//You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
//There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
//Return the minimum possible maximum working time of any assignment. 
// 
//Example 1:
//Input: jobs = [3,2,3], k = 3
//Output: 3
//Explanation: By assigning each person one job, the maximum time is 3.
//Example 2:
//Input: jobs = [1,2,4,7,8], k = 2
//Output: 11
//Explanation: Assign the jobs the following way:
//Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
//Worker 2: 4, 7 (working time = 4 + 7 = 11)
//The maximum working time is 11.
// 
//Constraints:
//	1 <= k <= jobs.length <= 12
//	1 <= jobs[i] <= 107


class Solution {
    public int minimumTimeRequired(int[] jobs, int k) {
        int[] sum = new int[1 << jobs.length];
        for (int i = 1; i < sum.length; i++) {
            int lowBit = Integer.lowestOneBit(i);
            int prev = i - lowBit;
            int last = Integer.numberOfTrailingZeros(lowBit);
            sum[i] = sum[prev] + jobs[last];
        }
        int[] dp = new int[1 << jobs.length];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i < (1 << jobs.length); i++) {
            for (int j = i; j > 0; j = (j - 1) & i) {
                int prev = i - j;
                int sumJ = sum[j];
                if (dp[prev] != -1) {
                    int curr = dp[prev] + Math.max(sumJ, dp[j]);
                    if (dp[i] == -1 || dp[i] > curr) {
                        dp[i] = curr;
                    }
                }
            }
        }
        int[] dpK = new int[k];
        Arrays.fill(dpK, -1);
        dpK[0] = dp[(1 << jobs.length) - 1];
        for (int i = 1; i < (1 << jobs.length); i++) {
            for (int j = i; j > 0; j = (j - 1) & i) {
                int prev = i - j;
                int sumJ = sum[j];
                if (dp[prev] != -1) {
                    for (int l = 0; l < k; l++) {
                        int curr = Math.max(dpK[l], Math.max(dp[prev], dp[j])) + Math.max(sumJ, dpK[l]);
                        if (dpK[(l + 1) % k] == -1 || dpK[(l + 1) % k] > curr) {
                            dpK[(l + 1) % k] = curr;
                        }
                    }
                }
            }
        }
        return dpK[k - 1];     
    }
}