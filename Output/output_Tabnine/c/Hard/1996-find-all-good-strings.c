/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
//Output: 51 
//Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
//Example 2:
//Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
//Output: 0 
//Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
//Example 3:
//Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
//Output: 2
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	s1 <= s2
//	1 <= n <= 500
//	1 <= evil.length <= 50
//	All strings consist of lowercase English letters.
int findGoodStrings(int n, char* s1, char* s2, char* evil) {
    int MOD = 1e9 + 7;
    int m = strlen(s1);
    int p1 = 0, p2 = 0;
    int count = 0;
    
    // Calculate the prefix sums for s1 and s2
    int pow1[m + 1], pow2[m + 1];
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pow1[i] = (pow1[i - 1] * (s1[i - 1] - 'a' + 1)) % MOD;
        pow2[i] = (pow2[i - 1] * (s2[i - 1] - 'a' + 1)) % MOD;
    }
    
    // Calculate the prefix sums for evil
    int evilPow = 1;
    for (int i = 0; i < strlen(evil); i++) {
        evilPow = (evilPow * (evil[i] - 'a' + 1)) % MOD;
    }
    
    // Iterate through the range [s1, s2]
    for (int i = 0; i < m; i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        
        // Calculate the number of good strings with the current prefix
        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int sum = (pow2[mid] - pow2[i]) % MOD;
            if (sum < 0) {
                sum += MOD;
            }
            if (sum >= evilPow) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        count = (count + (left - i + 1)) % MOD;
    }
    
    return count;
    
}