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
        // Create a boolean array to mark the occurrence of each letter
        bool letter[26] = {false};
        
        // Iterate through the sentence and mark the occurrence of each letter
        for (char c : sentence) {
            if (c >= 'a' && c <= 'z') {
                letter[c - 'a'] = true;
            }
        }
        
        // Check if all letters have been marked
        for (bool b : letter) {
            if (!b) {
                return false;
            }
        }
        
        return true;
        
    }
};