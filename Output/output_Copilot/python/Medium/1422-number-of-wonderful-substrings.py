#https://leetcode.com/problems/number-of-wonderful-substrings/
#A wonderful string is a string where at most one letter appears an odd number of times.
#	For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
#Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.
#A substring is a contiguous sequence of characters in a string.
# 
#Example 1:
#Input: word = "aba"
#Output: 4
#Explanation: The four wonderful substrings are underlined below:
#- "aba" -> "a"
#- "aba" -> "b"
#- "aba" -> "a"
#- "aba" -> "aba"
#Example 2:
#Input: word = "aabb"
#Output: 9
#Explanation: The nine wonderful substrings are underlined below:
#- "aabb" -> "a"
#- "aabb" -> "aa"
#- "aabb" -> "aab"
#- "aabb" -> "aabb"
#- "aabb" -> "a"
#- "aabb" -> "abb"
#- "aabb" -> "b"
#- "aabb" -> "bb"
#- "aabb" -> "b"
#Example 3:
#Input: word = "he"
#Output: 2
#Explanation: The two wonderful substrings are underlined below:
#- "he" -> "h"
#- "he" -> "e"
# 
#Constraints:
#	1 <= word.length <= 105
#	word consists of lowercase English letters from 'a' to 'j'.
class Solution(object):

    def wonderfulSubstrings(self, word):

        """

        :type word: str

        :rtype: int

        """
        # 1. 初始化变量
        n = len(word)
        ans = 0
        count = [0] * 1024
        count[0] = 1
        mask = 0
        # 2. 遍历字符串
        for i in range(n):
            # 3. 更新掩码
            mask ^= 1 << (ord(word[i]) - ord('a'))
            # 4. 计算当前掩码的出现次数
            ans += count[mask]
            # 5. 遍历所有可能的奇数位掩码
            for j in range(10):
                ans += count[mask ^ (1 << j)]
            # 6. 更新掩码出现次数
            count[mask] += 1
        return ans  