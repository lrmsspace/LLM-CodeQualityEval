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
    public boolean checkIfPangram(String sentence) {
        // Create a boolean array to keep track of the letters seen
        boolean[] seen = new boolean[26];
        // Iterate through each character in the sentence
        for (char c : sentence.toCharArray()) {
            // Mark the letter as seen
            seen[c - 'a'] = true;
        }
        // Check if all letters from 'a' to 'z' have been seen
        for (boolean b : seen) {
            if (!b) {
                return false; // If any letter is not seen, return false
            }
        }
        return true; // All letters have been seen, return true        
    }
}