# You are given a string s.
# A string t is called good if all characters of t occur the same number of times.
# You can perform the following operations any number of times:
# Delete a character from s.
# Insert a character in s.
# Change a character in s to its next letter in the alphabet.
# Note that you cannot change 'z' to 'a' using the third operation.
# Return the minimum number of operations required to make s good.
# Example 1:
# Input: s = "acab"
# Output: 1
# Explanation:
# We can make s good by deleting one occurrence of character 'a'.
# Example 2:
# Input: s = "wddw"
# Output: 0
# Explanation:
# We do not need to perform any operations since s is initially good.
# Example 3:
# Input: s = "aaabc"
# Output: 2
# Explanation:
# We can make s good by applying these operations:
# Change one occurrence of 'a' to 'b'
# Insert one occurrence of 'c' into s
# Constraints:
# 3 <= s.length <= 2 * 104
# s contains only lowercase English letters.

class Solution(object):
    def makeStringGood(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import Counter

        # Count the frequency of each character in s
        freq = Counter(s)
        
        # Get the unique frequencies
        unique_freq = list(freq.values())
        
        # If all characters already have the same frequency, return 0
        if len(set(unique_freq)) == 1:
            return 0
        
        # Find the minimum frequency and maximum frequency
        min_freq = min(unique_freq)
        max_freq = max(unique_freq)
        
        # Calculate the number of operations needed to make all frequencies equal
        operations = 0
        
        for f in unique_freq:
            if f < max_freq:
                operations += (max_freq - f)
            elif f > min_freq:
                operations += (f - min_freq)
        return operations
        