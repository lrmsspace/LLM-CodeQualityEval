/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
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
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

long long validSubstringCount(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    int count[26] = {0};
    long long res = 0;
    for (int i = 0; i < n; i++) {
        count[word1[i]-'a']++;
        if (i >= m) {
            count[word1[i-m]-'a']--;
        }
        int match = 1;
        for (int j = 0; j < 26; j++) {
            if (count[j] < count[word2[j]-'a']) {
                match = 0;
                break;
            }
        }
        if (match) {
            res += (i >= m ? n-i : 1);
        }
    }
    return res;
}