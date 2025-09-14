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
        StringBuilder res = new StringBuilder();
        if (num == 0) return "Zero";
        
        String[] units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        String[] teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        String[] tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        String[] thousands = {"", "Thousand", "Million", "Billion"};
        
        for (int i = thousands.length - 1; i >= 0 && num > 0; i--) {
            int count = num / (int) Math.pow(1000, i);
            num %= (int) Math.pow(1000, i);
            
            if (count > 0) {
                res.append(numberToWords(count) + " " + thousands[i] + " ");
            }
        }
        
        if (num == 0) return res.toString().trim();
        
        if (num >= 100) {
            res.append(units[num / 100] + " Hundred ");
            num %= 100;
        }
        
        if (num >= 20) {
            res.append(tens[num / 10] + " ");
            num %= 10;
        }
        
        if (num > 0) {
            res.append(units[num]);
        }
        
        return res.toString().trim();
    }
}