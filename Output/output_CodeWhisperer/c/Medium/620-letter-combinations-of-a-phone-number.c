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
    char** result = (char**)malloc(sizeof(char*) * 10000);
    *returnSize = 0;
    if (digits == NULL || strlen(digits) == 0) {
        return result;
    }
    char* map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result[*returnSize] = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
    strcpy(result[*returnSize], "");
    (*returnSize)++;
    for (int i = 0; i < strlen(digits); i++) {
        int count = strlen(result[0]);
        char* temp = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
        strcpy(temp, result[0]);
        for (int j = 0; j < count; j++) {
            temp[strlen(temp) - 1] = '\0';
            int len = strlen(result[j]);
            for (int k = 0; k < strlen(map[digits[i] - '0']); k++) {
                result[*returnSize] = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
                strcpy(result[*returnSize], temp);
                result[*returnSize][len] = map[digits[i] - '0'][k];
                result[*returnSize][len + 1] = '\0';
                (*returnSize)++;
            }
        }
    }
    return result;
    
}