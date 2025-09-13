#https://leetcode.com/problems/similar-string-groups/
#Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
#For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
#Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
#We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
# 
#Example 1:
#Input: strs = ["tars","rats","arts","star"]
#Output: 2
#Example 2:
#Input: strs = ["omv","ovm"]
#Output: 1
# 
#Constraints:
#	1 <= strs.length <= 300
#	1 <= strs[i].length <= 300
#	strs[i] consists of lowercase letters only.
#	All words in strs have the same length and are anagrams of each other.
class Solution(object):
    def numSimilarGroups(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        n = len(strs)
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        visited = [False] * n
        groups = 0
        for i in range(n):
            if not visited[i]:
                groups += 1
                self.dfs(strs, visited, i)
        return groups
    
    def dfs(self, strs, visited, i):
        visited[i] = True
        for j in range(len(strs)):
            if not visited[j] and self.isSimilar(strs[i], strs[j]):
                self.dfs(strs, visited, j)
    def isSimilar(self, s1, s2):
        diff = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diff += 1
                if diff > 2:
                    return False
        return diff == 0 or diff == 2
