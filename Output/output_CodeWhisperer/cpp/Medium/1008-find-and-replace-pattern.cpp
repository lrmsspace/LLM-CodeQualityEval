/**https://leetcode.com/problems/find-and-replace-pattern/ */
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
// 
//Example 1:
//Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
//Output: ["mee","aqq"]
//Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
//"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
//Example 2:
//Input: words = ["a","b","c"], pattern = "a"
//Output: ["a","b","c"]
// 
//Constraints:
//	1 <= pattern.length <= 20
//	1 <= words.length <= 50
//	words[i].length == pattern.length
//	pattern and words[i] are lowercase English letters.
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string word : words) {
            if (word.length() != pattern.length()) continue;
            unordered_map<char, char> m1, m2;
            bool match = true;
            for (int i = 0; i < word.length(); i++) {
                char c1 = word[i], c2 = pattern[i];
                if (m1.find(c1) == m1.end()) m1[c1] = c2;
                if (m2.find(c2) == m2.end()) m2[c2] = c1;
                if (m1[c1] != c2 || m2[c2] != c1) {
                    match = false;
                    break;
                }
            }
            if (match) res.push_back(word);
        }
        return res;     
    }
};