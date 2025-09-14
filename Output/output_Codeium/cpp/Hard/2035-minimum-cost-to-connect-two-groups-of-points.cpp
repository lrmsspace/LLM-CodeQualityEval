/**https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/ */
//You are given two groups of points where the first group has size1 points, the second group has size2 points, and size1 >= size2.
//The cost of the connection between any two points are given in an size1 x size2 matrix where cost[i][j] is the cost of connecting point i of the first group and point j of the second group. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.
//Return the minimum cost it takes to connect the two groups.
// 
//Example 1:
//Input: cost = [[15, 96], [36, 2]]
//Output: 17
//Explanation: The optimal way of connecting the groups is:
//1--A
//2--B
//This results in a total cost of 17.
//Example 2:
//Input: cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
//Output: 4
//Explanation: The optimal way of connecting the groups is:
//1--A
//2--B
//2--C
//3--A
//This results in a total cost of 4.
//Note that there are multiple points connected to point 2 in the first group and point A in the second group. This does not matter as there is no limit to the number of points that can be connected. We only care about the minimum total cost.
//Example 3:
//Input: cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
//Output: 10
// 
//Constraints:
//	size1 == cost.length
//	size2 == cost[i].length
//	1 <= size1, size2 <= 12
//	size1 >= size2
//	0 <= cost[i][j] <= 100
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size(), size2 = cost[0].size();
        vector<vector<int>> dp(size1 + 1, vector<int>(1 << size2, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 0; i < size1; ++i) {
            for (int mask = 0; mask < (1 << size2); ++mask) {
                if (dp[i][mask] == INT_MAX) continue;
                
                // Try to connect point i from group 1 to any point j in group 2
                for (int j = 0; j < size2; ++j) {
                    int newMask = mask | (1 << j);
                    dp[i + 1][newMask] = min(dp[i + 1][newMask], dp[i][mask] + cost[i][j]);
                }
                
                // Try to connect point i from group 1 to a previously connected point in group 2
                for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
                    dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][subMask]);
                }
            }
        }
        
        int answer = INT_MAX;
        for (int mask = 0; mask < (1 << size2); ++mask) {
            if (__builtin_popcount(mask) == size2) {
                answer = min(answer, dp[size1][mask]);
            }
        }
        
        return answer;

    }
};