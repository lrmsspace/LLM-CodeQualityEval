# You are given two arrays of strings wordsContainer and wordsQuery.
# For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.
# Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
# Example 1:
# Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]
# Output: [1,1,1]
# Explanation:
# Let's look at each wordsQuery[i] separately:
# For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
# For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
# For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
# Example 2:
# Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]
# Output: [2,0,2]
# Explanation:
# Let's look at each wordsQuery[i] separately:
# For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
# For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
# For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
# Constraints:
# 1 <= wordsContainer.length, wordsQuery.length <= 104
# 1 <= wordsContainer[i].length <= 5 * 103
# 1 <= wordsQuery[i].length <= 5 * 103
# wordsContainer[i] consists only of lowercase English letters.
# wordsQuery[i] consists only of lowercase English letters.
# Sum of wordsContainer[i].length is at most 5 * 105.
# Sum of wordsQuery[i].length is at most 5 * 105.

class Solution(object):
    def stringIndices(self, wordsContainer, wordsQuery):
        """
        :type wordsContainer: List[str]
        :type wordsQuery: List[str]
        :rtype: List[int]
        """
        def longest_common_suffix(s1, s2):
            """Find the longest common suffix of two strings."""
            i, j = len(s1) - 1, len(s2) - 1
            while i >= 0 and j >= 0 and s1[i] == s2[j]:
                i -= 1
                j -= 1
            return s1[i + 1:]

        ans = []
        for query in wordsQuery:
            max_suffix = ""
            min_length = float('inf')
            index = -1
            
            for i, word in enumerate(wordsContainer):
                suffix = longest_common_suffix(word, query)
                if len(suffix) > len(max_suffix) or (len(suffix) == len(max_suffix) and len(word) < min_length):
                    max_suffix = suffix
                    min_length = len(word)
                    index = i
            
            ans.append(index)
        
        return ans
            