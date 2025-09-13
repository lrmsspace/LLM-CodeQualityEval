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
char* largestMultipleOfThree(int* digits, int digitsSize) {
    // Initialize count of digits for each number system
    int count[10] = {0};
    int sum = 0;
    
    // Count the number of digits and calculate the sum
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
        sum += digits[i];
    }
    
    // Check if the sum is divisible by 3
    if (sum % 3!= 0) {
        return "";
    }
    
    // Sort the digits array in descending order
    qsort(digits, digitsSize, sizeof(int), compare);
    
    // Create a string to store the result
    char* result = (char*)malloc(digitsSize + 1);
    result[digitsSize] = '\0';
    
    // Construct the largest multiple of three
    int i = digitsSize - 1;
    int carry = 0;
    while (i >= 0 && carry!= 0) {
        int digit = (digits[i] + carry) % 3;
        carry = (digits[i] + carry) / 3;
        result[i] = '0' + digit;
        count[digit]--;
        i--;
    }
    
    // Add remaining digits to the result
    while (i >= 0) {
        int digit = digits[i];
        for (int j = 9; j >= 0; j--) {
            if (count[j] > 0) {
                result[i] = '0' + j;
                count[j]--;
                break;
            }
        }
        i--;
    }
    
    // Remove unnecessary leading zeros
    int j = 0;
    while (j < digitsSize && result[j] == '0') {
        j++;
    }
    return &result[j];
    
}