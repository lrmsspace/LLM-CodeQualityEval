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
char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    if (digits == NULL || strlen(digits) == 0) {
        return NULL;
    }
    char *phone[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = strlen(digits);
    char **result = (char **)malloc(sizeof(char *) * 100);
    char *temp = (char *)malloc(sizeof(char) * (len + 1));
    temp[len] = '\0';
    int i, j, k;
    for (i = 0; i < len; i++) {
        int num = digits[i] - '2';
        int size = strlen(phone[num]);
        for (j = 0; j < size; j++) {
            temp[i] = phone[num][j];
            if (i == 0) {
                result[(*returnSize)++] = (char *)malloc(sizeof(char) * (len+ 1));
            }
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < (*returnSize); k++) {
                result[k][i] = temp[i];
            }
        }
    }
    return result;

}