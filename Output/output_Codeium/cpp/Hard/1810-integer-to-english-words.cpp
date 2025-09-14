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
        int thousand = num / 1000;
        int hundred = (num % 1000) / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;
        string res = "";
        if (thousand > 0) {
            res += helper(thousand) + " Thousand ";
        }
        if (hundred > 0) {
            res += helper(hundred) + " Hundred ";
        }
        if (ten > 1) {
            res += tens[ten] + " ";
        }
        if (ten == 1) {
            res += teens[one] + " ";
            return res;
        }
        if (one > 0) {
            res += ones[one] + " ";
        }
        return res;
        
    }
    string helper(int n) {
        if (n == 0) return "";
        if (n < 10) return ones[n];
        if (n < 20) return teens[n % 10];
        return tens[n / 10] + " " + ones[n % 10];
    }
    string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
};