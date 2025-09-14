/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [1,0,1,0,1], goal = 2
//Output: 4
//Explanation: The 4 subarrays are bolded and underlined below:
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//Example 2:
//Input: nums = [0,0,0,0,0], goal = 0
//Output: 15
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	nums[i] is either 0 or 1.
//	0 <= goal <= nums.length
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < n)
        {
            sum += nums[right];
            while (left <= right && sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            if (sum == goal)
            {
                int temp = 0;
                int temp2 = 0;
                for (int i = right; i >= left; i--)
                {
                    temp += nums[i];
                    if (temp == goal)
                   {
                      temp2++;
                   }
                   else
                   {
                       break;
                   }
                }
            }
        }
        return ans;
    }
};