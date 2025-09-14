# You are given a binary string s of length n, where:
# '1' represents an active section.
# '0' represents an inactive section.
# You can perform at most one trade to maximize the number of active sections in s. In a trade, you:
# Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
# Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
# Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].
# For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].
# Return an array answer, where answer[i] is the result for queries[i].
# Note
# For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
# The queries are independent of each other.
# Example 1:
# Input: s = "01", queries = [[0,1]]
# Output: [1]
# Explanation:
# Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
# Example 2:
# Input: s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]
# Output: [4,3,1,1]
# Explanation:
# Query [0, 3] → Substring "0100" → Augmented to "101001"
# 	Choose "0100", convert "0100" → "0000" → "1111".
# 	The final string without augmentation is "1111". The maximum number of active sections is 4.
# Query [0, 2] → Substring "010" → Augmented to "10101"
# 	Choose "010", convert "010" → "000" → "111".
# 	The final string without augmentation is "1110". The maximum number of active sections is 3.
# Query [1, 3] → Substring "100" → Augmented to "11001"
# 	Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
# Query [2, 3] → Substring "00" → Augmented to "1001"
# 	Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
# Example 3:
# Input: s = "1000100", queries = [[1,5],[0,6],[0,4]]
# Output: [6,7,2]
# Explanation:
# Query [1, 5] → Substring "00010" → Augmented to "1000101"
# 	Choose "00010", convert "00010" → "00000" → "11111".
# 	The final string without augmentation is "1111110". The maximum number of active sections is 6.
# Query [0, 6] → Substring "1000100" → Augmented to "110001001"
# 	Choose "000100", convert "000100" → "000000" → "111111".
# 	The final string without augmentation is "1111111". The maximum number of active sections is 7.
# Query [0, 4] → Substring "10001" → Augmented to "1100011"
# 	Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.
# Example 4:
# Input: s = "01010", queries = [[0,3],[1,4],[1,3]]
# Output: [4,4,2]
# Explanation:
# Query [0, 3] → Substring "0101" → Augmented to "101011"
# 	Choose "010", convert "010" → "000" → "111".
# 	The final string without augmentation is "11110". The maximum number of active sections is 4.
# Query [1, 4] → Substring "1010" → Augmented to "110101"
# 	Choose "010", convert "010" → "000" → "111".
# 	The final string without augmentation is "01111". The maximum number of active sections is 4.
# Query [1, 3] → Substring "101" → Augmented to "11011"
# 	Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.
# Constraints:
# 1 <= n == s.length <= 105
# 1 <= queries.length <= 105
# s[i] is either '0' or '1'.
# queries[i] = [li, ri]
# 0 <= li <= ri < n
class Solution(object):
    def maxActiveSectionsAfterTrade(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        n = len(s)
        m = len(queries)
        
        # 预处理所有1段和0段
        ones_segments = []
        zeros_segments = []
        
        i = 0
        while i < n:
            if s[i] == '1':
                j = i
                while j < n and s[j] == '1':
                    j += 1
                ones_segments.append((i, j-1))
                i = j
            else:
                j = i
                while j < n and s[j] == '0':
                    j += 1
                zeros_segments.append((i, j-1))
                i = j
        
        # 构建前缀和数组
        ones_prefix = [0] * (n + 2)
        zero_blocks = [0] * (n + 2)
        curr_block_id = 0
        
        i = 0
        while i < n:
            if s[i] == '1':
                j = i
                while j < n and s[j] == '1':
                    j += 1
                for k in range(i, j):
                    ones_prefix[k+1] = ones_prefix[i] + 1
                i = j
            else:
                j = i
                while j < n and s[j] == '0':
                    j += 1
                for k in range(i, j):
                    zero_blocks[k+1] = curr_block_id
                curr_block_id += 1
                i = j
        
        # 处理每个查询
        results = []
        for l, r in queries:
            # 计算原始活跃区块数
            active_count = 0
            prev = -2
            for i in range(l, r+1):
                if s[i] == '1' and (i == l or s[i-1] != '1'):
                    active_count += 1
            
            max_active = active_count
            
            # 寻找可以移除的1块
            for start, end in ones_segments:
                if start > l and end < r:
                    # 检查是否被0包围
                    if s[start-1] == '0' and s[end+1] == '0':
                        # 移除这个1块的贡献
                        removed_contribution = 0
                        if start >= l and end <= r:
                            if start == l or s[start-1] != '1':
                                removed_contribution += 1
                        
                        # 寻找可以添加的0块
                        for z_start, z_end in zeros_segments:
                            if z_start > start and z_end < end:
                                # 检查是否被1包围
                                if s[z_start-1] == '1' and s[z_end+1] == '1':
                                    # 计算新增的活跃区块
                                    added_contribution = 0
                                    if z_start >= l and z_end <= r:
                                        if z_start == l or s[z_start-1] != '1':
                                            added_contribution += 1
                                    
                                    # 更新最大值
                                    max_active = max(max_active, active_count - removed_contribution + added_contribution)
            
            results.append(max_active)
        
        return results