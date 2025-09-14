/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/
int findMinimumOperations(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int minOperations = 0;

    // Start from the end of each string and move backwards
    while (len1 > 0 && len2 > 0 && len3 > 0) {
        if (s1[len1 - 1] == s2[len2 - 1] && s2[len2 - 1] == s3[len3 - 1]) {
            len1--;
            len2--;
            len3--;
        } else {
            if (s1[len1 - 1] != s2[len2 - 1] || s1[len1 - 1] != s3[len3 - 1]) {
                if (s1[len1 - 1] != s2[len2 - 1]) {
                    len1--;
                }
                if (s1[len1 - 1] != s3[len3 - 1]) {
                    len1--;
                }
                minOperations++;
            }
            if (s2[len2 - 1] != s3[len3 - 1]) {
                len2--;
                minOperations++;
            }
        }
    }

    // If any string is completely deleted, return -1
    if (len1 == 0 || len2 == 0 || len3 == 0) {
        return -1;
    }

    return minOperations;
}
