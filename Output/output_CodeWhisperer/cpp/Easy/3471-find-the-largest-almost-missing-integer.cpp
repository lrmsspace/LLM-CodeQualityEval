/*
 You are given an integer array nums and an integer k.
 An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.
 Return the largest almost missing integer from nums. If no such integer exists, return -1.
 A subarray is a contiguous sequence of elements within an array.
 Example 1:
 Input: nums = [3,9,2,1,7], k = 3
 Output: 7
 Explanation:
 1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
 2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
 3 appears in 1 subarray of size 3: [3, 9, 2].
 7 appears in 1 subarray of size 3: [2, 1, 7].
 9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
 We return 7 since it is the largest integer that appears in exactly one subarray of size k.
 Example 2:
 Input: nums = [3,9,7,2,1,7], k = 4
 Output: 3
 Explanation:
 1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
 2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
 3 appears in 1 subarray of size 4: [3, 9, 7, 2].
 7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
 9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
 We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.
 Example 3:
 Input: nums = [0,0], k = 1
 Output: -1
 Explanation:
 There is no integer that appears in only one subarray of size 1.
 Constraints:
 1 <= nums.length <= 50
 0 <= nums[i] <= 50
 1 <= k <= nums.length
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    // Use map to store frequency of each number in each k-sized subarray
    unordered_map<int, int> freq;
    int n = nums.size();
    int result = -1;
    
    // Count frequency of each number in first k-sized window
    for(int i = 0; i < k; i++) {
        freq[nums[i]]++;
    }
    
    // Sliding window to count frequencies in all k-sized subarrays
    for(int i = k; i < n; i++) {
        // Remove frequency of number going out of window
        freq[nums[i-k]]--;
        // Add frequency of number coming into window
        freq[nums[i]]++;
    }
    
    // Check each unique number in nums
    for(int num : nums) {
        int count = 0;
        
        // Count in how many k-sized subarrays this number appears
        for(int i = 0; i <= n-k; i++) {
            bool found = false;
            // Check if number exists in current k-sized subarray
            for(int j = 0; j < k; j++) {
                if(nums[i+j] == num) {
                    found = true;
                    break;
                }
            }
            if(found) count++;
        }
        
        // If number appears in exactly one k-sized subarray
        // Update result if this is larger than current result
        if(count == 1) {
            result = max(result, num);
        }
    }
    
    return result;
}                
    
};