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
    if (!digits || !*digits) {
        *returnSize = 0;
        return NULL;
    }

    const char* phone[10] = {"", "", "abc", "def", "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz"};
    int len = strlen(digits);
    int size = 1;
    for (int i = 0; i < len; i++) {
        size *= strlen(phone[digits[i] - '0']);
    }
    *returnSize = size;
    char** res = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        res[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int idx[10] = {0};
    for (int i = 0; i < size; i++) {
        int n = i;
        for (int j = len - 1; j >= 0; j--) {
            int k = (n % strlen(phone[digits[j] - '0']));
            n /= strlen(phone[digits[j] - '0']);
            res[i][j] = phone[digits[j] - '0'][k];
            idx[j] = k;
            if (idx[j] == strlen(phone[digits[j] - '0']) - 1) {
                for (int k = j + 1; k < len; k++) {
                    idx[k] = 0;
                }
            }
        }
        res[i][len] = '\0';
    }

    return res;
}