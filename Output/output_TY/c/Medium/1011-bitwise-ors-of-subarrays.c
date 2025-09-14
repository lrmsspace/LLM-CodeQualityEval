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


int subarrayBitwiseORs(int* arr, int arrSize){
    int ans = 0;
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a = (int *)malloc(arrSize * sizeof(int));
    int *b = (int *)malloc(arrSize * sizeof(int));
    int *c = (int *)malloc(arrSize * sizeof(int));
    int *d = (int *)malloc(arrSize * sizeof(int));
    int *e = (int *)malloc(arrSize * sizeof(int));
    int *f = (int *)malloc(arrSize * sizeof(int));
    for (i = 0; i < arrSize; i++) {
        a[i] = arr[i];
    }
    for (i = 0; i < arrSize; i++) {
        b[i] = arr[i];
        c[i] = arr[i];
        d[i] = arr[i];
        e[i] = arr[i];
        f[i] = arr[i];
    }
    for (i = 1; i < arrSize; i++) {
        a[i] |= a[i - 1];
        b[i] ^= b[i - 1];
        c[i] &= c[i - 1];
    }
    for (i = arrSize - 2; i >= 0; i--) {
        d[i] |= d[i + 1];
        e[i] ^= e[i + 1];
        f[i] &= f[i + 1];
    }
    for (i = 0; i < arrSize; i++) {
        ans += a[i] | b[i] | c[i] | d[i] | e[i] | f[i];
    }
    return ans;
}