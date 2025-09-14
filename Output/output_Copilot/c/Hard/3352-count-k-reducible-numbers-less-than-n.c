/*
 You are given a binary string s representing a number n in its binary form.
 You are also given an integer k.
 An integer x is called k-reducible if performing the following operation at most k times reduces it to 1:
 Replace x with the count of set bits in its binary representation.
 For example, the binary representation of 6 is "110". Applying the operation once reduces it to 2 (since "110" has two set bits). Applying the operation again to 2 (binary "10") reduces it to 1 (since "10" has one set bit).
 Return an integer denoting the number of positive integers less than n that are k-reducible.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: s = "111", k = 1
 Output: 3
 Explanation: 
 n = 7. The 1-reducible integers less than 7 are 1, 2, and 4.
 Example 2:
 Input: s = "1000", k = 2
 Output: 6
 Explanation:
 n = 8. The 2-reducible integers less than 8 are 1, 2, 3, 4, 5, and 6.
 Example 3:
 Input: s = "1", k = 3
 Output: 0
 Explanation:
 There are no positive integers less than n = 1, so the answer is 0.
 Constraints:
 1 <= s.length <= 800
 s has no leading zeros.
 s consists only of the characters '0' and '1'.
 1 <= k <= 5
*/

int countKReducibleNumbers(char* s, int k) {
    int n = 0, i, j, count = 0;
    long long mod = 1000000007;
    
    // Convert binary string to integer
    for (i = 0; s[i] != '\0'; i++) {
        n = (n << 1) | (s[i] - '0');
    }
    
    // Count k-reducible numbers less than n
    for (i = 1; i < n; i++) {
        int x = i, steps = 0;
        while (x > 1 && steps < k) {
            x = __builtin_popcount(x); // Count set bits
            steps++;
        }
        if (x == 1) {
            count++;
        }
    }
    
    return count % mod;    
}