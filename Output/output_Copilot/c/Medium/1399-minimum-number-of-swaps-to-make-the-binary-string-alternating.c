/**https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/ */
//Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
//The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//Any two characters may be swapped, even if they are not adjacent.
// 
//Example 1:
//Input: s = "111000"
//Output: 1
//Explanation: Swap positions 1 and 4: "111000" -> "101010"
//The string is now alternating.
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating, no swaps are needed.
//Example 3:
//Input: s = "1110"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
int minSwaps(char* s) {
    int len = strlen(s);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    if (abs(cnt0 - cnt1) > 1) {
        return -1;
    }
    if (cnt0 == cnt1) {
        int cnt01 = 0, cnt10 = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    cnt01++;
                } else {
                    cnt10++;
                }
            } else {
                if (s[i] == '0') {
                    cnt01++;
                } else {
                    cnt10++;
                }
            }
        }
        return cnt01 / 2;
    } else if (cnt0 > cnt1) {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    cnt++;
                }
            } else {
                if (s[i] == '0') {
                    cnt++;
                }
            }
        }
        return cnt / 2;
    } else {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    cnt++;
                }
            } else {
                if (s[i] == '1') {
                    cnt++;
                }
            }
        }
        return cnt / 2;
    }    
}