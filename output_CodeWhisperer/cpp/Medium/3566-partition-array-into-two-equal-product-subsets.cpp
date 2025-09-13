/*
 You are given an integer array nums containing distinct positive integers and an integer target.
 Determine if you can partition nums into two non-empty disjoint subsets, with each element belonging to exactly one subset, such that the product of the elements in each subset is equal to target.
 Return true if such a partition exists and false otherwise.
 A subset of an array is a selection of elements of the array.
 Example 1:
 Input: nums = [3,1,6,8,4], target = 24
 Output: true
 Explanation: The subsets [3, 8] and [1, 6, 4] each have a product of 24. Hence, the output is true.
 Example 2:
 Input: nums = [2,5,3,7], target = 15
 Output: false
 Explanation: There is no way to partition nums into two non-empty disjoint subsets such that both subsets have a product of 15. Hence, the output is false.
 Constraints:
 3 <= nums.length <= 12
 1 <= target <= 1015
 1 <= nums[i] <= 100
 All elements of nums are distinct.
*/

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
    int n = nums.size();
    vector<vector<long long>> dp(1 << n);
    
    // Calculate product for each subset
    for(int mask = 0; mask < (1 << n); mask++) {
        long long prod = 1;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                prod *= nums[i];
            }
        }
        dp[mask] = prod;
    }
    
    // Check all possible partitions
    for(int mask = 1; mask < (1 << n) - 1; mask++) {
        int complement = ((1 << n) - 1) ^ mask;
        if(dp[mask] == target && dp[complement] == target) {
            return true;
        }
    }
    
    return false;
}                
};