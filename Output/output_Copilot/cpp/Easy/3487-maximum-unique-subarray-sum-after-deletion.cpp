/*
 You are given an integer array nums.
 You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
 All elements in the subarray are unique.
 The sum of the elements in the subarray is maximized.
 Return the maximum sum of such a subarray.
 Example 1:
 Input: nums = [1,2,3,4,5]
 Output: 15
 Explanation:
 Select the entire array without deleting any element to obtain the maximum sum.
 Example 2:
 Input: nums = [1,1,0,1,1]
 Output: 1
 Explanation:
 Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.
 Example 3:
 Input: nums = [1,2,-1,-2,1,0,-1]
 Output: 3
 Explanation:
 Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.
 Constraints:
 1 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen; // To track unique elements
        int maxSum = 0; // To store the maximum sum of unique elements
        int currentSum = 0; // To store the current sum of the subarray

        for (int num : nums) {
            if (seen.find(num) == seen.end()) { // If the number is unique
                seen.insert(num); // Add it to the set
                currentSum += num; // Add to the current sum
            } else { // If the number is a duplicate
                maxSum = max(maxSum, currentSum); // Update maxSum if needed
                currentSum = num; // Start a new subarray with the current number
                seen.clear(); // Clear the set for the new subarray
                seen.insert(num); // Add the current number to the set
            }
        }

        maxSum = max(maxSum, currentSum); // Final check for the last subarray

        return maxSum; // Return the maximum sum found
        
    }
};