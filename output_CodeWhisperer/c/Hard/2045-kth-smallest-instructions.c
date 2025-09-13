/**https://leetcode.com/problems/kth-smallest-instructions/ */
//Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.
//The instructions are represented as a string, where each character is either:
//	'H', meaning move horizontally (go right), or
//	'V', meaning move vertically (go down).
//Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
//However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.
//Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.
// 
//Example 1:
//Input: destination = [2,3], k = 1
//Output: "HHHVV"
//Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
//["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
//Example 2:
//Input: destination = [2,3], k = 2
//Output: "HHVHV"
//Example 3:
//Input: destination = [2,3], k = 3
//Output: "HHVVH"
// 
//Constraints:
//	destination.length == 2
//	1 <= row, column <= 15
//	1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.
char* kthSmallestPath(int* destination, int destinationSize, int k) {
    int row = destination[0];
    int col = destination[1];
    int i, j;
    int dp[16][16] = {0};
    for (i = 0; i <= row; i++) {
        for (j = 0; j <= col; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (row + col + 1));
    int r = row;
    int c = col;
    int index = 0;
    while (r > 0 && c > 0) {
        if (k <= dp[r - 1][c]) {
            result[index++] = 'H';
            r--;
        } else {
            result[index++] = 'V';
            k -= dp[r - 1][c];
            c--;
        }
    }
    while (r > 0) {
        result[index++] = 'H';
        r--;
    }
    while (c > 0) {
        result[index++] = 'V';
        c--;
    }
    result[index] = '\0';
    return result;
}