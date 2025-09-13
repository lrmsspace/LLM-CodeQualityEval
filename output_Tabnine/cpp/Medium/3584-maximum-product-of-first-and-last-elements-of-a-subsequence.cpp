/*
 You are given an integer array nums and an integer m.
 Return the maximum product of the first and last elements of any subsequence of nums of size m.
 Example 1:
 Input: nums = [-1,-9,2,3,-2,-3,1], m = 1
 Output: 81
 Explanation:
 The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.
 Example 2:
 Input: nums = [1,3,-5,5,6,-4], m = 3
 Output: 20
 Explanation:
 The subsequence [-5, 6, -4] has the largest product of the first and last elements.
 Example 3:
 Input: nums = [2,-1,2,-6,5,2,-5,7], m = 2
 Output: 35
 Explanation:
 The subsequence [5, 7] has the largest product of the first and last elements.
 Constraints:
 1 <= nums.length <= 105
 -105 <= nums[i] <= 105
 1 <= m <= nums.length
*/

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        // Your code here
        int n = nums.size();
        vector<long long> maxProd(n, 0);
        vector<long long> minProd(n, 0);
        
        maxProd[0] = nums[0];
        minProd[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            maxProd[i] = max(nums[i], maxProd[i - 1] * nums[i]);
            minProd[i] = min(nums[i], minProd[i - 1] * nums[i]);
        }
        
        long long maxProduct = maxProd[m - 1];
        
        for (int i = m; i < n; i++) {
            maxProduct = max(maxProduct, maxProd[i - 1] / minProd[i - m]);
        }
        
        return maxProduct;
        
    }
};