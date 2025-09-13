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
            
            string result = "";
            int billion = num / 1000000000;
            int million = (num % 1000000000) / 1000000;
            int thousand = (num % 1000000) / 1000;
            int rest = num % 1000;
            
            if (billion) result += threeDigits(billion) + " Billion";
            if (million) result += threeDigits(million) + " Million";
            if (thousand) result += threeDigits(thousand) + " Thousand";
            if (rest) result += threeDigits(rest);
            
            // Remove leading space if it exists
            return result.substr(1);
        }
        
    private:
        // Arrays for word representations
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                              "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        // Helper function to convert a number less than 1000 to words
        string threeDigits(int num) {
            string result = "";
            
            if (num >= 100) {
                result += " " + ones[num / 100] + " Hundred";
                num %= 100;
            }
            
            if (num > 0) {
                if (num < 20) {
                    result += " " + ones[num];
                } else {
                    result += " " + tens[num / 10];
                    if (num % 10 > 0) {
                        result += " " + ones[num % 10];
                    }
                }
            }
            
            return result;
        }
    };
    