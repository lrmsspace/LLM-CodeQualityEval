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
        if (num == 0) return "Zero";
        
        vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string result;
        int i = 0;
        
        while (num > 0) {
            int digit3 = num % 1000;
            num /= 1000;
            
            if (digit3 > 0) {
                if (i > 0) result = thousands[i] + " " + result;
                result = helper(digit3) + " " + result;
            }
            
            i++;
        }
        
        return result.trim();
        
    }
};