/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.
// 
//Example 1:
//Input: num = 310
//Output: 103
//Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
//The arrangement with the smallest value that does not contain any leading zeros is 103.
//Example 2:
//Input: num = -7605
//Output: -7650
//Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
//The arrangement with the smallest value that does not contain any leading zeros is -7650.
// 
//Constraints:
//	-1015 <= num <= 1015
long long smallestNumber(long long num) {
    std::string numStr = std::to_string(std::abs(num));
    std::vector<int> digits(numStr.size());
    std::vector<bool> used(numStr.size(), false);
    
    for (int i = 0; i < numStr.size(); ++i) {
        digits[i] = numStr[i] - '0';
    }
    
    std::sort(digits.begin(), digits.end(), [](int a, int b) {
        return a > b;
    });
    
    long long result = 0;
    bool isNegative = num < 0;
    
    for (int i = 0; i < numStr.size(); ++i) {
        if (!used[i]) {
            result = result * 10 + digits[i];
            used[i] = true;
        }
    }
    
    return isNegative? -result : result;
    
}