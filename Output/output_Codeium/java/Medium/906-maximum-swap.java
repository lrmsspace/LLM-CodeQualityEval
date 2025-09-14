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
        int[] digits = new int[String.valueOf(num).length()];
        int i = 0;
        while (num > 0) {
            digits[i++] = num % 10;
            num /= 10;
        }
        
        int maxIndex = 0;
        int maxDigit = 0;
        for (int j = digits.length - 1; j >= 0; j--) {
            if (digits[j] > maxDigit) {
                maxDigit = digits[j];
                maxIndex = j;
            }
        }
        
        int firstIndex = -1;
        for (int j = 0; j < digits.length; j++) {
            if (digits[j] < maxDigit) {
                firstIndex = j;
                break;
            }
        }
        
        if (firstIndex != -1) {
            int temp = digits[maxIndex];
            digits[maxIndex] = digits[firstIndex];
            digits[firstIndex] = temp;
        }
        
        int result = 0;
        for (int j = digits.length - 1; j >= 0; j--) {
            result = result * 10 + digits[j];
        }
        
        return result;
    }
}