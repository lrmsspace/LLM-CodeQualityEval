/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
int numDupDigitsAtMostN(int n) {
    // Convert the number to a string for easier manipulation
    string numStr = to_string(n);
    
    // Count the number of digits in the number
    int numDigits = numStr.size();
    
    // If the number of digits is less than 2, there are no repeated digits
    if (numDigits < 2) {
        return 0;
    }
    
    // Initialize variables
    int result = 0;
    vector<int> count(10, 0); // Count the frequency of each digit
    
    // Calculate the number of valid digits for each position
    for (int i = 0; i < numDigits - 1; i++) {
        int digit = numStr[i] - '0';
        result += 9 * count[digit];
        
        // Update the count of the current digit
        if (i < numDigits - 2) {
            count[digit]--;
        }
        
        // Skip the current digit if it is the maximum possible
        if (digit == 9) {
            break;
        }
    }
    
    // Calculate the remaining digits
    int remainingDigits = n - stoi(numStr.substr(0, numDigits - 1));
    result += remainingDigits + 1;
    
    return result;
    
}