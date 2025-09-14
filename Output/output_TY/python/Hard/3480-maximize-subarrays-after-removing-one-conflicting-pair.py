# You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.
# Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].
# Return the maximum number of subarrays possible after removing exactly one conflicting pair.
# Example 1:
# Input: n = 4, conflictingPairs = [[2,3],[1,4]]
# Output: 9
# Explanation:
# Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
# There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
# The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
# Example 2:
# Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]
# Output: 12
# Explanation:
# Remove [1, 2] from conflictingPairs. Now, conflictingPairs = [[2, 5], [3, 5]].
# There are 12 subarrays in nums where [2, 5] and [3, 5] do not appear together.
# The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 12.
# Constraints:
# 2 <= n <= 105
# 1 <= conflictingPairs.length <= 2 * n
# conflictingPairs[i].length == 2
# 1 <= conflictingPairs[i][j] <= n
# conflictingPairs[i][0] != conflictingPairs[i][1]

class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        """
        :type n: int
        :type conflictingPairs: List[List[int]]
        :rtype: int
        """
        # 创建两个字典来记录每个数字涉及的冲突对
        conflict_map = {}
        for a, b in conflictingPairs:
            if a not in conflict_map:
                conflict_map[a] = set()
            if b not in conflict_map:
                conflict_map[b] = set()
            conflict_map[a].add(b)
            conflict_map[b].add(a)
        
        # 计算所有可能的子数组总数
        total_subarrays = n * (n + 1) // 2
        
        # 如果没有冲突对，返回全部子数组数量
        if not conflictingPairs:
            return total_subarrays
        
        # 初始化最大有效子数组数量
        max_valid = 0
        
        # 遍历每个可能的冲突对，尝试移除它
        for a, b in conflictingPairs:
            # 临时存储当前冲突对
            temp_conflicts = []
            
            # 保存被影响的数字及其冲突关系
            affected = {}
            
            # 移除冲突对(a,b)，然后检查其他冲突对的影响
            for c, d in conflictingPairs:
                if (c == a and d == b) or (c == b and d == a):
                    continue  # 跳过要移除的冲突对
                
                # 如果这个冲突对也会影响某些子数组，则保留它
                if c not in affected:
                    affected[c] = set()
                if d not in affected:
                    affected[d] = set()
                
                affected[c].add(d)
                affected[d].add(c)
            
            # 计算有效的子数组数量
            valid_subarrays = 0
            
            # 对于每个可能的子数组起始点i
            for i in range(1, n + 1):
                # 当前冲突集合
                current_conflicts = set()
                
                # 对于每个结束点j
                for j in range(i, n + 1):
                    # 如果j和i-j之间的任何数有冲突，则不能形成有效子数组
                    is_valid = True
                    for k in range(i, j):
                        if j in affected.get(k, set()):
                            is_valid = False
                            break
                    
                    if is_valid:
                        valid_subarrays += 1
            
            max_valid = max(max_valid, valid_subarrays)
        
        return max_valid
    