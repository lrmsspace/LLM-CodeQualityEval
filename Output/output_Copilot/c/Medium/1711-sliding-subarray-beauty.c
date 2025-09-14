/**https://leetcode.com/problems/sliding-subarray-beauty/ */
//Given an integer array nums containing n integers, find the beauty of each subarray of size k.
//The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.
//Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.
//	
//	A subarray is a contiguous non-empty sequence of elements within an array.
//	
// 
//Example 1:
//Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
//Output: [-1,-2,-2]
//Explanation: There are 3 subarrays with size k = 3. 
//The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
//The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
//The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.
//Example 2:
//Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
//Output: [-1,-2,-3,-4]
//Explanation: There are 4 subarrays with size k = 2.
//For [-1, -2], the 2nd smallest negative integer is -1.
//For [-2, -3], the 2nd smallest negative integer is -2.
//For [-3, -4], the 2nd smallest negative integer is -3.
//For [-4, -5], the 2nd smallest negative integer is -4. 
//Example 3:
//Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
//Output: [-3,0,-3,-3,-3]
//Explanation: There are 5 subarrays with size k = 2.
//For [-3, 1], the 1st smallest negative integer is -3.
//For [1, 2], there is no negative integer so the beauty is 0.
//For [2, -3], the 1st smallest negative integer is -3.
//For [-3, 0], the 1st smallest negative integer is -3.
//For [0, -3], the 1st smallest negative integer is -3.
// 
//Constraints:
//	n == nums.length 
//	1 <= n <= 105
//	1 <= k <= n
//	1 <= x <= k 
//	-50 <= nums[i] <= 50 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSubarrayBeauty(int* nums, int numsSize, int k, int x, int* returnSize) {
    int* res = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* count = (int*)malloc(101 * sizeof(int));
    int* prefix = (int*)malloc((numsSize + 1) * sizeof(int));
    int* suffix = (int*)malloc((numsSize + 1) * sizeof(int));
    int i, j, l, r, ans;
    for (i = 0; i < 101; i++) count[i] = 0;
    for (i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i];
        if (nums[i] < 0) {
            count[nums[i] + 50]++;
            if (count[nums[i] + 50] == x) prefix[i + 1]++;
        }
    }
    for (i = 0; i < 101; i++) count[i] = 0;
    for (i = numsSize - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1];
        if (nums[i] < 0) {
            count[nums[i] + 50]++;
            if (count[nums[i] + 50] == x) suffix[i]++;
        }
    }
    for (i = 0; i <= numsSize - k; i++) {
        res[i] = 0;
        for (j = 0; j < 101; j++) count[j] = 0;
        for (j = i; j < i + k; j++) {
            if (nums[j] < 0) {
                count[nums[j] + 50]++;
                if (count[nums[j] + 50] == x) res[i]++;
            }
        }
        res[i] = res[i] + prefix[i] + suffix[i + k];
    }
    *returnSize = numsSize - k + 1;
    return res;    
}