#https://leetcode.com/problems/find-all-good-strings/
#Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
#A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 109 + 7.
# 
#Example 1:
#Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
#Output: 51 
#Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
#Example 2:
#Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
#Output: 0 
#Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
#Example 3:
#Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
#Output: 2
# 
#Constraints:
#	s1.length == n
#	s2.length == n
#	s1 <= s2
#	1 <= n <= 500
#	1 <= evil.length <= 50
#	All strings consist of lowercase English letters.
class Solution(object):
    def findGoodStrings(self, n, s1, s2, evil):
        """
        :type n: int
        :type s1: str
        :type s2: str
        :type evil: str
        :rtype: int
        """
        def dfs(i, max_match, low, high):
            if max_match == len(evil):
                return 0
            if (i, max_match, low) in memo:
                return memo[(i, max_match, low)]
            res = 0
            low_bound = s1[i] if low else 'a'
            high_bound = s2[i] if high else 'z'
            for c in string.ascii_lowercase[low_bound <= c <= high_bound]:
                next_max_match = max_match
                while next_max_match > 0 and c != evil[next_max_match]:
                    next_max_match = lps[next_max_match - 1]
                next_max_match += c == evil[next_max_match]
                res += dfs(i + 1, next_max_match, low and c == low_bound, high and c == high_bound)
            memo[(i, max_match, low)] = res % 1000000007
            return memo[(i, max_match, low)]
        lps = [0] * len(evil)
        for i in range(1, len(evil)):
            j = lps[i - 1]
            while j > 0 and evil[i] != evil[j]:
                j = lps[j - 1]
            lps[i] = j + (evil[i] == evil[j])
        memo = {}
        return dfs(0, 0, True, True)
        