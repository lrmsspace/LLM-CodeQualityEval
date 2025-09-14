# Attention: In this version, the number of operations that can be performed, has been increased to twice.
# You are given an array nums consisting of positive integers.
# We call two integers x and y almost equal if both integers can become equal after performing the following operation at most twice:
# Choose either x or y and swap any two digits within the chosen number.
# Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.
# Note that it is allowed for an integer to have leading zeros after performing an operation.
# Example 1:
# Input: nums = [1023,2310,2130,213]
# Output: 4
# Explanation:
# The almost equal pairs of elements are:
# 1023 and 2310. By swapping the digits 1 and 2, and then the digits 0 and 3 in 1023, you get 2310.
# 1023 and 213. By swapping the digits 1 and 0, and then the digits 1 and 2 in 1023, you get 0213, which is 213.
# 2310 and 213. By swapping the digits 2 and 0, and then the digits 3 and 2 in 2310, you get 0213, which is 213.
# 2310 and 2130. By swapping the digits 3 and 1 in 2310, you get 2130.
# Example 2:
# Input: nums = [1,10,100]
# Output: 3
# Explanation:
# The almost equal pairs of elements are:
# 1 and 10. By swapping the digits 1 and 0 in 10, you get 01 which is 1.
# 1 and 100. By swapping the second 0 with the digit 1 in 100, you get 001, which is 1.
# 10 and 100. By swapping the first 0 with the digit 1 in 100, you get 010, which is 10.
# Constraints:
# 2 <= nums.length <= 5000
# 1 <= nums[i] < 107

from collections import Counter

class Solution(object):
    def countPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def normalize(num):
            # 将数字转为排序后的字符串作为规范化表示
            return ''.join(sorted(str(num)))

        freq = Counter()
        for num in nums:
            key = normalize(num)
            freq[key] += 1

        keys = list(freq.keys())
        total_pairs = 0

        for i in range(len(keys)):
            for j in range(i + 1, len(keys)):
                if self.can_transform(keys[i], keys[j]):
                    total_pairs += freq[keys[i]] * freq[keys[j]]
        
        # 单独处理相同规范化形式之间的配对
        for key in freq:
            cnt = freq[key]
            total_pairs += cnt * (cnt - 1) // 2

        return total_pairs

    def can_transform(self, s1, s2):
        # 判断两个字符串是否可以通过最多两次交换变得相同
        diff = []
        for a, b in zip(s1, s2):
            if a != b:
                diff.append((a, b))
            if len(diff) > 2:
                return False
        return True