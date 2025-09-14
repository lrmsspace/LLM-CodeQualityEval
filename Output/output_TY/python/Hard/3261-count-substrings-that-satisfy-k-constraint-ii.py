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
        n = len(s)
        
        # 预处理：对于每个位置 i，找到最远的 j，使得 s[j..i] 满足约束
        # 即：子串中 0 的个数 <= k 或 1 的个数 <= k
        res = [0] * n
        count = [0, 0]
        left = 0
        for right in range(n):
            count[int(s[right])] += 1
            while count[0] > k and count[1] > k:
                count[int(s[left])] -= 1
                left += 1
            res[right] = left
        
        # 构建前缀和数组：pre_sum[i] 表示前 i 个位置的总合法子串数
        pre_sum = [0] * (n + 1)
        for i in range(n):
            valid_len = i - res[i] + 1
            pre_sum[i + 1] = pre_sum[i] + valid_len
        
        # 处理每个查询 [l, r]
        answer = []
        for l, r in queries:
            # 计算在 [l, r] 范围内的有效子串数
            # 找到所有右端点在 [l, r] 的子串，并且起始点 >= res[r]
            total = 0
            for i in range(l, r + 1):
                start = max(res[i], l)
                total += i - start + 1
            answer.append(total)
        
        return total