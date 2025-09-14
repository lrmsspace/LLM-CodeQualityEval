/*
 You are given a string s.
 Your task is to remove all digits by doing this operation repeatedly:
 Delete the first digit and the closest non-digit character to its left.
 Return the resulting string after removing all digits.
 Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.
 Example 1:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no digit in the string.
 Example 2:
 Input: s = "cb34"
 Output: ""
 Explanation:
 First, we apply the operation on s[2], and s becomes "c4".
 Then we apply the operation on s[1], and s becomes "".
 Constraints:
 1 <= s.length <= 100
 s consists only of lowercase English letters and digits.
 The input is generated such that it is possible to delete all digits.
*/

char* clearDigits(char* s) {
    int length = strlen(s);
    char* result = (char*)malloc(length + 1); // Allocate memory for the result
    int index = 0; // Index for the result string

    for (int i = 0; i < length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            // If current character is a digit, check if there's a non-digit character before it
            if (index > 0) {
                index--; // Remove the last non-digit character
            }
        } else {
            // If current character is not a digit, add it to the result
            result[index++] = s[i];
        }
    }

    result[index] = '\0'; // Null-terminate the result string
    return result; // Return the resulting string
    
}