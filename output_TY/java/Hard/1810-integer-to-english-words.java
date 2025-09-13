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
        if (num == 0) {
            return "Zero";
        }
        String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        String[] thousands = {"", "Thousand", "Million", "Billion"};
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < thousands.length; i++) {
            int group = num / (int) Math.pow(1000, i);
            if (group > 0) {
                int h = group / 100;
                int t = (group - h * 100) / 10;
                int o = group - h * 100 - t * 10;
                if (h > 0) {
                    sb.append(ones[h] + " Hundred ");
                }
                if (t == 1) {
                    sb.append(ones[t * 10 + o] + " ");
                } else {
                    if (t > 0) {
                        sb.append(tens[t] + " ");
                    }
                }
            }
        }
        return sb.toString().trim();
    }
}