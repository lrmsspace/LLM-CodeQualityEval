/**https://leetcode.com/problems/count-vowels-permutation/ */
//Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
//	Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//	Each vowel 'a' may only be followed by an 'e'.
//	Each vowel 'e' may only be followed by an 'a' or an 'i'.
//	Each vowel 'i' may not be followed by another 'i'.
//	Each vowel 'o' may only be followed by an 'i' or a 'u'.
//	Each vowel 'u' may only be followed by an 'a'.
//Since the answer may be too large, return it modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
//Example 2:
//Input: n = 2
//Output: 10
//Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
//Example 3: 
//Input: n = 5
//Output: 68
// 
//Constraints:
//	1 <= n <= 2 * 10^4
class Solution {
public:
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1e9 + 7;
        for (int j = 1; j < n; ++j) {
            long long a2 = (e + i + u) % mod;
            long long e2 = (a + i) % mod;
            long long i2 = (e + o) % mod;
            long long o2 = i % mod;
            long long u2 = (i + o) % mod;
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;        
    }
};