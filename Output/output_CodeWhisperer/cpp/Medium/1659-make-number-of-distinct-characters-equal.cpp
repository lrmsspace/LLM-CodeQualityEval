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
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> m1, m2;
        for (char c : word1) {
            m1[c]++;
        }
        for (char c : word2) {
            m2[c]++;
        }
        for (char c1 : word1) {
            for (char c2 : word2) {
                unordered_map<char, int> m1_copy = m1, m2_copy = m2;
                m1_copy[c1]--;
                if (m1_copy[c1] == 0) {
                    m1_copy.erase(c1);
                }
                m1_copy[c2]++;
                m2_copy[c2]--;
                if (m2_copy[c2] == 0) {
                    m2_copy.erase(c2);
                }
                m2_copy[c1]++;
                if (m1_copy.size() == m2_copy.size()) {
                    return true;
                }
            }
        }
        return false;      
    }
};