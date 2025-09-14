/**https://leetcode.com/problems/rearranging-fruits/ */
//You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
//	Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
//	The cost of the swap is min(basket1[i],basket2[j]).
//Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.
//Return the minimum cost to make both the baskets equal or -1 if impossible.
// 
//Example 1:
//Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
//Output: 1
//Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
//Example 2:
//Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
//Output: -1
//Explanation: It can be shown that it is impossible to make both the baskets equal.
// 
//Constraints:
//	basket1.length == basket2.length
//	1 <= basket1.length <= 105
//	1 <= basket1[i],basket2[i] <= 109
long long minCost(int* basket1, int basket1Size, int* basket2, int basket2Size) {
    int n = basket1Size;
    int m = basket2Size;
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += basket1[i];
    }
    int sum2 = 0;
    for (int i = 0; i < m; i++) {
        sum2 += basket2[i];
    }
    if (sum1 != sum2) {
        return -1;
    }
    int dp[n + 1][sum1 + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum1; j++) {
            dp[i + 1][j] = fmin(dp[i + 1][j], dp[i][j]);
            if (j + basket1[i] <= sum1) {
                dp[i + 1][j + basket1[i]] = fmin(dp[i + 1][j + basket1[i]], dp[i][j] + basket1[i]);
            }
        }
    }
    int answer = INT_MAX;
    for (int i = 0; i <= sum1; i++) {
        int cost1 = dp[n][i];
        int cost2 = sum1 - i;
        answer = fmin(answer, fmax(cost1, cost2));
    }
    return answer;    
}