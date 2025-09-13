# You are given a collection of numbered balls and instructed to sort them into boxes for a nearly balanced distribution. There are two rules you must follow:
# Balls with the same box must have the same value. But, if you have more than one ball with the same number, you can put them in different boxes.
# The biggest box can only have one more ball than the smallest box.
# ​Return the fewest number of boxes to sort these balls following these rules.
# Example 1: 
# Input:   balls = [3,2,3,2,3] 
# Output:   2 
# Explanation:
# We can sort balls into boxes as follows:
# [3,3,3]
# [2,2]
# The size difference between the two boxes doesn't exceed one.
# Example 2: 
# Input:   balls = [10,10,10,3,1,1] 
# Output:   4 
# Explanation:
# We can sort balls into boxes as follows:
# [10]
# [10,10]
# [3]
# [1,1]
# You can't use fewer than four boxes while still following the rules. For example, putting all three balls numbered 10 in one box would break the rule about the maximum size difference between boxes.
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109

class Solution(object):
    def minGroupsForValidAssignment(self, balls):
        """
        :type balls: List[int]
        :rtype: int
        """
        from collections import Counter
        from math import ceil

        # Count the frequency of each ball number
        freq = Counter(balls)
        freq_values = list(freq.values())

        # Function to calculate the number of groups for a given size
        def groups(size):
            return sum(ceil(count / (size + 1)) for count in freq_values)

        # Try different sizes from 1 to the minimum frequency
        for size in range(1, min(freq_values) + 1):
            # Check if the current size or size + 1 is valid
            if groups(size) == groups(size + 1):
                return groups(size)
            elif groups(size) == groups(size - 1):
                return groups(size)

        # If no valid size is found, return the number of unique ball numbers
        return len(freq)        