/**https://leetcode.com/problems/mice-and-cheese/ */
//There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.
//A point of the cheese with index i (0-indexed) is:
//	reward1[i] if the first mouse eats it.
//	reward2[i] if the second mouse eats it.
//You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.
//Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.
// 
//Example 1:
//Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
//Output: 15
//Explanation: In this example, the first mouse eats the 2nd (0-indexed) and the 3rd types of cheese, and the second mouse eats the 0th and the 1st types of cheese.
//The total points are 4 + 4 + 3 + 4 = 15.
//It can be proven that 15 is the maximum total points that the mice can achieve.
//Example 2:
//Input: reward1 = [1,1], reward2 = [1,1], k = 2
//Output: 2
//Explanation: In this example, the first mouse eats the 0th (0-indexed) and 1st types of cheese, and the second mouse does not eat any cheese.
//The total points are 1 + 1 = 2.
//It can be proven that 2 is the maximum total points that the mice can achieve.
// 
//Constraints:
//	1 <= n == reward1.length == reward2.length <= 105
//	1 <= reward1[i], reward2[i] <= 1000
//	0 <= k <= n
int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k) {
        int n = reward1Size;
    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + reward1[i - 1];
        for (int j = 0; j < n; j++) {
            if (i - j - 1 < k) {
                dp[0][i] = fmax(dp[0][i], dp[1][j] + reward1[i - 1]);
            }
        }
        dp[1][i] = dp[0][i - 1] + reward2[i - 1];
        for (int j = 0; j < n; j++) {
            if (i - j - 1 < k) {
                dp[1][i] = fmax(dp[1][i], dp[0][j] + reward2[i - 1]);
            }
        }
    }
    return fmax(dp[0][n], dp[1][n]);    
}