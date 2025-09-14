#https://leetcode.com/problems/find-the-shortest-superstring/
#Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
#You may assume that no string in words is a substring of another string in words.
# 
#Example 1:
#Input: words = ["alex","loves","leetcode"]
#Output: "alexlovesleetcode"
#Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
#Example 2:
#Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
#Output: "gctaagttcatgcatc"
# 
#Constraints:
#	1 <= words.length <= 12
#	1 <= words[i].length <= 20
#	words[i] consists of lowercase English letters.
#	All the strings of words are unique.
class Solution(object):
    def shortestSuperstring(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        # Build a graph where each node represents a word and each edge represents a common substring
        graph = {}
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                common = self.find_common_suffix(words[i], words[j])
                if common:
                    if words[i] not in graph:
                        graph[words[i]] = []
                    if words[j] not in graph:
                        graph[words[j]] = []
                    graph[words[i]].append(words[j])
                    graph[words[j]].append(words[i])
        
        # Perform a topological sort on the graph to get the order in which words can be concatenated
        order = self.topological_sort(graph)
        
        # Build the shortest superstring by concatenating the words in the order
        superstring = ""
        for word in order:
            superstring += word
            # Remove the concatenated word from the graph
            for neighbor in graph[word]:
                graph[neighbor].remove(word)
                if len(graph[neighbor]) == 0:
                    del graph[neighbor]
        
        # Concatenate the remaining words in the order
        for word in order:
            superstring += word
        
        return superstring
        