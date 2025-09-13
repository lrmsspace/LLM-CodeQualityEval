/*
 You are given a 0-indexed array nums of non-negative integers, and two integers l and r.
 Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].
 Since the answer may be large, return it modulo 109 + 7.
 A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.
 Note that:
 Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
 The sum of an empty multiset is 0.
 Example 1:
 Input: nums = [1,2,2,3], l = 6, r = 6
 Output: 1
 Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
 Example 2:
 Input: nums = [2,1,4,2,7], l = 1, r = 5
 Output: 7
 Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
 Example 3:
 Input: nums = [1,2,1,3,5,2], l = 3, r = 5
 Output: 9
 Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.
 Constraints:
 1 <= nums.length <= 2 * 104
 0 <= nums[i] <= 2 * 104
 Sum of nums does not exceed 2 * 104.
 0 <= l <= r <= 2 * 104
*/

class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
    const int MOD = 1e9 + 7;
    map<int, int> freq;
    for (int x : nums) freq[x]++;
    
    // dp[i] represents number of submultisets with sum i
    vector<long long> dp(r + 1);
    dp[0] = 1;
    
    for (auto [num, count] : freq) {
        if (num == 0) continue;
        
        // For each sum i, add combinations using current number
        for (int sum = r; sum >= 0; sum--) {
            long long val = dp[sum];
            long long mul = 1;
            
            // Try adding current number 1 to count times
            for (int k = 1; k <= count && sum + k * num <= r; k++) {
                mul = (mul * (count - k + 1)) / k; // Calculate combinations
                dp[sum + k * num] = (dp[sum + k * num] + val * mul) % MOD;
            }
        }
    }
    
    // Handle zero separately since it can be added to any subset
    long long ans = 0;
    long long zeroMul = freq[0] + 1;
    
    // Sum up all values in range [l,r]
    for (int i = l; i <= r; i++) {
        ans = (ans + dp[i] * zeroMul) % MOD;
    }
    
    return ans;
}                    
};