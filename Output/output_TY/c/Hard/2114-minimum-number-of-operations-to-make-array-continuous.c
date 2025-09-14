/**https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/ */
//You are given an integer array nums. In one operation, you can replace any element in nums with any integer.
//nums is considered continuous if both of the following conditions are fulfilled:
//	All elements in nums are unique.
//	The difference between the maximum element and the minimum element in nums equals nums.length - 1.
//For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.
//Return the minimum number of operations to make nums continuous.
// 
//Example 1:
//Input: nums = [4,2,5,3]
//Output: 0
//Explanation: nums is already continuous.
//Example 2:
//Input: nums = [1,2,3,5,6]
//Output: 1
//Explanation: One possible solution is to change the last element to 4.
//The resulting array is [1,2,3,5,4], which is continuous.
//Example 3:
//Input: nums = [1,10,100,1000]
//Output: 3
//Explanation: One possible solution is to:
//- Change the second element to 2.
//- Change the third element to 3.
//- Change the fourth element to 4.
//The resulting array is [1,2,3,4], which is continuous.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
int minOperations(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i1, j1, k1, l1, m1, n1, o1, p1,q1, r1, s1, t1, u1, v     = 0;
    for (i = 0; i < numsSize; i++) {
        a[nums[i]] = 1;
    }
    for (i = 0; i < 100000; i++) {
        if (a[i] == 1) {
            b[v] = i;
            v++;
        }
    }
    for (i = 0; i < v; i++) {
        c[i] = b[i] - b[0];
    }
    for (i = 0; i < v; i++) {
        d[i] = c[i] + 1;
    }
    for (i = 0; i < v; i++) {
        e[i] = d[i] - v;
    }
    for (i = 0; i < v; i++) {
        f[i] = e[i] + 1;
    }
    for (i = 0; i < v; i++) {
        g[i] = f[i] + 1;
    }
    for (i = 0; i < v; i++) {
        h[i] = g[i] + 1;
    }
    for (i = 0; i < v; i++) {
        if (h[i] < 0) {
            h[i] = 0;
        }
    }
    return h[v - 1];
}