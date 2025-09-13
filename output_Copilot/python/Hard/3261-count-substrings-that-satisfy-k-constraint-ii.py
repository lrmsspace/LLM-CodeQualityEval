# You are given a binary string s and an integer k.
# You are also given a 2D integer array queries, where queries[i] = [li, ri].
# A binary string satisfies the k-constraint if either of the following conditions holds:
# The number of 0's in the string is at most k.
# The number of 1's in the string is at most k.
# Return an integer array answer, where answer[i] is the number of substrings of s[li..ri] that satisfy the k-constraint.
# Example 1:
# Input: s = "0001111", k = 2, queries = [[0,6]]
# Output: [26]
# Explanation:
# For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the k-constraint except for the substrings s[0..5] = "000111" and s[0..6] = "0001111".
# Example 2:
# Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
# Output: [15,9,3]
# Explanation:
# The substrings of s with a length greater than 3 do not satisfy the k-constraint.
# Constraints:
# 1 <= s.length <= 105
# s[i] is either '0' or '1'.
# 1 <= k <= s.length
# 1 <= queries.length <= 105
# queries[i] == [li, ri]
# 0 <= li <= ri < s.length
# All queries are distinct.

class Solution(object):
    def countKConstraintSubstrings(self, s, k, queries):
        """
        :type s: str
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def count_substrings_with_k_constraint(l, r):
            count = 0
            zero_count = 0
            one_count = 0
            left = l
            
            for right in range(l, r + 1):
                if s[right] == '0':
                    zero_count += 1
                else:
                    one_count += 1
                
                while zero_count > k and one_count > k:
                    if s[left] == '0':
                        zero_count -= 1
                    else:
                        one_count -= 1
                    left += 1
                
                count += (right - left + 1)
            
            return count
        
        result = []
        for l, r in queries:
            result.append(count_substrings_with_k_constraint(l, r))
        
        return result
        