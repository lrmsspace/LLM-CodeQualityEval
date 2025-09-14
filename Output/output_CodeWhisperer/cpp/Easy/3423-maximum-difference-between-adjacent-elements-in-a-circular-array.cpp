/*
 Given a circular array nums, find the maximum absolute difference between adjacent elements.
 Note: In a circular array, the first and last elements are adjacent.
 Example 1:
 Input: nums = [1,2,4]
 Output: 3
 Explanation:
 Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
 Example 2:
 Input: nums = [-5,-10,-5]
 Output: 5
 Explanation:
 The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.
 Constraints:
 2 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
    int maxDiff = 0;
    int n = nums.size();
    
    // Check difference between adjacent elements
    for(int i = 0; i < n-1; i++) {
        maxDiff = max(maxDiff, abs(nums[i] - nums[i+1]));
    }
    
    // Check difference between first and last element since array is circular
    maxDiff = max(maxDiff, abs(nums[0] - nums[n-1]));
    
    return maxDiff;
}                
};