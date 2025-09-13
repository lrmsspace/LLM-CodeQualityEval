/*
 You are given two integer arrays, nums1 and nums2, both of length n, along with a positive integer k.
 For each index i from 0 to n - 1, perform the following:
 Find all indices j where nums1[j] is less than nums1[i].
 Choose at most k values of nums2[j] at these indices to maximize the total sum.
 Return an array answer of size n, where answer[i] represents the result for the corresponding index i.
 Example 1:
 Input: nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2
 Output: [80,30,0,80,50]
 Explanation:
 For i = 0: Select the 2 largest values from nums2 at indices [1, 2, 4] where nums1[j] < nums1[0], resulting in 50 + 30 = 80.
 For i = 1: Select the 2 largest values from nums2 at index [2] where nums1[j] < nums1[1], resulting in 30.
 For i = 2: No indices satisfy nums1[j] < nums1[2], resulting in 0.
 For i = 3: Select the 2 largest values from nums2 at indices [0, 1, 2, 4] where nums1[j] < nums1[3], resulting in 50 + 30 = 80.
 For i = 4: Select the 2 largest values from nums2 at indices [1, 2] where nums1[j] < nums1[4], resulting in 30 + 20 = 50.
 Example 2:
 Input: nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1
 Output: [0,0,0,0]
 Explanation:
 Since all elements in nums1 are equal, no indices satisfy the condition nums1[j] < nums1[i] for any i, resulting in 0 for all positions.
 Constraints:
 n == nums1.length == nums2.length
 1 <= n <= 105
 1 <= nums1[i], nums2[i] <= 106
 1 <= k <= n
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* findMaxSum(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    
    *returnSize = 2;
    long long* ret = (long long*)malloc(sizeof(long long) * 2);
    ret[0] = ret[1] = 0;
    if (k == 0) {
        return ret;
    }
    if (k == 1) {
        ret[0] = nums1[0];
        ret[1] = nums2[0];
        return ret;
    }
    if (nums1Size == 0) {
        ret[0] = 0;
        ret[1] = nums2[0];
        return ret;
    }
    if (nums2Size == 0) {
        ret[0] = nums1[0];
        ret[1] = 0;
        return ret;
    }
    for (int i = 0; i < k; i++) { 
        ret[i] = nums1[i] + nums2[i];
    }
    return ret;
}