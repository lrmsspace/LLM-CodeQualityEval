/**https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 
//Example 1:
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Example 2:
//Input: digits = ""
//Output: []
//Example 3:
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//Constraints:
//	0 <= digits.length <= 4
//	digits[i] is a digit in the range ['2', '9'].
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() == 0) {
            return res;
        }
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(res, map, digits, 0, new StringBuilder());
        return res;
    }
    
    private void backtrack(List<String> res, String[] map, String digits, int index, StringBuilder sb) {
        if (index == digits.length()) {
            res.add(sb.toString());
            return;
        }
        String str = map[digits.charAt(index) - '0'];
        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            backtrack(res, map, digits, index + 1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}