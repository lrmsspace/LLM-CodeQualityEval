/**https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/ */
//You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//	Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//	Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//Return the lexicographically smallest string that can be written on the paper.
// 
//Example 1:
//Input: s = "zza"
//Output: "azz"
//Explanation: Let p denote the written string.
//Initially p="", s="zza", t="".
//Perform first operation three times p="", s="", t="zza".
//Perform second operation three times p="azz", s="", t="".
//Example 2:
//Input: s = "bac"
//Output: "abc"
//Explanation: Let p denote the written string.
//Perform first operation twice p="", s="c", t="ba". 
//Perform second operation twice p="ab", s="c", t="". 
//Perform first operation p="ab", s="", t="c". 
//Perform second operation p="abc", s="", t="".
//Example 3:
//Input: s = "bdda"
//Output: "addb"
//Explanation: Let p denote the written string.
//Initially p="", s="bdda", t="".
//Perform first operation four times p="", s="", t="bdda".
//Perform second operation four times p="addb", s="", t="".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
class Solution {
    public String robotWithString(String s) {
        // Create frequency array to track minimum chars after each position
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // Stack to simulate string t
        Stack<Character> stack = new Stack<>();
        
        // Result string builder
        StringBuilder paper = new StringBuilder();
        
        // Index to track position in s
        int idx = 0;
        
        // Process each character
        while (idx < s.length() || !stack.isEmpty()) {
            // If stack is empty, we must take from s
            if (stack.isEmpty() && idx < s.length()) {
                stack.push(s.charAt(idx));
                freq[s.charAt(idx) - 'a']--;
                idx++;
                continue;
            }
            
            // Find minimum character remaining in s
            char minRemaining = 'z' + 1;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    minRemaining = (char)('a' + i);
                    break;
                }
            }
            
            // If top of stack is smaller than minimum remaining in s
            // or if we've processed all of s, pop from stack
            if (stack.peek() <= minRemaining || idx >= s.length()) {
                paper.append(stack.pop());
            } else {
                // Otherwise take from s
                stack.push(s.charAt(idx));
                freq[s.charAt(idx) - 'a']--;
                idx++;
            }
        }
        
        return paper.toString();
    }
        
}
