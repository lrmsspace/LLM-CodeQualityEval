/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == a) {
                c1++;
            } else if (num == b) {
                c2++;
            } else if (c1 == 0) {
                a = num;
                c1 = 1;
            } else if (c2 == 0) {
                b = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == a) {
                c1++;
            } else if (num == b) {
                c2++;
            }
        }
        vector<int> result;
        if (c1 > n / 3) {
            result.push_back(a);
        }
        if (c2 > n / 3) {
            result.push_back(b);
        }
        return result;     
    }
};