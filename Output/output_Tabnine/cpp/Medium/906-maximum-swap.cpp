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
public:
    int maximumSwap(int num) {
        vector<int> digits = {};
        int maxDigit = 0;
        int maxIndex = 0;
        
        // Separate digits and find the maximum digit and its index
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (digit > maxDigit) {
                maxDigit = digit;
                maxIndex = digits.size();
            }
            digits.push_back(digit);
        }
        
        // Find the digit that can be swapped with the maximum digit
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < maxDigit) {
                // Swap the digits and return the new number
                int temp = digits[i];
                digits[i] = maxDigit;
                digits[maxIndex] = temp;
                break;
            }
        }
        
        // Convert the digits back to an integer
        int result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }
        
        return result;
        
    }
};