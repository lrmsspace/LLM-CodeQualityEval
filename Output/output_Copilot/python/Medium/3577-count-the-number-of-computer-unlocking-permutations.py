# You are given an array complexity of length n.
# There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].
# The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:
# You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
# To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].
# Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.
# Since the answer may be large, return it modulo 109 + 7.
# Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.
# Example 1:
# Input: complexity = [1,2,3]
# Output: 2
# Explanation:
# The valid permutations are:
# [0, 1, 2]
# Unlock computer 0 first with root password.
# Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
# Unlock computer 2 with password of computer 1 since complexity[1] < complexity[2].
# [0, 2, 1]
# Unlock computer 0 first with root password.
# Unlock computer 2 with password of computer 0 since complexity[0] < complexity[2].
# Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
# Example 2:
# Input: complexity = [3,3,3,4,4,4]
# Output: 0
# Explanation:
# There are no possible permutations which can unlock all computers.
# Constraints:
# 2 <= complexity.length <= 105
# 1 <= complexity[i] <= 109

class Solution(object):
    def countPermutations(self, complexity):
        """
        :type complexity: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(complexity)
        
        # Sort the complexity and keep track of original indices
        sorted_indices = sorted(range(n), key=lambda x: complexity[x])
        
        # Initialize factorials and inverse factorials
        fact = [1] * (n + 1)
        inv_fact = [1] * (n + 1)
        
        for i in range(2, n + 1):
            fact[i] = fact[i - 1] * i % MOD
        
        inv_fact[n] = pow(fact[n], MOD - 2, MOD)
        for i in range(n - 1, 0, -1):
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD
        
        # Count the number of valid permutations
        count = 1
        for i in range(1, n):
            if complexity[sorted_indices[i]] <= complexity[sorted_indices[i - 1]]:
                return 0
            
            # Count how many elements are less than the current one
            less_count = sum(1 for j in range(i) if complexity[sorted_indices[j]] < complexity[sorted_indices[i]])
            count = count * less_count % MOD
        
        return count        