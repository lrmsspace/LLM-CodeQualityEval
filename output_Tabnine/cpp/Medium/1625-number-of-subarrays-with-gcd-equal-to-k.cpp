/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.
// 
//Example 1:
//Input: nums = [9,3,1,2,6,3], k = 3
//Output: 4
//Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//Example 2:
//Input: nums = [4], k = 7
//Output: 0
//Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i], k <= 109
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] * nums[i] % k;
        }
        
        unordered_map<int, int> count;
        count[0] = 1;
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += count[prefix[i] % k];
            ++count[prefix[i]];
        }
        
        return result;
        
    }
};