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
int minDistance(int* houses, int housesSize, int k) {
    int** dp = (int**)malloc(sizeof(int*) * (housesSize + 1));
    for (int i = 0; i <= housesSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (k + 1));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= housesSize; i++) {
        for (int j = 1; j <= i; j++) {
            int min = INT_MAX;
            for (int m = j; m <= i; m++) {
                int cost = 0;
                for (int n = j; n <= i; n++) {
                    cost += abs(houses[m - 1] - houses[n - 1]);
                }
                if (m == j) {
                    min = cost;
                } else {
                    min = (min < dp[m - 1][j - 1] + cost) ? min : dp[m - 1][j - 1] + cost;
                }
            }
            dp[i][j] = min;
        }
    }
    int result = dp[housesSize][k];
    for (int i = 0; i <= housesSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}