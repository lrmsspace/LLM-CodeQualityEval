/**https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 
//Example 1:
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Example 2:
//Input: digits = ""
//Output: []
//Example 3:
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//Constraints:
//	0 <= digits.length <= 4
//	digits[i] is a digit in the range ['2', '9'].
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    // Create a mapping of digits to letters
    char* mapping[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // Initialize result array
    char** result = malloc(1 * sizeof(char*));
    *returnSize = 0;
    
    // Base case: if digits is empty, return an empty array
    if (*digits == '\0') {
        return result;
    }
    
    // Recursive case: iterate through each digit, and for each digit, combine with all previous combinations
    for (int i = 0; i < strlen(digits); i++) {
        int digit = digits[i] - '0';
        int newSize = *returnSize * (strlen(mapping[digit]) + 1);
        result = realloc(result, newSize * sizeof(char*));
        
        // Add new combinations to the result array
        for (int j = 0; j < *returnSize; j++) {
            for (int k = 0; k < strlen(mapping[digit]); k++) {
                result[j * (strlen(mapping[digit])) + k + *returnSize] = malloc((strlen(digits) + 1) * sizeof(char));
                strcpy(result[j * (strlen(mapping[digit])) + k + *returnSize], result[j]);
                result[j * (strlen(mapping[digit])) + k + *returnSize][strlen(result[j])] = mapping[digit][k];
            }
        }
        
        *returnSize = newSize;

        // Remove the first combination from the result array (since it was added multiple times)
        free(result[0]);
        memmove(result, result + *returnSize / (strlen(mapping[digit]) + 1), (*returnSize / (strlen(mapping[digit]) + 1)) * sizeof(char*));
    }
    
    return result;
    
}