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
        # Create a dictionary to store the index of each character in s1
        index = {c: i for i, c in enumerate(s1)}
        
        # Initialize the count of swaps and the visited set
        count, visited = 0, set()
        
        # Perform BFS to find the minimum number of swaps
        queue = [(s1, 0)]
        while queue:
            current, i = queue.pop(0)
            if current == s2:
                return count
            
            # Iterate through the current string
            for j in range(i, len(current)):
                if current[j]!= s2[j] and current[j] not in visited:
                    visited.add(current[j])
                    # Swap the characters at indices i and j
                    new_current = current[:j] + current[j] + current[i+1:j] + current[i] + current[j+1:]
                    # Add the new string to the queue
                    queue.append((new_current, j))
                    count += 1
        
        return -1
        