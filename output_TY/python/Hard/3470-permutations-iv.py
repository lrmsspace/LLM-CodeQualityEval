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

from math import factorial

class Solution(object):
    def permute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        # 计算组合数C(n, m)
        def comb(n, m):
            if m > n or m < 0:
                return 0
            result = 1
            for i in range(m):
                result *= (n - i)
            return result
        
        # 计算可能的排列总数
        odd_count = (n + 1) // 2  # 1,3,5,...的个数
        even_count = n // 2       # 2,4,6,...的个数
        
        # 检查是否可能有解
        total = 0
        # 两种可能的起始类型：奇开头或偶开头
        if abs(odd_count - even_count) <= 1:
            total += factorial(odd_count) * factorial(even_count)
        
        if k > total:
            return []
        
        result = []
        used = [False] * (n + 1)
        # 确定第一个数字是奇数还是偶数
        is_odd_turn = None
        
        if odd_count == even_count + 1 or odd_count == even_count:
            # 奇数开头
            count = 0
            for i in range(1, n+1, 2):  # 遍历所有奇数
                if used[i]:
                    continue
                count += 1
                if count == k:
                    result.append(i)
                    used[i] = True
                    odd_count -= 1
                    is_odd_turn = False
                    break
        else:
            # 偶数开头
            count = 0
            for i in range(2, n+1, 2):  # 遍历所有偶数
                if used[i]:
                    continue
                count += 1
                if count == k:
                    result.append(i)
                    used[i] = True
                    even_count -= 1
                    is_odd_turn = True
                    break
        
        # 构造剩余的序列
        while len(result) < n:
            if is_odd_turn:
                # 选择下一个奇数
                count = 0
                for i in range(1, n+1, 2):
                    if not used[i]:
                        count += 1
                        if count == 1:
                            result.append(i)
                            used[i] = True
                            odd_count -= 1
                            is_odd_turn = False
                            break
            else:
                # 选择下一个偶数
                count = 0
                for i in range(2, n+1, 2):
                    if not used[i]:
                        count += 1
                        if count == 1:
                            result.append(i)
                            used[i] = True
                            even_count -= 1
                            is_odd_turn = True
                            break
        
        return result
    