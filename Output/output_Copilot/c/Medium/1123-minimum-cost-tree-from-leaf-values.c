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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[40] = {0};
    int b[40] = {0};
    int c[40] = {0};
    int d[40] = {0};
    int e[40] = {0};
    int f[40] = {0};
    int g[40] = {0};
    int h[40] = {0};
    int ans = 0;
    for(i = 0; i < arrSize; i++) {
        a[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        b[i] = 0;
        for(j = 0; j < arrSize; j++) {
            if(j < i) {
                b[i] = max(b[i], arr[j]);
            } else if(j > i) {
                c[i] = max(c[i], arr[j]);
            }
        }
    }
    for(i = 0; i < arrSize - 1; i++) {
        d[i] = a[i] * a[i + 1];
    }
    for(i = 0; i < arrSize - 1; i++) {
        e[i] = b[i] * c[i];
    }
    for(i = 0; i < arrSize - 1; i++) {
        f[i] = min(d[i], e[i]);
    }
    for(i = 0; i < arrSize - 1; i++) {
        ans += f[i];
    }
    return ans; 
}