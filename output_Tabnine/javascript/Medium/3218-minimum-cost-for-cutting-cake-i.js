/*
 There is an m x n cake that needs to be cut into 1 x 1 pieces.
 You are given integers m, n, and two arrays:
 horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
 verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
 In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:
 Cut along a horizontal line i at a cost of horizontalCut[i].
 Cut along a vertical line j at a cost of verticalCut[j].
 After the cut, the piece of cake is divided into two distinct pieces.
 The cost of a cut depends only on the initial cost of the line and does not change.
 Return the minimum total cost to cut the entire cake into 1 x 1 pieces.
 Example 1:
 Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]
 Output: 13
 Explanation:
 Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
 Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
 Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
 Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
 Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
 The total cost is 5 + 1 + 1 + 3 + 3 = 13.
 Example 2:
 Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]
 Output: 15
 Explanation:
 Perform a cut on the horizontal line 0 with cost 7.
 Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
 Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
 The total cost is 7 + 4 + 4 = 15.
 Constraints:
 1 <= m, n <= 20
 horizontalCut.length == m - 1
 verticalCut.length == n - 1
 1 <= horizontalCut[i], verticalCut[i] <= 103
*/

/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} horizontalCut
 * @param {number[]} verticalCut
 * @return {number}
 */
var minimumCost = function(m, n, horizontalCut, verticalCut) {
    // Sort the horizontal and vertical cuts
    horizontalCut.sort((a, b) => a - b);
    verticalCut.sort((a, b) => a - b);
    
    // Add the edges of the cake to the cuts
    horizontalCut = [0,...horizontalCut, m];
    verticalCut = [0,...verticalCut, n];
    
    // Initialize the dp array with large values
    const dp = Array(m + 1).fill(null).map(() => Array(n + 1).fill(Infinity));
    
    // Set the cost for cutting the first piece of cake to 0
    dp[0][0] = 0;
    // Iterate over the possible lengths of the subgrid

    for (let i = 1; i <= m; i++) {
        // Iterate over the possible lengths of the subgrid
        for (let j = 1; j <= n; j++) {
            // Iterate over the possible positions of the cuts
            for (let k = 1; k <= i; k++) {
                // Calculate the cost of cutting the subgrid
                const cost = horizontalCut[i] - horizontalCut[k - 1] + verticalCut[j] - verticalCut[k - 1];
                // Update the minimum cost
                dp[i][j] = Math.min(dp[i][j], dp[k - 1][j - 1] + cost);
            }
        }
    }
    // Return the minimum total cost
    return dp[m][n];
    
};