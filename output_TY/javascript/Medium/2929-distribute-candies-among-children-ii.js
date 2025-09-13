/*
 You are given two positive integers n and limit.
 Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.
 Example 1:
 Input: n = 5, limit = 2
 Output: 3
 Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
 Example 2:
 Input: n = 3, limit = 3
 Output: 10
 Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
 Constraints:
 1 <= n <= 106
 1 <= limit <= 106
*/

/**
 * @param {number} n
 * @param {number} limit
 * @return {number}
 */
var distributeCandies = function(n, limit) {
    let dp = new Array(limit+1).fill(0).map(()=>new Array(2).fill(0));
    for(let i=0; i<=limit; i++){
        for(let j=0; j<=limit; j++){
            if(i+j<=n && i+j>=n-limit){
                if(i==j) dp[i][j] = 1;
                else dp[i][j] = 2;
            }
            else dp[i][j] = 0;
        }
    }
    for(let i=limit+1; i<=n; i++){
        for(let j=0; j<=limit; j++){
            dp[i][j] = dp[i-1][j];
            if(j>0) dp[i][j] += dp[i-1][j-1];
        }
    }
    for(let i=0; i<=limit; i++){
        for(let j=limit+1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(i>0) dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[limit][n];
};