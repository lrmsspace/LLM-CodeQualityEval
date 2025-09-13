/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1
class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = "";
        vector<string> v1 = {"", "Thousand", "Million", "Billion"};
        vector<string> v2 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> v3 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> v4 = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        int i = 0;
        while(num > 0) {
            if(num % 1000 != 0) {
                res = helper(num % 1000, v2, v3, v4) + v1[i] + " " + res;
            }
            num /= 1000;
            i++;
        }
        while(res.back() == ' ') res.pop_back();
        return res;        
    }
};