/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.
// 
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//	0 <= num <= 108
class Solution {
    public int maximumSwap(int num) {
        String strNum = String.valueOf(num);
        int[] digits = new int[strNum.length()];
        for (int i = 0; i < strNum.length(); i++) {
            digits[i] = strNum.charAt(i) - '0';
        }
        
        int maxIndex = 0;
        for (int i = 1; i < digits.length; i++) {
            if (digits[i] > digits[maxIndex]) {
                maxIndex = i;
            }
        }
        
        if (maxIndex == 0) {
            return num;
        }
        
        int minIndex = maxIndex;
        for (int i = maxIndex + 1; i < digits.length; i++) {
            if (digits[i] < digits[minIndex] && digits[i] > digits[maxIndex]) {
                minIndex = i;
            }
        }
        
        int temp = digits[maxIndex];
        digits[maxIndex] = digits[minIndex];
        digits[minIndex] = temp;
        
        StringBuilder sb = new StringBuilder();
        for (int digit : digits) {
            sb.append(digit);
        }
        
        return Integer.parseInt(sb.toString());
        
    }
}