/**https://leetcode.com/problems/count-the-number-of-consistent-strings/ */
//You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
//Return the number of consistent strings in the array words.
// 
//Example 1:
//Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
//Output: 2
//Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
//Example 2:
//Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
//Output: 7
//Explanation: All strings are consistent.
//Example 3:
//Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
//Output: 4
//Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= allowed.length <= 26
//	1 <= words[i].length <= 10
//	The characters in allowed are distinct.
//	words[i] and allowed contain only lowercase English letters.
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        int allowed_size = allowed.size();
        int words_size = words.size();
        for (int i = 0; i < words_size; i++) {
            int word_size = words[i].size();
            bool flag = true;
            for (int j = 0; j < word_size; j++) {
                bool found = false;
                for (int k = 0; k < allowed_size; k++) {
                    if (words[i][j] == allowed[k]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    flag = false;
                    break;
                }
            }
        }
        return count;
    }
};