# You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
# subs has a size of at least k.
# Character a has an odd frequency in subs.
# Character b has a non-zero even frequency in subs.
# Return the maximum difference.
# Note that subs can contain more than 2 distinct characters.
# Example 1:
# Input: s = "12233", k = 4
# Output: -1
# Explanation:
# For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
# Example 2:
# Input: s = "1122211", k = 3
# Output: 1
# Explanation:
# For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.
# Example 3:
# Input: s = "110", k = 3
# Output: -1
# Constraints:
# 3 <= s.length <= 3 * 104
# s consists only of digits '0' to '4'.
# The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
# 1 <= k <= s.length
class Solution(object):
    def maxDifference(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        max_diff = float('-inf')
        n = len(s)
        
        for start in range(n - k + 1):
            freq = [0] * 5  # 只包含数字0-4
            odd_counts = set()  # 当前窗口中奇数次出现的字符
            even_counts = set()  # 当前窗口中偶数次出现的字符
            
            # 初始化第一个窗口
            for i in range(start, start + k):
                digit = int(s[i])
                freq[digit] += 1
                
            # 确定当前窗口的奇数和偶数频率字符
            for i in range(5):
                if freq[i] > 0:
                    if freq[i] % 2 == 1:
                        odd_counts.add(i)
                    else:
                        even_counts.add(i)
            
            # 如果满足条件则计算差值
            if odd_counts and even_counts:
                max_odd = max(odd_counts)
                min_even = min(even_counts)
                diff = freq[max_odd] - freq[min_even]
                max_diff = max(max_diff, diff)
            
            # 滑动窗口
            for end in range(start + k, n):
                # 移除最左边的字符
                left_digit = int(s[start + end - start - k])
                freq[left_digit] -= 1
                if freq[left_digit] == 0:
                    if left_digit in odd_counts:
                        odd_counts.remove(left_digit)
                    if left_digit in even_counts:
                        even_counts.remove(left_digit)
                elif freq[left_digit] % 2 == 1:
                    # 更新奇偶性
                    odd_counts.add(left_digit)
                    if left_digit in even_counts:
                        even_counts.remove(left_digit)
                else:
                    if freq[left_digit] > 0:
                        even_counts.add(left_digit)
                    if left_digit in odd_counts:
                        odd_counts.remove(left_digit)
                
                # 添加新字符
                new_digit = int(s[end])
                freq[new_digit] += 1
                
                if freq[new_digit] == 1:
                    odd_counts.add(new_digit)
                elif freq[new_digit] % 2 == 1:
                    # 从even移除，添加到odd
                    odd_counts.add(new_digit)
                    if new_digit in even_counts:
                        even_counts.remove(new_digit)
                else:
                    # 从odd移除，添加到even
                    even_counts.add(new_digit)
                    if new_digit in odd_counts:
                        odd_counts.remove(new_digit)
                
                # 如果满足条件则计算差值
                if odd_counts and even_counts:
                    max_odd = max(odd_counts)
                    min_even = min(even_counts)
                    diff = freq[max_odd] - freq[min_even]
                    max_diff = max(max_diff, diff)
        
        return max_diff if max_diff != float('-inf') else -1