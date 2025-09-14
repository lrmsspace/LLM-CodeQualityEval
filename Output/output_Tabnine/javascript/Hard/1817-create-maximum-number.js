/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.
// 
//Example 1:
//Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
//Output: [9,8,6,5,3]
//Example 2:
//Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
//Output: [6,7,6,0,4]
//Example 3:
//Input: nums1 = [3,9], nums2 = [8,9], k = 3
//Output: [9,8,9]
// 
//Constraints:
//	m == nums1.length
//	n == nums2.length
//	1 <= m, n <= 500
//	0 <= nums1[i], nums2[i] <= 9
//	1 <= k <= m + n
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[]}
 */
var maxNumber = function(nums1, nums2, k) {
    const maxSubarray = (nums, k) => {
        let n = nums.length, maxSum = 0;
        const dp = new Array(n + 1).fill(0);
        
        for (let i = 1; i <= n; i++) {
            let prevMax = 0;
            for (let j = i; j > 0 && j <= k; j--) {
                dp[j] = Math.max(dp[j], prevMax + nums[i - j]);
                prevMax = dp[j];
            }
            maxSum = Math.max(maxSum, dp[k]);
        }
        
        return maxSum;
    };
    
    const merge = (nums1, nums2, k) => {
        let m = nums1.length, n = nums2.length;
        const merged = [];
        
        while (m > 0 && n > 0 && k > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                merged.push(nums1[--m]);
                k--;
            } else if (nums1[m - 1] < nums2[n - 1]) {
                merged.push(nums2[--n]);
                k--;
            } else {
                if (maxSubarray(nums1.slice(0, m), k - 1) > maxSubarray(nums2.slice(0, n), k - 1)) {
                    merged.push(nums1[--m]);
                } else {
                    merged.push(nums2[--n]);
                }
                k--;
            }
        }
        
        while (m > 0) {
            merged.push(nums1[--m]);
        }
        
        while (n > 0) {
            merged.push(nums2[--n]);
        }
        
        return merged.slice(0, k);

    };
    
    return merge(nums1.slice().sort((a, b) => b - a), nums2.slice().sort((a, b) => b - a), k);
    
};