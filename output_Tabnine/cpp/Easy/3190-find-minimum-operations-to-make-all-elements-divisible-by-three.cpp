/*
 You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
 Return the minimum number of operations to make all elements of nums divisible by 3.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 3
 Explanation:
 All array elements can be made divisible by 3 using 3 operations:
 Subtract 1 from 1.
 Add 1 to 2.
 Subtract 1 from 4.
 Example 2:
 Input: nums = [3,6,9]
 Output: 0
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count[3] = {0};
        for (int num : nums) {
            count[(num - 1) % 3]++;
        }
        
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            ans += min(count[i], count[(i + 1) % 3]);
        }
        
        return ans * 3; // multiply by 3 to get the minimum number of operations to make all elements divisible by 3.
        
    }
};