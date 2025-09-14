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
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        String[] thousands = {"", "Thousand", "Million", "Billion"};
        String result = "";
        for (int i = 0; i < 4; i++) {
            int threeDigits = num % 1000;
            if (threeDigits != 0) {
                result = helper(threeDigits) + thousands[i] + " " + result;
            }
            num /= 1000;
        }
        return result.trim();        
    }
}