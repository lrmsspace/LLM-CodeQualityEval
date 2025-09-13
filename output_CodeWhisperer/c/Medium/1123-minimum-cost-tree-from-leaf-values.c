/**https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/ */
//Given an array arr of positive integers, consider all binary trees such that:
//	Each node has either 0 or 2 children;
//	The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//	The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
//Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
//A node is a leaf if and only if it has zero children.
// 
//Example 1:
//Input: arr = [6,2,4]
//Output: 32
//Explanation: There are two possible trees shown.
//The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
//Example 2:
//Input: arr = [4,11]
//Output: 44
// 
//Constraints:
//	2 <= arr.length <= 40
//	1 <= arr[i] <= 15
//	It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
int mctFromLeafValues(int* arr, int arrSize) {
    int dp[arrSize][arrSize];
    for (int i = 0; i < arrSize; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= arrSize; len++) {
        for (int i = 0; i <= arrSize - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int maxLeft = 0;
                for (int l = i; l <= k; l++) {
                    maxLeft = fmax(maxLeft, arr[l]);
                }
                int maxRight = 0;
                for (int l = k + 1; l <= j; l++) {
                    maxRight = fmax(maxRight, arr[l]);
                }
                dp[i][j] = fmin(dp[i][j], dp[i][k] + dp[k + 1][j] + maxLeft * maxRight);
            }
        }
    }
    return dp[0][arrSize - 1];
}