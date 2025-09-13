/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
// 
//Example 1:
//Input: n = 2, m = 3
//Output: 3
//Explanation: 3 squares are necessary to cover the rectangle.
//2 (squares of 1x1)
//1 (square of 2x2)
//Example 2:
//Input: n = 5, m = 8
//Output: 5
//Example 3:
//Input: n = 11, m = 13
//Output: 6
// 
//Constraints:
//	1 <= n, m <= 13
int tilingRectangle(int n, int m) {
    if (n == m) {
        return 1;
    } else if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    if (n == 1) {
        return m;
    } else if (n == 2) {
        return m == 3 ? 3 : m / 2 + 1;
    } else {
        return m == 3 ? 3 : m / 2 + 1;
    }
        
}