# Alice and Bob are playing a game. Initially, Alice has a string word = "a".
# You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.
# Now Bob will ask Alice to perform all operations in sequence:
# If operations[i] == 0, append a copy of word to itself.
# If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
# Return the value of the kth character in word after performing all the operations.
# Note that the character 'z' can be changed to 'a' in the second type of operation.
# Example 1:
# Input: k = 5, operations = [0,0,0]
# Output: "a"
# Explanation:
# Initially, word == "a". Alice performs the three operations as follows:
# Appends "a" to "a", word becomes "aa".
# Appends "aa" to "aa", word becomes "aaaa".
# Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
# Example 2:
# Input: k = 10, operations = [0,1,0,1]
# Output: "b"
# Explanation:
# Initially, word == "a". Alice performs the four operations as follows:
# Appends "a" to "a", word becomes "aa".
# Appends "bb" to "aa", word becomes "aabb".
# Appends "aabb" to "aabb", word becomes "aabbaabb".
# Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".
# Constraints:
# 1 <= k <= 1014
# 1 <= operations.length <= 100
# operations[i] is either 0 or 1.
# The input is generated such that word has at least k characters after all operations.

class Solution(object):
    def kthCharacter(self, k, operations):
        """
        :type k: int
        :type operations: List[int]
        :rtype: str
        """
        # We will trace back from k to find the original character and how many shifts it has gone through
        shift = 0
        length = 1
        path = []

        # First compute the length of string after each operation
        for op in operations:
            if op == 0:
                length *= 2
            else:
                length *= 2

        # Trace back to find which half the k is in
        for op in reversed(operations):
            if k > length // 2:
                # It's in the second half
                k -= length // 2
                if op == 1:
                    shift += 1
            # If in first half, do nothing
            length //= 2

        # Original char is 'a' + shift times
        result_char = chr((ord('a') + (k - 1) + shift) % 26)
        return result_char