/**https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */
//You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
//Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 12
//Explanation: There are 12 possible way to paint the grid as shown.
//Example 2:
//Input: n = 5000
//Output: 30228214
// 
//Constraints:
//	n == grid.length
//	1 <= n <= 5000
int numOfWays(int n) {
    long long a121 = 6, a123 = 6, b121, b123, mod = 1000000007;
    for (int i = 1; i < n; i++) {
        b121 = (3 * a121 + 2 * a123) % mod;
        b123 = (2 * a121 + 2 * a123) % mod;
        a121 = b121;
        a123 = b123;
    }
    return (a121 + a123) % mod;    
}