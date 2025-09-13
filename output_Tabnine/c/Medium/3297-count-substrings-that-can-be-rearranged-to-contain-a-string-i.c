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

    int m = strlen(word1);
    int n = strlen(word2);
    
    // Create a frequency array for word2
    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[word2[i] - 'a']++;
    }
    
    int count = 0;
    int left = 0;   
    int right = 0;
    int matchCount = 0;

    while (right < m) {
        // If the current character matches with word2's character, increment matchCount
        if (freq[word1[right] - 'a'] > 0) {
            matchCount++;
        }
        // Decrement the frequency of the left character
        if (left < n && word1[left] == word2[right]) {
            freq[word1[left] - 'a']--;
            matchCount--;
        }
        // If all characters in word2 match, increment count
        if (matchCount == n) {
            count++;
        }
        // Move the right pointer
        right++;
        // If the window size becomes smaller than word2, move the left pointer
        if (right - left == n) {
            freq[word1[left] - 'a']++;
            if (word1[left] == word2[left]) {
                matchCount--;
            }
            left++;
        }
    }   
    return count;
    
}