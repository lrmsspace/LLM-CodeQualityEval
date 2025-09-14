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
int minimumTimeRequired(int* jobs, int jobsSize, int k) {
      int n = jobsSize;
        int dp[1 << n][k];
        memset(dp, 0x3f, sizeof(dp));
        int sum[n + 1];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + jobs[i - 1];
        }
        for (int i = 0; i < n; i++) {
            dp[1 << i][0] = jobs[i];
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                for (int j = 0; j < k; j++) {
                    dp[mask][j] = fmin(dp[mask][j], fmax(dp[mask ^ (1 << i)][j], sum[i + 1] - sum[__builtin_popcount(mask) - 1]));
                    for (int subset = mask; subset > 0; subset = (subset - 1) & mask) {
                        dp[mask][j] = fmin(dp[mask][j], fmax(dp[subset][j - 1], sum[i + 1] - sum[__builtin_popcount(mask) - __builtin_popcount(subset) - 1]));
                    }
                }
            }
        }
        return dp[(1 << n) - 1][k - 1];      
}