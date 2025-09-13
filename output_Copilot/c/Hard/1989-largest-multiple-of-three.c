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
    int count[10] = {0};
    int sum = 0;
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
        sum += digits[i];
    }
    if (sum == 0) {
        return "0";
    }
    if (sum % 3 == 1) {
        if (remove(count, 1) || remove(count, 4) || remove(count, 7)) {
            sum -= 1;
        } else {
            remove(count, 2);
            remove(count, 2);
            sum -= 2;
        }
    } else if (sum % 3 == 2) {
        if (remove(count, 2) || remove(count, 5) || remove(count, 8)) {
            sum -= 2;
        } else {
            remove(count, 1);
            remove(count, 1);
            sum -= 2;
        }
    }
    char* result = (char*)malloc(sizeof(char) * (sum + 1));
    int index = 0;
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < count[i]; j++) {
            result[index++] = i + '0';
        }
    }
    result[index] = '\0';
    return result;    
}