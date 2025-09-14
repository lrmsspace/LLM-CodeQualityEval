# You are given an array nums which is a permutation of [0, 1, 2, ..., n - 1]. The score of any permutation of [0, 1, 2, ..., n - 1] named perm is defined as:
# score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|
# Return the permutation perm which has the minimum possible score. If multiple permutations exist with this score, return the one that is lexicographically smallest among them.
# Example 1:
# Input: nums = [1,0,2]
# Output: [0,1,2]
# Explanation:
# The lexicographically smallest permutation with minimum cost is [0,1,2]. The cost of this permutation is |0 - 0| + |1 - 2| + |2 - 1| = 2.
# Example 2:
# Input: nums = [0,2,1]
# Output: [0,2,1]
# Explanation:
# The lexicographically smallest permutation with minimum cost is [0,2,1]. The cost of this permutation is |0 - 1| + |2 - 2| + |1 - 0| = 2.
# Constraints:
# 2 <= n == nums.length <= 14
# nums is a permutation of [0, 1, 2, ..., n - 1].

class Solution(object):
    def findPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        n = len(nums)
        # Create a list to store the result
        result = [0] * n

        # Create a list to store the positions of each number
        positions = [[] for _ in range(n)]
        for i in range(n):
            positions[nums[i]].append(i)

        # Create a list to store the current position of each number
        current_positions = [0] * n
        for i in range(n):
            current_positions[nums[i]] = i

        # Find the permutation with the minimum cost
        for i in range(n):
            # Find the minimum position for the current number
            min_pos = min(positions[i])
            result[i] = min_pos
            # Update the positions of the current number
            positions[i].remove(min_pos)
            current_positions[i] = min_pos

        return result