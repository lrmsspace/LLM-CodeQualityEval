/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int andValue = nums[i];
            if (andValue == k) {
                count++;
            }
            for (int j = i + 1; j < n; ++j) {
                andValue &= nums[j];
                if (andValue == k) {
                    count++;
                } else if (andValue < k) {
                    break; // No need to continue if AND value is less than k
                }
            }
        }
        
        return count;   
        
    }
};