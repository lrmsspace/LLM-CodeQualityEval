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
    int count[26] = {0}, required[26] = {0};
    int len1 = 0, len2 = 0;
    long long result = 0;

    // Calculate the frequency of characters in word2
    while (word2[len2]) {
        required[word2[len2] - 'a']++;
        len2++;
    }

    // Sliding window to count valid substrings
    for (int start = 0, end = 0; word1[end]; end++) {
        count[word1[end] - 'a']++;

        // Check if the current window can form a valid substring
        while (start <= end && (count[word1[end] - 'a'] > required[word1[end] - 'a'])) {
            count[word1[start] - 'a']--;
            start++;
        }

        // If the current window size is at least len2, it's valid
        if (end - start + 1 >= len2) {
            result += (end - start + 1) - len2 + 1;
        }
    }

    return result;    
}