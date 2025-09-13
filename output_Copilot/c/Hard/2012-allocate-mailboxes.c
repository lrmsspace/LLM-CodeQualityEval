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
    qsort(houses, housesSize, sizeof(int), cmp);
    int dp[housesSize][k + 1];
    memset(dp, 0x3f, sizeof(dp));
    int prefix[housesSize + 1];
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= housesSize; i++) {
        prefix[i] = prefix[i - 1] + houses[i - 1];
    }
    for (int i = 0; i < housesSize; i++) {
        dp[i][1] = prefix[i + 1] - prefix[0] - (houses[i] + houses[0]) / 2 * (i + 1);
    }
    for (int i = 1; i < housesSize; i++) {
        for (int j = 2; j <= k; j++) {
            for (int l = 0; l < i; l++) {
                dp[i][j] = fmin(dp[i][j], dp[l][j - 1] + prefix[i + 1] - prefix[l + 1] - (houses[i] + houses[l]) / 2 * (i - l));
            }
        }
    }
    return dp[housesSize - 1][k];    
}