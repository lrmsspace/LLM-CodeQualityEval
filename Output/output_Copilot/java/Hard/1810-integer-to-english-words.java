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
        String[] belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                 "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        String[] tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", 
                         "Eighty", "Ninety"};

        StringBuilder result = new StringBuilder();
        int i = 0;
        
        while (num > 0) {
            if (num % 1000 != 0) {
                result.insert(0, convertLessThanThousand(num % 1000) + thousands[i] + " ");
            }
            num /= 1000;
            i++;
        }
        
        return result.toString().trim(); // Remove trailing space    
    }
}