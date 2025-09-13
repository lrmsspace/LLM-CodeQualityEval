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
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        if (numStrings[0] == "0") return "0";
        
        string result;
        for (const string& numStr : numStrings) {
            result += numStr;
        }
        
        return result;

    }
};