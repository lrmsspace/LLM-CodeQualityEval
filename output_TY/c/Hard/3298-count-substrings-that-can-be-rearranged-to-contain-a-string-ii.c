/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 106
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

long long validSubstringCount(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    
    int i, j, k;
    int count = 0;
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int flag = 1;
            for (k = 0; k < m; k++) {
                if (word1[i + k] != word2[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                count += (j - i + 1);
            }
        }
    }
    return count;

    
}