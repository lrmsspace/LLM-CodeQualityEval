/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.
// 
//Example 1:
//Input: word1 = "ac", word2 = "b"
//Output: false
//Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
//Example 2:
//Input: word1 = "abcc", word2 = "aab"
//Output: true
//Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
//Example 3:
//Input: word1 = "abcde", word2 = "fghij"
//Output: true
//Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 consist of only lowercase English letters.
bool isItPossible(char * word1, char * word2){
    int hash1[26] = { 0 }, hash2[26] = { 0 }, len1 = strlen(word1), len2 = strlen(word2);
    for (int i = 0; i < len1; i++) hash1[word1[i] - 'a']++;
    for (int i = 0; i < len2; i++) hash2[word2[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (hash1[i] == 0 || hash2[j] == 0) continue;
            int cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < 26; k++) {
                if (hash1[k] >0) cnt1++;
            }
        }
    }
    return false;
}