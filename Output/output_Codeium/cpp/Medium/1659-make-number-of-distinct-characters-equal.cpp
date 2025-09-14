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
        unordered_map<char, int> count1, count2;
        for (char c : word1) ++count1[c];
        for (char c : word2) ++count2[c];
        int diff1 = count1.size() - count2.size();
        if (diff1 < -1 || diff1 > 1) return false;
        if (diff1 == 0) {
            for (auto& [c, cnt] : count1) {
                if (cnt > 1) return true;
                if (count2.count(c)) return true;
            }
            for (auto& [c, cnt] : count2) {
                if (cnt > 1) return true;
                if (count1.count(c)) return true;
            }
            return false;
        }
        if (diff1 == 1) {
            for (auto& [c, cnt] : count1) {
                if (cnt > 1) return true;
                if (count2.count(c)) {
                    --count2[c];
                    if (!count2[c]) count2.erase(c);
                    return count2.size() == count1.size() - 1;
                }
            }
        }
        if (diff1 == -1) {
            for (auto& [c, cnt] : count2) {
                if (cnt > 1) return true;
                if (count1.count(c)) {
                    --count1[c];
                    if (!count1[c]) count1.erase(c);
                    return count1.size() == count2.size() - 1;
                }
            }
        }
        return false;
    }
};