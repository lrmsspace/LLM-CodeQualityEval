/**https://leetcode.com/problems/allocate-mailboxes/ */
//Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
//Return the minimum total distance between each house and its nearest mailbox.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: houses = [1,4,8,10,20], k = 3
//Output: 5
//Explanation: Allocate mailboxes in position 3, 9 and 20.
//Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
//Example 2:
//Input: houses = [2,3,5,12,18], k = 2
//Output: 9
//Explanation: Allocate mailboxes in position 3 and 14.
//Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
// 
//Constraints:
//	1 <= k <= houses.length <= 100
//	1 <= houses[i] <= 104
//	All the integers of houses are unique.
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i; k <= j; k++) {
                    cost[i][j] += abs(houses[k] - houses[(i + j) / 2]);
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int j = 2; j <= k && j <= i + 1; j++) {
                for (int m = j - 2; m < i; m++) {
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m + 1][i]);
                }
            }
        }
        return dp[n - 1][k];     
    }
};