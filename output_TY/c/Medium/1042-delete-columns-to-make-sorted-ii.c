/**https://leetcode.com/problems/delete-columns-to-make-sorted-ii/ */
//You are given an array of n strings strs, all of the same length.
//We may choose any deletion indices, and we delete all the characters in those indices for each string.
//For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
//Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.
// 
//Example 1:
//Input: strs = ["ca","bb","ac"]
//Output: 1
//Explanation: 
//After deleting the first column, strs = ["a", "b", "c"].
//Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
//We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
//Example 2:
//Input: strs = ["xc","yb","za"]
//Output: 0
//Explanation: 
//strs is already in lexicographic order, so we do not need to delete anything.
//Note that the rows of strs are not necessarily in lexicographic order:
//i.e., it is NOT necessarily true that (strs[0][0] <= strs[0][1] <= ...)
//Example 3:
//Input: strs = ["zyx","wvu","tsr"]
//Output: 3
//Explanation: We have to delete every column.
// 
//Constraints:
//	n == strs.length
//	1 <= n <= 100
//	1 <= strs[i].length <= 100
//	strs[i] consists of lowercase English letters.
int minDeletionSize(char ** strs, int strsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, i0, j0, k0, l0, m0, n0, o0, p0, q0, r0, s0, t0, u0, v0, w0, x0,y0, z0;
    int w01, x01, y01, z01;
    int w02, x02, y02, z02;
    for (i = 0; i < strsSize; i++) {
        for (j = 0; j < strs[i][j]; j++) {
            for (k = 0; k < strsSize; k++) {
                if (strs[i][j] > strs[k][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}