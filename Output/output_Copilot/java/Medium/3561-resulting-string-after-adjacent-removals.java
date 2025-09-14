/*
 You are given a string s consisting of lowercase English letters.
 You must repeatedly perform the following operation while the string s has at least two consecutive characters:
 Remove the leftmost pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
 Shift the remaining characters to the left to fill the gap.
 Return the resulting string after no more operations can be performed.
 Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.
 Example 1:
 Input: s = "abc"
 Output: "c"
 Explanation:
 Remove "ab" from the string, leaving "c" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "c".
 Example 2:
 Input: s = "adcb"
 Output: ""
 Explanation:
 Remove "dc" from the string, leaving "ab" as the remaining string.
 Remove "ab" from the string, leaving "" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "".
 Example 3:
 Input: s = "zadb"
 Output: "db"
 Explanation:
 Remove "za" from the string, leaving "db" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "db".
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters.
*/

class Solution {
    public String resultingString(String s) {
        StringBuilder sb = new StringBuilder(s);
        boolean found;

        do {
            found = false;
            for (int i = 0; i < sb.length() - 1; i++) {
                char c1 = sb.charAt(i);
                char c2 = sb.charAt(i + 1);
                if (Math.abs(c1 - c2) == 1 || (c1 == 'a' && c2 == 'z') || (c1 == 'z' && c2 == 'a')) {
                    sb.delete(i, i + 2);
                    found = true;
                    break; // Restart from the beginning after a removal
                }
            }
        } while (found);

        return sb.toString();        
    }
}