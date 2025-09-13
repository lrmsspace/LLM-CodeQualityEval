/**https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ */
//Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
// 
//Example 1:
//Input: s = "00110110", k = 2
//Output: true
//Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
//Example 2:
//Input: s = "0110", k = 1
//Output: true
//Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
//Example 3:
//Input: s = "0110", k = 2
//Output: false
//Explanation: The binary code "00" is of length 2 and does not exist in the array.
// 
//Constraints:
//	1 <= s.length <= 5 * 105
//	s[i] is either '0' or '1'.
//	1 <= k <= 20
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;
        int m = 1 << k;
        vector<bool> vis(m, false);
        int num = 0;
        for (int i = 0; i < k; ++i) {
            num = num * 2 + s[i] - '0';
        }
        vis[num] = true;
        for (int i = k; i < n; ++i) {
            num = num * 2 + s[i] - '0';
            num &= (m - 1);
            vis[num] = true;
        }
        for (int i = 0; i < m; ++i) {
            if (!vis[i]) return false;
        }
        return true;        
    }
};