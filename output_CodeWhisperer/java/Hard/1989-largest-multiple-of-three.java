/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] count = new int[10];
        int sum = 0;
        for (int digit : digits) {
            count[digit]++;
            sum += digit;
        }
        boolean[] removed = new boolean[digits.length];
        while (sum % 3 != 0) {
            boolean found = false;
            for (int i = 1; i <= 2; i++) {
                if (sum % 3 == i) {
                    for (int j = 1; j <= 9; j += 3) {
                        if (count[j] > 0) {
                            count[j]--;
                            sum -= j;
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
            if (!found) {
                return "";
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 9; i >= 0; i--) {
            while (count[i]-- > 0) {
                sb.append(i);
            }
        }
        if (sb.length() > 0 && sb.charAt(0) == '0') {
            return "0";
        }
        return sb.toString();      
    }
}