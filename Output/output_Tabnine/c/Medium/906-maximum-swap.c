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
int maximumSwap(int num) {
    int[] digits = new int[10];
    int maxDigit = 0;
    int maxDigitIndex = 0;
    
    // Count the occurrences of each digit
    for (int i = 0; num > 0; num /= 10) {
        int digit = num % 10;
        digits[digit]++;
        if (digit > maxDigit) {
            maxDigit = digit;
            maxDigitIndex = i;
        }
    }
    
    // Find the first digit that is greater than maxDigit
    for (int i = 9; i > maxDigitIndex; i--) {
        if (digits[i] > 0) {
            // Swap the maxDigit with the first greater digit
            int temp = digits[maxDigit];
            digits[maxDigit] = digits[i];
            digits[i] = temp;
            
            // Convert the digits array back to an integer
            int result = 0;
            for (int j = 0; j < 10; j++) {
                result = result * 10 + digits[j];
            }
            
            return result;
        }
    }
    
    // If no swap is possible, return the original number
    return num;
}