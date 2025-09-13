#https://leetcode.com/problems/k-similar-strings/
#Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
#Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
# 
#Example 1:
#Input: s1 = "ab", s2 = "ba"
#Output: 1
#Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
#Example 2:
#Input: s1 = "abc", s2 = "bca"
#Output: 2
#Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
# 
#Constraints:
#	1 <= s1.length <= 20
#	s2.length == s1.length
#	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
#	s2 is an anagram of s1.
class Solution(object):
    def kSimilarity(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        from collections import deque

        if s1 == s2:
            return 0

        queue = deque([(s1, 0)])
        visited = {s1}

        while queue:
            current, swaps = queue.popleft()

            if current == s2:
                return swaps

            for i in range(len(current)):
                if current[i] != s2[i]:
                    for j in range(i + 1, len(current)):
                        if current[j] != s2[j] and current[i] == s2[j] and current[j] == s2[i]:
                            new_s = list(current)
                            new_s[i], new_s[j] = new_s[j], new_s[i]
                            new_s = ''.join(new_s)

                            if new_s not in visited:
                                visited.add(new_s)
                                queue.append((new_s, swaps + 1))

                    break   
        return -1     