/**https://leetcode.com/problems/count-palindromic-subsequences/ */
//Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
//Note:
//	A string is palindromic if it reads the same forward and backward.
//	A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: s = "103301"
//Output: 2
//Explanation: 
//There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
//Two of them (both equal to "10301") are palindromic.
//Example 2:
//Input: s = "0000000"
//Output: 21
//Explanation: All 21 subsequences are "00000", which is palindromic.
//Example 3:
//Input: s = "9999900000"
//Output: 2
//Explanation: The only two palindromic subsequences are "99999" and "00000".
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of digits.
class Solution {
public:
    int countPalindromes(string s) {
            const int MOD = 1e9 + 7;
            int n = s.size();
            if (n < 5) return 0;

            vector<vector<int>> prefix(10, vector<int>(10, 0));
            vector<vector<int>> suffix(10, vector<int>(10, 0));

            // Build suffix counts
            for (int i = n - 1; i >= 0; --i) {
                int digit = s[i] - '0';
                for (int x = 0; x < 10; ++x) {
                suffix[digit][x] += suffix[x][digit];
                suffix[digit][x] %= MOD;
                }
                suffix[digit][digit]++;
            }

            long long result = 0;
            vector<vector<int>> current(10, vector<int>(10, 0));

            // Traverse the string and calculate the result
            for (int i = 0; i < n; ++i) {
                int digit = s[i] - '0';

                // Remove current digit from suffix
                for (int x = 0; x < 10; ++x) {
                suffix[digit][x] -= suffix[x][digit];
                if (suffix[digit][x] < 0) suffix[digit][x] += MOD;
                }
                suffix[digit][digit]--;

                // Calculate palindromes using prefix and suffix
                for (int x = 0; x < 10; ++x) {
                for (int y = 0; y < 10; ++y) {
                    result += (long long)prefix[x][y] * suffix[y][x] % MOD;
                    result %= MOD;
                }
                }

                // Update prefix counts
                for (int x = 0; x < 10; ++x) {
                prefix[x][digit] += prefix[digit][x];
                prefix[x][digit] %= MOD;
                }
                prefix[digit][digit]++;
            }

            return result;
    }   
};