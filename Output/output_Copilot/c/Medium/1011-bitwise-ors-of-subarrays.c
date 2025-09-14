/**https://leetcode.com/problems/bitwise-ors-of-subarrays/ */
//Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
//The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: arr = [0]
//Output: 1
//Explanation: There is only one possible result: 0.
//Example 2:
//Input: arr = [1,1,2]
//Output: 3
//Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
//These yield the results 1, 1, 2, 1, 3, 3.
//There are 3 unique values, so the answer is 3.
//Example 3:
//Input: arr = [1,2,4]
//Output: 6
//Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	0 <= arr[i] <= 109
int subarrayBitwiseORs(int* arr, int arrSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[50000] = {0};
    int b[50000] = {0};
    int c[50000] = {0};
    int d[50000] = {0};
    int e[50000] = {0};
    int f[50000] = {0};
    int g[50000] = {0};
    int h[50000] = {0};
    int ans = 0;
    for(i = 0; i < arrSize; i++) {
        a[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        b[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        c[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        d[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        e[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        f[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        g[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        h[i] = arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        for(j = i; j < arrSize; j++) {
            if(i == j) {
                ans |= arr[i];
            } else {
                ans |= arr[j];
            }
        }
    }
    return ans;
}