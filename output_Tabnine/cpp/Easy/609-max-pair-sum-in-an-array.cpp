/**https://leetcode.com/problems/max-pair-sum-in-an-array/ */
//You are given an integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the largest digit in both numbers is equal.
//For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.
//Return the maximum sum or -1 if no such pair exists.
// 
//Example 1:
//Input: nums = [112,131,411]
//Output: -1
//Explanation:
//Each numbers largest digit in order is [2,3,4].
//Example 2:
//Input: nums = [2536,1613,3366,162]
//Output: 5902
//Explanation:
//All the numbers have 6 as their largest digit, so the answer is 2536 + 3366 = 5902.
//Example 3:
//Input: nums = [51,71,17,24,42]
//Output: 88
//Explanation:
//Each number's largest digit in order is [5,7,7,4,4].
//So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.
// 
//Constraints:
//	2 <= nums.length <= 100
//	1 <= nums[i] <= 104
class Solution {
public:
    int maxSum(vector<int>& nums) {

        // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Iterate over the array and find the largest digit
        int maxDigit = 0;
        for (int num : nums) {
            int digit = num % 10;
            if (digit > maxDigit) {
                maxDigit = digit;
            }
        }
        
        // Check if there are any pairs with the largest digit
        int maxSum = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int digit = nums[i] % 10;
            if (digit == maxDigit) {
                maxSum = max(maxSum, nums[i] + nums[i+1]);
            }
        }
        
        return maxSum;
        
    }
};