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
int countVowelPermutation(int n) {
    int MOD = 1000000007;
    long a = 1, e = 1, i = 1, o = 1, u = 1;
    for (int j = 1; j < n; j++) {
        long a1 = (e + i + u) % MOD;
        long e1 = (a + i) % MOD;
        long i1 = (e + o) % MOD;
        long o1 = i;
        long u1 = (i + o) % MOD;
        a = a1;
        e = e1;
        i = i1;
        o = o1;
        u = u1;
    }
    return (int)((a + e + i + o + u) % MOD);    
}