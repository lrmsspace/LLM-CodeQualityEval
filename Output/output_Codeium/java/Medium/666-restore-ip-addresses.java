/**https://leetcode.com/problems/restore-ip-addresses/ */
//A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//	For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
// 
//Example 1:
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
//Example 2:
//Input: s = "0000"
//Output: ["0.0.0.0"]
//Example 3:
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//Constraints:
//	1 <= s.length <= 20
//	s consists of digits only.
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        backtrack(res, "", s, 0, 0);
        return res;
    }
    
    private void backtrack(List<String> res, String cur, String s, int index, int count) {
        if (count > 4) return;
        if (index == s.length() && count == 4) {
            res.add(cur.substring(0, cur.length() - 1));
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (index + i > s.length()) break;
            String str = s.substring(index, index + i);
            if (Integer.parseInt(str) > 255 || (str.length() > 1 && str.charAt(0) == '0')) break;
            backtrack(res, cur + str + ".", s, index + i, count + 1);
        }
    }
}