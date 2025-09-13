/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
bool isSolvable(char** words, int wordsSize, char* result) {
    int n = 0;
    int* charToDigit = (int*)malloc(26 * sizeof(int));
    int* digitToChar = (int*)malloc(10 * sizeof(int));
    int* leading = (int*)malloc(26 * sizeof(int));
    int* count = (int*)malloc(26 * sizeof(int));
    int* sum = (int*)malloc(26 * sizeof(int));
    int* product = (int*)malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++) {
        charToDigit[i] = -1;
        leading[i] = 0;
        count[i] = 0;
        sum[i] = 0;
        product[i] = 1;
    }
    for (int i = 0; i < 10; i++) {
        digitToChar[i] = -1;
    }
    for (int i = 0; i < wordsSize; i++) {
        n = fmax(n, strlen(words[i]));
    }
    n = fmax(n, strlen(result));
    for (int i = 0; i < wordsSize; i++) {
        int m = strlen(words[i]);
        for (int j = 0; j < m; j++) {
            char c = words[i][j];
            if (j == 0) {
                leading[c - 'A'] = 1;
            }
            count[c - 'A']++;
            sum[c - 'A'] += m - j - 1;
            product[c - 'A'] *= 10;
        }
    }
    int m = strlen(result);
    for (int j = 0; j < m; j++) {
        char c = result[j];
        if (j == 0) {
            leading[c - 'A'] = 1;
        }
        count[c - 'A']++;
        sum[c - 'A'] += m - j - 1;
        product[c - 'A'] *= 10;
    }
    int* used = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        used[i] = 0;
    }
    bool dfs(int index, int carry) {
        if (index == n) {
            return carry == 0;
        }
        int s = carry;
        for (int i = 0; i < wordsSize; i++) {
            int m = strlen(words[i]);
            if (index < m) {
            char c = words[i][m - index - 1];
            if (charToDigit[c - 'A'] == -1) {
                for (int d = 0; d < 10; d++) {
                if (!used[d] && (d > 0 || !leading[c - 'A'])) {
                    used[d] = 1;
                    charToDigit[c - 'A'] = d;
                    if (dfs(index, carry)) {
                    return true;
                    }
                    charToDigit[c - 'A'] = -1;
                    used[d] = 0;
                }
                }
                return false;
            }
            s += charToDigit[c - 'A'];
            }
        }
        int m = strlen(result);
        if (index < m) {
            char c = result[m - index - 1];
            if (charToDigit[c - 'A'] == -1) {
            for (int d = 0; d < 10; d++) {
                if (!used[d] && (d > 0 || !leading[c - 'A'])) {
                used[d] = 1;
                charToDigit[c - 'A'] = d;
                if (dfs(index + 1, s / 10)) {
                    return true;
                }
                charToDigit[c - 'A'] = -1;
                used[d] = 0;
                }
            }
            return false;
            }
            if (charToDigit[c - 'A'] != s % 10) {
            return false;
            }
        }
        return dfs(index + 1, s / 10);  
}