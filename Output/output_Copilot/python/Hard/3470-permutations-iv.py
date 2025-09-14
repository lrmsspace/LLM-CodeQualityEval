# Given two integers, n and k, an alternating permutation is a permutation of the first n positive integers such that no two adjacent elements are both odd or both even.
# Return the k-th alternating permutation sorted in lexicographical order. If there are fewer than k valid alternating permutations, return an empty list.
# Example 1:
# Input: n = 4, k = 6
# Output: [3,4,1,2]
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2, 3, 4] are:
# [1, 2, 3, 4]
# [1, 4, 3, 2]
# [2, 1, 4, 3]
# [2, 3, 4, 1]
# [3, 2, 1, 4]
# [3, 4, 1, 2] ← 6th permutation
# [4, 1, 2, 3]
# [4, 3, 2, 1]
# Since k = 6, we return [3, 4, 1, 2].
# Example 2:
# Input: n = 3, k = 2
# Output: [3,2,1]
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2, 3] are:
# [1, 2, 3]
# [3, 2, 1] ← 2nd permutation
# Since k = 2, we return [3, 2, 1].
# Example 3:
# Input: n = 2, k = 3
# Output: []
# Explanation:
# The lexicographically-sorted alternating permutations of [1, 2] are:
# [1, 2]
# [2, 1]
# There are only 2 alternating permutations, but k = 3, which is out of range. Thus, we return an empty list [].
# Constraints:
# 1 <= n <= 100
# 1 <= k <= 1015

class Solution(object):
    def permute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        if n == 1:
            return [1] if k == 1 else []
        
        # Generate the first half of the permutation
        first_half = list(range(1, n // 2 + 1))
        second_half = list(range(n // 2 + 1, n + 1))
        
        # If n is odd, add the middle element
        if n % 2 == 1:
            middle = [n // 2 + 1]
        else:
            middle = []
        
        # Combine the halves and middle element
        permutation = first_half + middle + second_half[::-1]
        
        # If k is greater than the number of permutations, return empty list
        if k > len(permutation):
            return []
        
        return permutation  
        