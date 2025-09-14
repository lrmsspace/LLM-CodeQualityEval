/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        string res;
        for (string& s : strs) {
            res += s;
        }
        return res[0] == '0' ? "0" : res;     
    }
};