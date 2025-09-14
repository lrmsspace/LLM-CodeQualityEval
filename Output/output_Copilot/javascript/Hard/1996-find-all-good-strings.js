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
/**
 * @param {number} n
 * @param {string} s1
 * @param {string} s2
 * @param {string} evil
 * @return {number}
 */
var findGoodStrings = function(n, s1, s2, evil) {
    const mod = 1e9 + 7;
    const m = evil.length;
    const dp = Array.from({ length: n + 1 }, () => Array.from({ length: m + 1 }, () => Array(3).fill(-1)));
    const kmp = Array(m).fill(0);
    
    // Preprocess the evil string using KMP algorithm
    for (let i = 1, j = 0; i < m; i++) {
        while (j > 0 && evil[i] !== evil[j]) {
            j = kmp[j - 1];
        }
        if (evil[i] === evil[j]) {
            j++;
        }
        kmp[i] = j;
    }
    
    const dfs = (pos, evilPos, isPrefixS1, isPrefixS2) => {
        if (evilPos === m) return 0; // Found the evil string
        if (pos === n) return 1; // Reached the end of the string
        
        if (dp[pos][evilPos][isPrefixS1 * 2 + isPrefixS2] !== -1) {
            return dp[pos][evilPos][isPrefixS1 * 2 + isPrefixS2];
        }
        
        let count = 0;
        const lowerBound = isPrefixS1 ? s1[pos] : 'a';
        const upperBound = isPrefixS2 ? s2[pos] : 'z';
        
        for (let charCode = lowerBound.charCodeAt(0); charCode <= upperBound.charCodeAt(0); charCode++) {
            const char = String.fromCharCode(charCode);
            let nextEvilPos = evilPos;
            
            // Update the position in the evil string using KMP
            while (nextEvilPos > 0 && char !== evil[nextEvilPos]) {
                nextEvilPos = kmp[nextEvilPos - 1];
            }
            if (char === evil[nextEvilPos]) {
                nextEvilPos++;
            }
            
            count += dfs(pos + 1, nextEvilPos, isPrefixS1 && char === lowerBound, isPrefixS2 && char === upperBound);
            count %= mod;
        }
        
        dp[pos][evilPos][isPrefixS1 * 2 + isPrefixS2] = count;  
        return count;
    }
    return dfs(0, 0, true, true);  
};