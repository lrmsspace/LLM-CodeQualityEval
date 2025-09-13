/**https://leetcode.com/problems/greatest-sum-divisible-by-three/ */
//Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.
// 
//Example 1:
//Input: nums = [3,6,5,1,8]
//Output: 18
//Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
//Example 2:
//Input: nums = [4]
//Output: 0
//Explanation: Since 4 is not divisible by 3, do not pick any number.
//Example 3:
//Input: nums = [1,2,3,4,4]
//Output: 12
//Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
// 
//Constraints:
//	1 <= nums.length <= 4 * 104
//	1 <= nums[i] <= 104
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 3 == 0) return sum;
        
        int target = 3 - (sum % 3);
        int i = 0, j = n - 1;
        int res = 0;
        
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                res += nums[i] + nums[j];
                i++;
                j--;
            } else {
                res += nums[j];
                j--;
            }
        }
        
        return res;  // Return the maximum possible sum of elements divisible by three.
        
    }
};