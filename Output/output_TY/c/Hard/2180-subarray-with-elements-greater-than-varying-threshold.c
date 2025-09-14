/**https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/ */
//You are given an integer array nums and an integer threshold.
//Find any subarray of nums of length k such that every element in the subarray is greater than threshold / k.
//Return the size of any such subarray. If there is no such subarray, return -1.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,3,4,3,1], threshold = 6
//Output: 3
//Explanation: The subarray [3,4,3] has a size of 3, and every element is greater than 6 / 3 = 2.
//Note that this is the only valid subarray.
//Example 2:
//Input: nums = [6,5,6,5,8], threshold = 7
//Output: 1
//Explanation: The subarray [8] has a size of 1, and 8 > 7 / 1 = 7. So 1 is returned.
//Note that the subarray [6,5] has a size of 2, and every element is greater than 7 / 2 = 3.5. 
//Similarly, the subarrays [6,5,6], [6,5,6,5], [6,5,6,5,8] also satisfy the given conditions.
//Therefore, 2, 3, 4, or 5 may also be returned.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], threshold <= 109
int validSubarraySize(int* nums, int numsSize, int threshold){        
    int i, j, k, l, r, m, n, t, a[numsSize], b[numsSize], c[numsSize], d[numsSize], e[numsSize], f[numsSize], g[numsSize], h[numsSize], u, v, w, x, y, z;
    for (i = 0; i < numsSize; i++) a[i] = nums[i] > threshold / (i + 1) ? 1 : 0;
    for (i = 0; i < numsSize; i++) b[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) c[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) d[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) e[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) f[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) g[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) h[i] = a[i] ? 1 : -1;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (j == i) {
                u = 0;
                v = 0;
                w = 0;
                x = 0;
                y = 0;
                z = 0;
            } else {
                u = b[j - 1];
                v = c[j - 1];
                w = d[j - 1];
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (j == i) {
                u = 0;
                v = 0;
                w = 0;
                x = 0;
                y = 0;
                z = 0;
            } else {
                u = e[j - 1];
                v = f[j - 1];
                w = g[j - 1];
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (j == i) {
                u = 0;
                v = 0;
                w = 0;
                x = 0;
                y = 0;
                z = 0;
            } else {
                u = h[j -1];
            }
        }
    }
    return -1;
}