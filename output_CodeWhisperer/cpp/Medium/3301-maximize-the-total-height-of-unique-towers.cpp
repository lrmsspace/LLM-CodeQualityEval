/*
 You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.
 Your task is to assign a height to each tower so that:
 The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
 No two towers have the same height.
 Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
 Example 1:
 Input: maximumHeight = [2,3,4,3]
 Output: 10
 Explanation:
 We can assign heights in the following way: [1, 2, 4, 3].
 Example 2:
 Input: maximumHeight = [15,10]
 Output: 25
 Explanation:
 We can assign heights in the following way: [15, 10].
 Example 3:
 Input: maximumHeight = [2,2,1]
 Output: -1
 Explanation:
 It's impossible to assign positive heights to each index so that no two towers have the same height.
 Constraints:
 1 <= maximumHeight.length <= 105
 1 <= maximumHeight[i] <= 109
*/

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = maximumHeight[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0] + maximumHeight[i], dp[i-1][1] + maximumHeight[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);        
    }
};