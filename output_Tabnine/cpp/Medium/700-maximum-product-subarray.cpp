/**https://leetcode.com/problems/maximum-product-subarray/ */
//Given an integer array nums, find a subarray that has the largest product, and return the product.
//The test cases are generated so that the answer will fit in a 32-bit integer.
// 
//Example 1:
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-10 <= nums[i] <= 10
//	The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int max_here = nums[0], min_here = nums[0], max_so_far = nums[0];
        
        for (int i = 1; i < n; i++) {
            int temp = max_here;
            max_here = max(nums[i], max(nums[i] * max_here, nums[i] * min_here));
            min_here = min(nums[i], min(nums[i] * temp, nums[i] * min_here));
            
            max_so_far = max(max_so_far, max_here);
        }
        
        return max_so_far;
        
    }
};