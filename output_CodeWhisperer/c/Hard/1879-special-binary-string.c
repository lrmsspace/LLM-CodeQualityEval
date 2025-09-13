/**https://leetcode.com/problems/special-binary-string/ */
//Special binary strings are binary strings with the following two properties:
//	The number of 0's is equal to the number of 1's.
//	Every prefix of the binary string has at least as many 1's as 0's.
//You are given a special binary string s.
//A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
//Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.
// 
//Example 1:
//Input: s = "11011000"
//Output: "11100100"
//Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
//This is the lexicographically largest string possible after some number of swaps.
//Example 2:
//Input: s = "10"
//Output: "10"
// 
//Constraints:
//	1 <= s.length <= 50
//	s[i] is either '0' or '1'.
//	s is a special binary string.
char* makeLargestSpecial(char* s) {
    int n = strlen(s);

    if (n <= 2) {
        return s;
    }

    int count = 0;

    int start = 0;

    char* result = (char*)malloc(sizeof(char) * (n + 1));

    int resultIndex = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            char* sub = (char*)malloc(sizeof(char) * (i - start + 2));

            strncpy(sub, s + start, i - start + 1);

            sub[i - start + 1] = '\0';

            char* subResult = makeLargestSpecial(sub);

            int subResultLength = strlen(subResult);

            for (int j = 0; j < subResultLength; j++) {
                result[resultIndex++] = subResult[j];
            }

            free(sub);
            free(subResult);

            start = i + 1;
        }
    }
    result[resultIndex] = '\0';

    char* finalResult = (char*)malloc(sizeof(char) * (resultIndex + 1));

    int finalResultIndex = 0;

    for (int i = 0; i < resultIndex; i++) {
        if (result[i] == '1') {
            finalResult[finalResultIndex++] = '1';
        } else {
            finalResult[finalResultIndex++] = '0';
        }
    }
    finalResult[finalResultIndex] = '\0';

    free(result);
    return finalResult;
    
}