/*
 You are given three integers m, n, and k.
 There is a rectangular grid of size m × n containing k identical pieces. Return the sum of Manhattan distances between every pair of pieces over all valid arrangements of pieces.
 A valid arrangement is a placement of all k pieces on the grid with at most one piece per cell.
 Since the answer may be very large, return it modulo 109 + 7.
 The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 Example 1:
 Input: m = 2, n = 2, k = 2
 Output: 8
 Explanation:
 The valid arrangements of pieces on the board are:
 In the first 4 arrangements, the Manhattan distance between the two pieces is 1.
 In the last 2 arrangements, the Manhattan distance between the two pieces is 2.
 Thus, the total Manhattan distance across all valid arrangements is 1 + 1 + 1 + 1 + 2 + 2 = 8.
 Example 2:
 Input: m = 1, n = 4, k = 3
 Output: 20
 Explanation:
 The valid arrangements of pieces on the board are:
 The first and last arrangements have a total Manhattan distance of 1 + 1 + 2 = 4.
 The middle two arrangements have a total Manhattan distance of 1 + 2 + 3 = 6.
 The total Manhattan distance between all pairs of pieces across all arrangements is 4 + 6 + 6 + 4 = 20.
 Constraints:
 1 <= m, n <= 105
 2 <= m * n <= 105
 2 <= k <= m * n
*/

class Solution {
    public int distanceSum(int m, int n, int k) {
        final int MOD = 1000000007;
        long totalDistance = 0;
        
        // Calculate the number of ways to choose 2 pieces from k
        long combinations = (long)k * (k - 1) / 2 % MOD;
        
        // Calculate distances for all pairs of pieces placed in the grid
        for (int x1 = 0; x1 < m; ++x1) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int x2 = 0; x2 < m; ++x2) {
                    for (int y2 = 0; y2 < n; ++y2) {
                        if (x1 != x2 || y1 != y2) {
                            int distance = Math.abs(x1 - x2) + Math.abs(y1 - y2);
                            totalDistance = (totalDistance + distance) % MOD;
                        }
                    }
                }
            }
        }
        
        // Multiply by combinations to get the sum of all distances across all arrangements
        totalDistance = totalDistance * combinations % MOD;
        return (int)totalDistance;
    }
}