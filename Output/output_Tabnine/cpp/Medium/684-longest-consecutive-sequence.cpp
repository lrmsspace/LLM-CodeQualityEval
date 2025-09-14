/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
// 
//Example 1:
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//Example 2:
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 
//Constraints:
//	0 <= nums.length <= 105
//	-109 <= nums[i] <= 109
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums) {
            if (numSet.find(num) == numSet.end()) continue;
            numSet.erase(num);
            int left = num - 1, right = num + 1;
            while (numSet.find(left)!= numSet.end()) numSet.erase(left--);
            while (numSet.find(right)!= numSet.end()) numSet.erase(right++);
            longest = max(longest, right - left - 1);
        }
        return longest;
        
    }
};