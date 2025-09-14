/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.
// 
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//	1 <= s.length <= 12
//	s consists of lowercase English letters, uppercase English letters, and digits.
class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> result = new ArrayList<>();
        backtrack(result, new StringBuilder(), s, 0);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder sb, String s, int i) {
        if (i == s.length()) {
            result.add(sb.toString());
            return;
        }
        char c = s.charAt(i);
        if (Character.isLetter(c)) {
            sb.append(Character.toLowerCase(c));
            backtrack(result, sb, s, i + 1);
            sb.deleteCharAt(sb.length() - 1);
            sb.append(Character.toUpperCase(c));
            backtrack(result, sb, s, i + 1);
            sb.deleteCharAt(sb.length() - 1);
        } else {
            sb.append(c);
            backtrack(result, sb, s, i + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}