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
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }
        
        vector<int> dp(1 << n, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int y = j;
                while (y) {
                    dp[j] = min(dp[j], max(dp[j - y], sum[y]));
                    y = (y - 1) & j;
                }
            }
        }
        return dp[(1 << n) - 1];      
    }
};