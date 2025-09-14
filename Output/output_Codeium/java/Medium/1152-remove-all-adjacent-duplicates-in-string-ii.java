/**https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/ */
//You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
//We repeatedly make k duplicate removals on s until we no longer can.
//Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
// 
//Example 1:
//Input: s = "abcd", k = 2
//Output: "abcd"
//Explanation: There's nothing to delete.
//Example 2:
//Input: s = "deeedbbcccbdaa", k = 3
//Output: "aa"
//Explanation: 
//First delete "eee" and "ccc", get "ddbbbdaa"
//Then delete "bbb", get "dddaa"
//Finally delete "ddd", get "aa"
//Example 3:
//Input: s = "pbbcggttciiippooaais", k = 2
//Output: "ps"
// 
//Constraints:
//	1 <= s.length <= 105
//	2 <= k <= 104
//	s only contains lowercase English letters.
class Solution {
    public String removeDuplicates(String s, int k) {
        Stack<Pair<Character, Integer>> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek().getKey() == c) {
                int count = stack.peek().getValue() + 1;
                stack.pop();
                if (count < k) {
                    stack.push(new Pair<>(c, count));
                }
            } else {
                stack.push(new Pair<>(c, 1));
            }
        }
        
        StringBuilder result = new StringBuilder();
        for (Pair<Character, Integer> pair : stack) {
            for (int i = 0; i < pair.getValue(); i++) {
                result.append(pair.getKey());
            }
        }
        
        return result.toString();

    }
}