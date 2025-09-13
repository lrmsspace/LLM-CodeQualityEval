/*
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
 You are given an array of strings message and an array of strings bannedWords.
 An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.
 Return true if the array message is spam, and false otherwise.
 Example 1:
 Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]
 Output: true
 Explanation:
 The words "hello" and "world" from the message array both appear in the bannedWords array.
 Example 2:
 Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]
 Output: false
 Explanation:
 Only one word from the message array ("programming") appears in the bannedWords array.
 Constraints:
 1 <= message.length, bannedWords.length <= 105
 1 <= message[i].length, bannedWords[i].length <= 15
 message[i] and bannedWords[i] consist only of lowercase English letters.
*/

class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        Set<String> bannedSet = new HashSet<>(Arrays.asList(bannedWords));
        for (String word : message) {
            if (bannedSet.contains(word)) {
                return true;
            }
            for (int i = 0; i < word.length(); i++) {
                for (int j = i + 1; j <= word.length(); j++) {
                    String sub = word.substring(i, j);
                    if (bannedSet.contains(sub)) {
                        return true;
                    }
                }
            }
        }
        return false;
            
    }
}