/**https://leetcode.com/problems/maximum-equal-frequency/ */
//Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
//If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).
// 
//Example 1:
//Input: nums = [2,2,1,1,5,3,3,5]
//Output: 7
//Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4] = 5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
//Example 2:
//Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
//Output: 13
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i] <= 105
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        unordered_map<int, int> freq;
        int max_freq = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (count[num] > 0) {
                freq[count[num]]--;
            }
            count[num]++;
            freq[count[num]]++;
            max_freq = max(max_freq, count[num]);
            if (max_freq == 1) {
                result = i + 1;
            } else if (freq[max_freq] * max_freq + freq[max_freq - 1] * (max_freq - 1) == i + 1 && freq[max_freq] == 1) {
                result = i + 1;
            } else if (freq[max_freq] * max_freq + 1 == i + 1 && freq[1] == 1) {
                result = i + 1;
            }
        }
        return result;
    }
};