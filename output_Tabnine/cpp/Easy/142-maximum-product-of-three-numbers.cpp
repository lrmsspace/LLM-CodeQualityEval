/**https://leetcode.com/problems/maximum-product-of-three-numbers/ */
//Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 6
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 24
//Example 3:
//Input: nums = [-1,-2,-3]
//Output: -6
// 
//Constraints:
//	3 <= nums.length <= 104
//	-1000 <= nums[i] <= 1000
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);  // Compare the three possible products: the first three numbers multiplied, the last three numbers multiplied, and the largest and second largest numbers multiplied.
        
    }
};