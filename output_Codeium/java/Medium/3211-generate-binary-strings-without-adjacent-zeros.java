/*
 You are given a positive integer n.
 A binary string x is valid if all substrings of x of length 2 contain at least one "1".
 Return all valid strings with length n, in any order.
 Example 1:
 Input: n = 3
 Output: ["010","011","101","110","111"]
 Explanation:
 The valid strings of length 3 are: "010", "011", "101", "110", and "111".
 Example 2:
 Input: n = 1
 Output: ["0","1"]
 Explanation:
 The valid strings of length 1 are: "0" and "1".
 Constraints:
 1 <= n <= 18
*/

class Solution {
    public List<String> validStrings(int n) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < (1 << n); i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                sb.append((i & (1 << j)) != 0 ? '1' : '0');
            }
            boolean isValid = true;
            for (int j = 0; j < n - 1; j++) {
                if (sb.charAt(j) == '0' && sb.charAt(j + 1) == '0') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                result.add(sb.reverse().toString());
            }
        }
        return result;

    }
}