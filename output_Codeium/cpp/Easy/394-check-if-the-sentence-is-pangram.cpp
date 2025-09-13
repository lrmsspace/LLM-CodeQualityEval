/**https://leetcode.com/problems/check-if-the-sentence-is-pangram/ */
//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
// 
//Example 1:
//Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
//Output: true
//Explanation: sentence contains at least one of every letter of the English alphabet.
//Example 2:
//Input: sentence = "leetcode"
//Output: false
// 
//Constraints:
//	1 <= sentence.length <= 1000
//	sentence consists of lowercase English letters.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);
        for (char c : sentence) {
            seen[c - 'a'] = true;
        }
        return all_of(seen.begin(), seen.end(), [](bool x){ return x; });
    }
};