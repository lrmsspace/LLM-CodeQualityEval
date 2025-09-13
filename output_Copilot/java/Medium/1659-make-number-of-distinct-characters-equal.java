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
class Solution {
    public boolean isItPossible(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        int distinct1 = 0;
        int distinct2 = 0;
        for (int i = 0; i < n; i++) {
            if (freq1[word1.charAt(i) - 'a'] == 0) {
                distinct1++;
            }
            freq1[word1.charAt(i) - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            if (freq2[word2.charAt(i) - 'a'] == 0) {
                distinct2++;
            }
            freq2[word2.charAt(i) - 'a']++;
        }
        if (distinct1 == distinct2) {
            return true;
        }
        if (distinct1 > distinct2) {
            int temp = distinct1;
            distinct1 = distinct2;
            distinct2 = temp;
            int[] tempFreq = freq1;
            freq1 = freq2;
            freq2 = tempFreq;
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] > 0 && freq2[i] == 0) {
                return false;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] == 0 && freq2[i] > 0) {
                return false;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] > 0 && freq2[i] > 0) {
                return true;
            }
        }
        return false;        
    }
}