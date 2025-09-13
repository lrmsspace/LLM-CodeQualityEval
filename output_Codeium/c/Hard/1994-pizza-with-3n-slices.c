/**https://leetcode.com/problems/pizza-with-3n-slices/ */
//There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
//	You will pick any pizza slice.
//	Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
//	Your friend Bob will pick the next slice in the clockwise direction of your pick.
//	Repeat until there are no more slices of pizzas.
//Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
// 
//Example 1:
//Input: slices = [1,2,3,4,5,6]
//Output: 10
//Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
//Example 2:
//Input: slices = [8,9,8,6,1,1]
//Output: 16
//Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
// 
//Constraints:
//	3 * n == slices.length
//	1 <= slices.length <= 500
//	1 <= slices[i] <= 1000
int maxSizeSlices(int* slices, int slicesSize) {
    int dp[slicesSize][slicesSize / 3 + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 2; i < slicesSize; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + slices[i - 2]);
    }
    for (int i = 2; i < slicesSize; i++) {
        for (int j = 1; j <= i / 3; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i - 2]);
        }
    }
    return dp[slicesSize - 1][slicesSize / 3];
}
