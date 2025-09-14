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
    int mod = 1000000007;
    long color2 = 6;
    long color3 = 6;
    for (int i = 1; i < n; i++) {
        long temp = color2;
        color2 = (2 * color2 + 2 * color3) % mod;
        color3 = (2 * temp + 3 * color3) % mod;
    }
    return (color2 + color3) % mod;
}