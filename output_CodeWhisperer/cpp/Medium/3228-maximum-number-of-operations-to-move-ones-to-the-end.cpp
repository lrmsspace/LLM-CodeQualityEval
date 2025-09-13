/*
 You are given a binary string s.
 You can perform the following operation on the string any number of times:
 Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
 Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
 Return the maximum number of operations that you can perform.
 Example 1:
 Input: s = "1001101"
 Output: 4
 Explanation:
 We can perform the following operations:
 Choose index i = 0. The resulting string is s = "0011101".
 Choose index i = 4. The resulting string is s = "0011011".
 Choose index i = 3. The resulting string is s = "0010111".
 Choose index i = 2. The resulting string is s = "0001111".
 Example 2:
 Input: s = "00111"
 Output: 0
 Constraints:
 1 <= s.length <= 105
 s[i] is either '0' or '1'.
*/

class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cnt = 0;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                cnt++;
                if(i < n-1 && s[i+1] == '0') {
                    idx = i;
                }
            }
        }
        if(cnt == 0) return 0;
        if(cnt == 1) return 0;
        if(idx == n-2) return 1;
        if(idx == 0) {
            int cnt1 = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') {
                    cnt1++;
                }
                if(s[i] == '0') {
                    break;
                }
            }
            return cnt1-1;
        }
        int cnt1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                cnt1++;
            }
            if(s[i] == '0') {
                break;
            }
        }
        int cnt2 = 0;
        for(int i = idx+1; i < n; i++) {
            if(s[i] == '1') {
                cnt2++;
            }
        }
        return cnt1+cnt2-1;        
    }
};