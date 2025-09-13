/**https://leetcode.com/problems/unique-binary-search-trees/ */
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// 
//Example 1:
//Input: n = 3
//Output: 5
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 19
int numTrees(int n) {
    int G[20] = {1};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i/2; ++j)
            G[i] += G[j-1] * G[i-j];
        if (i % 2 == 1) G[i] += G[i/2] * G[i/2];
    }
    return G[n];
}