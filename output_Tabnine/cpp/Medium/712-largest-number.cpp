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
        // Convert each number to a string and push them into a priority queue
        // The priority queue will automatically sort the strings based on their concatenated values
        priority_queue<string, vector<string>, greater<string>> pq;
        for (int num : nums) {
            pq.push(to_string(num));
        }
        
        // Construct the largest number by concatenating the strings from the priority queue
        string res = "";
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
            if (!pq.empty()) {
                res += pq.top();
                pq.pop();
            }
        }
        
        // Remove leading zeros from the result
        while (res.length() > 1 && res[0] == '0') {
            res = res.substr(1);
        }
        
        return res;
        
    }
};