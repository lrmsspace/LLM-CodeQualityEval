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
    int count1[26] = {0};
    int count2[26] = {0};
    int i;
    for (i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
    }
    for (i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
    }
    long long result = 0;
    for (i = 0; i < 26; i++) {
        if (count2[i] > 0) {
            result += (long long)count1[i] * (count1[i] - 1) / 2;
        }
    }
    return result;    
}