#https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
#You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
#You are also given a string s of length n, where s[i] is the character assigned to node i.
#Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
# 
#Example 1:
#Input: parent = [-1,0,0,1,1,2], s = "abacbe"
#Output: 3
#Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
#It can be proven that there is no longer path that satisfies the conditions. 
#Example 2:
#Input: parent = [-1,0,0,0], s = "aabc"
#Output: 3
#Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.
# 
#Constraints:
#	n == parent.length == s.length
#	1 <= n <= 105
#	0 <= parent[i] <= n - 1 for all i >= 1
#	parent[0] == -1
#	parent represents a valid tree.
#	s consists of only lowercase English letters.
class Solution(object):
    def longestPath(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """
        # Initialize a dictionary to store the children of each node
        children = {i: [] for i in range(len(parent))}
        
        # Populate the children dictionary
        for i in range(1, len(parent)):
            children[parent[i]].append(i)
        
        # Initialize a dictionary to store the maximum length of a path ending at each node
        max_length = {i: 0 for i in range(len(parent))}
        
        # Initialize a stack to store the nodes for which we need to calculate the maximum length
        stack = [i for i in range(len(parent)) if parent[i] == -1]
        
        # Perform a depth-first search to calculate the maximum length of a path ending at each node
        while stack:
            node = stack.pop()
            for child in children[node]:
                # Update the maximum length of the current node by adding 1 to the maximum length of its child
                max_length[node] = max(max_length[node], max_length[child] + 1)
                # Push the child node onto the stack for further processing
                stack.append(child)
        
        # Return the maximum length of a path where no pair of adjacent nodes have the same character assigned to them
        return max(max_length.values())
    
        