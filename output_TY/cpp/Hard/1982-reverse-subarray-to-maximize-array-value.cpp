/**https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ */
//You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
//You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
//Find maximum possible value of the final array.
// 
//Example 1:
//Input: nums = [2,3,1,5,4]
//Output: 10
//Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
//Example 2:
//Input: nums = [2,4,9,24,2,1,10]
//Output: 68
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-105 <= nums[i] <= 105
//	The answer is guaranteed to fit in a 32-bit integer.
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            ans += abs(nums[i] - nums[i + 1]);
        }
        int max_diff = 0;
        for(int i = 0; i < n - 1; i++){
            max_diff = max(max_diff, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            max_diff = max(max_diff, abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }
        return ans + max_diff;
    }
};