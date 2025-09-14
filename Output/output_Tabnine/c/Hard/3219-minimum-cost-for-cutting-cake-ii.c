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
 1 <= m, n <= 105
 horizontalCut.length == m - 1
 verticalCut.length == n - 1
 1 <= horizontalCut[i], verticalCut[i] <= 103
*/

long long minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize) {
    // Sort the horizontal and vertical cuts in ascending order
    qsort(horizontalCut, horizontalCutSize, sizeof(int), compare);
    qsort(verticalCut, verticalCutSize, sizeof(int), compare);
    
    // Initialize the prefix sums for both horizontal and vertical cuts
    long long prefixSumH[m + 1], prefixSumV[n + 1];
    prefixSumH[0] = 0;
    prefixSumV[0] = 0;
    for (int i = 1; i <= m; i++) {
        prefixSumH[i] = prefixSumH[i - 1] + horizontalCut[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        prefixSumV[i] = prefixSumV[i - 1] + verticalCut[i - 1];
    }
    // Initialize the minimum cost
    long long minCost = LLONG_MAX;
    
    // Iterate through all possible cuts
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // Calculate the current cost
            long long cost = prefixSumH[i] + prefixSumV[j] - prefixSumH[m] - prefixSumV[n];
            // Update the minimum cost if necessary
            minCost = min(minCost, cost);
        }
    }
    
    return minCost;
    
}