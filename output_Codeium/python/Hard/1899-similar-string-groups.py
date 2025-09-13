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
        def dfs(i, j, A, B):
            if i == len(A):
                return True
            if A[i] == B[j]:
                return dfs(i + 1, j + 1, A, B)
            for k in range(len(B)):
                if A[i] == B[k]:
                    B[j], B[k] = B[k], B[j]
                    if dfs(i + 1, j + 1, A, B):
                        return True
                    B[j], B[k] = B[k], B[j]
            return False

        n = len(strs)
        f = [-1] * n
        def find(x):
            if f[x] < 0:
                f[x] = x
            else:
                f[x] = find(f[x])
            return f[x]

        for i in range(n):
            for j in range(i):
                if dfs(0, 0, strs[i], strs[j]):
                    f[find(i)] = find(j)

        return sum(f[i] == i for i in range(n))
