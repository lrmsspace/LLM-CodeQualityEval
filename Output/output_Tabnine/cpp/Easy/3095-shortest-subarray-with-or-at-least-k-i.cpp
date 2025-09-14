/*
 You are given an array nums of non-negative integers and an integer k.
 An array is called special if the bitwise OR of all of its elements is at least k.
 Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.
 Example 1:
 Input: nums = [1,2,3], k = 2
 Output: 1
 Explanation:
 The subarray [3] has OR value of 3. Hence, we return 1.
 Note that [2] is also a special subarray.
 Example 2:
 Input: nums = [2,1,8], k = 10
 Output: 3
 Explanation:
 The subarray [2,1,8] has OR value of 11. Hence, we return 3.
 Example 3:
 Input: nums = [1,2], k = 0
 Output: 1
 Explanation:
 The subarray [1] has OR value of 1. Hence, we return 1.
 Constraints:
 1 <= nums.length <= 50
 0 <= nums[i] <= 50
 0 <= k < 64
*/

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0, minLen = INT_MAX;
        
        while (right < n) {
            sum += nums[right];
            while (sum >= k) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        
        return minLen == INT_MAX? -1 : minLen;
        
    }
};