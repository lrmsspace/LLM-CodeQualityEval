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
int connectTwoGroups(int** cost, int costSize, int* costColSize) {
    int size1 = costSize;
    int size2 = costColSize[0];
    
    int dp[size1 + 1][size2 + 1];
    memset(dp, 0x3f, sizeof(dp));
    
    for (int i = 1; i <= size1; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= size2; j++) {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i - 1][j - 1];
        }
    }
    
    return dp[size1][size2];
    
}