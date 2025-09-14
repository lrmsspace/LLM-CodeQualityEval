/*
 You are given an integer array nums.
 You can do the following operation on the array at most once:
 Choose any integer x such that nums remains non-empty on removing all occurrences of x.
 Remove all occurrences of x from the array.
 Return the maximum subarray sum across all possible resulting arrays.
 Example 1:
 Input: nums = [-3,2,-2,-1,3,-2,3]
 Output: 7
 Explanation:
 We can have the following arrays after at most one operation:
 The original array is nums = [-3, 2, -2, -1, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
 Deleting all occurences of x = -3 results in nums = [2, -2, -1, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
 Deleting all occurences of x = -2 results in nums = [-3, 2, -1, 3, 3]. The maximum subarray sum is 2 + (-1) + 3 + 3 = 7.
 Deleting all occurences of x = -1 results in nums = [-3, 2, -2, 3, -2, 3]. The maximum subarray sum is 3 + (-2) + 3 = 4.
 Deleting all occurences of x = 3 results in nums = [-3, 2, -2, -1, -2]. The maximum subarray sum is 2.
 The output is max(4, 4, 7, 4, 2) = 7.
 Example 2:
 Input: nums = [1,2,3,4]
 Output: 10
 Explanation:
 It is optimal to not perform any operations.
 Constraints:
 1 <= nums.length <= 105
 -106 <= nums[i] <= 106
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
    // Get unique elements to try removing each one
    set<int> unique(nums.begin(), nums.end());
    long long maxSum = INT_MIN;
    
    // Try removing each unique element
    for(int x : unique) {
        // Create temp array without element x
        vector<int> temp;
        for(int num : nums) {
            if(num != x) temp.push_back(num);
        }
        
        // Skip if array becomes empty
        if(temp.empty()) continue;
        
        // Calculate max subarray sum using Kadane's algorithm
        long long currSum = temp[0];
        long long bestSum = temp[0];
        
        for(int i = 1; i < temp.size(); i++) {
            currSum = max((long long)temp[i], currSum + temp[i]);
            bestSum = max(bestSum, currSum);
        }
        
        maxSum = max(maxSum, bestSum);
    }
    
    // Also try original array without removing anything
    long long currSum = nums[0];
    long long bestSum = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        currSum = max((long long)nums[i], currSum + nums[i]);
        bestSum = max(bestSum, currSum);
    }
    
    maxSum = max(maxSum, bestSum);
    
    return maxSum;
}           
};