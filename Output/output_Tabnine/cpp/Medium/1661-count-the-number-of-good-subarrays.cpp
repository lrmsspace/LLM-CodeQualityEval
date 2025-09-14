/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], k = 10
//Output: 1
//Explanation: The only good subarray is the array nums itself.
//Example 2:
//Input: nums = [3,1,4,3,2,2,4], k = 2
//Output: 4
//Explanation: There are 4 different good subarrays:
//- [3,1,4,3,2,2] that has 2 pairs.
//- [3,1,4,3,2,2,4] that has 3 pairs.
//- [1,4,3,2,2,4] that has 2 pairs.
//- [4,3,2,2,4] that has 2 pairs.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], k <= 109
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            left[i] = nums[i] ^ left[i - 1];
        }
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = nums[i] ^ right[i + 1];
        }
        
        long long ans = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            ans += (left[i] == 0 && right[i + k - 1] == 0);
        }
        
        return ans;
        
    }
};