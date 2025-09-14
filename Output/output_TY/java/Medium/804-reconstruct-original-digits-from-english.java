/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
class Solution {
    public String originalDigits(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        int[] ans = new int[10];
        ans[0] = count['z' - 'a'];
        ans[2] = count['w' - 'a'];
        ans[4] = count['u' - 'a'];
        ans[6] = count['x' - 'a'];
        ans[8] = count['g' - 'a'];
        ans[1] = count['o' - 'a'] - ans[0] - ans[2] - ans[4];
        ans[3] = count['r' - 'a'] - ans[0] - ans[4];
        ans[5] = count['f' - 'a'] - ans[4];
        ans[7] = count['s' - 'a'] - ans[6];
        ans[9] = count['i' - 'a'] - ans[5] - ans[6] - ans[8];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}