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
        StringBuilder sb = new StringBuilder();
        int billion = num / 1000000000;
        if (billion > 0) {
            sb.append(numberToWords(billion)).append(" Billion");
            num %= 1000000000;
        }
        int million = num / 1000000;
        if (million > 0) {
            if (sb.length() > 0) {
                sb.append(" ");
            }
            sb.append(numberToWords(million)).append(" Million");
            num %= 1000000;
        }
        int thousand = num / 1000;
        if (thousand > 0) {
            if (sb.length() > 0) {
                sb.append(" ");
            }
            sb.append(numberToWords(thousand)).append(" Thousand");
            num %= 1000;
        }
        if (num > 0) {
            if (sb.length() > 0) {
                sb.append(" ");
            }
            sb.append(numberToWords(num));
        }
        return sb.toString();
    }
}