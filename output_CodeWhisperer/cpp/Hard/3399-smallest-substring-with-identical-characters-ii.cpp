/*
 You are given a binary string s of length n and an integer numOps.
 You are allowed to perform the following operation on s at most numOps times:
 Select any index i (where 0 <= i < n) and flip s[i]. If s[i] == '1', change s[i] to '0' and vice versa.
 You need to minimize the length of the longest substring of s such that all the characters in the substring are identical.
 Return the minimum length after the operations.
 Example 1:
 Input: s = "000001", numOps = 1
 Output: 2
 Explanation: 
 By changing s[2] to '1', s becomes "001001". The longest substrings with identical characters are s[0..1] and s[3..4].
 Example 2:
 Input: s = "0000", numOps = 2
 Output: 1
 Explanation: 
 By changing s[0] and s[2] to '1', s becomes "1010".
 Example 3:
 Input: s = "0101", numOps = 0
 Output: 1
 Constraints:
 1 <= n == s.length <= 105
 s consists only of '0' and '1'.
 0 <= numOps <= n
*/

class Solution {
public:
    int minLength(string s, int numOps) {
    int n = s.length();
    int ans = n;
    
    // Try each possible length from 1 to n
    for(int len = 1; len <= n; len++) {
        // For each window of size len
        for(int i = 0; i + len <= n; i++) {
            // Try making all chars in window either 0 or 1
            int ops0 = 0, ops1 = 0;
            for(int j = 0; j < len; j++) {
                if(s[i+j] == '1') ops0++;
                else ops1++;
            }
            
            // Check if we can make all chars same with numOps operations
            if(ops0 <= numOps || ops1 <= numOps) {
                // Check if rest of string can be split into segments <= len
                bool possible = true;
                int curr = 0;
                int remain = numOps - min(ops0, ops1);
                
                // Check segments before window
                for(int j = 0; j < i; j++) {
                    curr++;
                    if(curr == len) {
                        int need = min(curr - count(s.begin()+j-curr+1, s.begin()+j+1, '0'),
                                    curr - count(s.begin()+j-curr+1, s.begin()+j+1, '1'));
                        if(need > remain) {
                            possible = false;
                            break;
                        }
                        remain -= need;
                        curr = 0;
                    }
                }
                
                // Check segments after window 
                if(possible) {
                    curr = 0;
                    for(int j = i+len; j < n; j++) {
                        curr++;
                        if(curr == len) {
                            int need = min(curr - count(s.begin()+j-curr+1, s.begin()+j+1, '0'),
                                        curr - count(s.begin()+j-curr+1, s.begin()+j+1, '1'));
                            if(need > remain) {
                                possible = false;
                                break;
                            }
                            remain -= need;
                            curr = 0;
                        }
                    }
                }
                
                // Check remaining chars
                if(possible && curr > 0) {
                    int need = min(curr - count(s.begin()+n-curr, s.begin()+n, '0'),
                                curr - count(s.begin()+n-curr, s.begin()+n, '1'));
                    if(need <= remain) {
                        ans = min(ans, len);
                        break;
                    }
                } else if(possible) {
                    ans = min(ans, len);
                    break;
                }
            }
        }
    }
    
    return ans;
}                
};