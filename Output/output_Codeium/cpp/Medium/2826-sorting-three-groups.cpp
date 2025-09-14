/*
 You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
 Example 1:
 Input: nums = [2,1,3,2,1]
 Output: 3
 Explanation:
 One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
 Example 2:
 Input: nums = [1,3,2,1,3,3]
 Output: 2
 Explanation:
 One of the optimal solutions is to remove nums[1] and nums[2].
 Example 3:
 Input: nums = [2,2,2,2,3,3]
 Output: 0
 Explanation:
 nums is already non-decreasing.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 3
 Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0, count3 = 0;

        for (int num : nums) {
            if (num == 1) count1++;
            else if (num == 2) count2++;
            else if (num == 3) count3++;
        }

        // To make the array non-decreasing, we can remove elements to have fewer '1's followed by '2's and then '3's.
        int remove1 = n - count1; // Remove elements to have all '1's followed by '2's and '3's
        int remove2 = n - count2; // Remove elements to have all '2's followed by '1's and '3's
        int remove3 = n - count3; // Remove elements to have all '3's followed by '1's and '2's

        return std::min({remove1, remove2, remove3});

    }
};