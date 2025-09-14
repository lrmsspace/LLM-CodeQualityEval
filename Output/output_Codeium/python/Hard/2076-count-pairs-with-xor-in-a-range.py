#https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
#Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.
#A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.
# 
#Example 1:
#Input: nums = [1,4,2,7], low = 2, high = 6
#Output: 6
#Explanation: All nice pairs (i, j) are as follows:
#    - (0, 1): nums[0] XOR nums[1] = 5 
#    - (0, 2): nums[0] XOR nums[2] = 3
#    - (0, 3): nums[0] XOR nums[3] = 6
#    - (1, 2): nums[1] XOR nums[2] = 6
#    - (1, 3): nums[1] XOR nums[3] = 3
#    - (2, 3): nums[2] XOR nums[3] = 5
#Example 2:
#Input: nums = [9,8,4,2,1], low = 5, high = 14
#Output: 8
#Explanation: All nice pairs (i, j) are as follows:
#​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
#    - (0, 3): nums[0] XOR nums[3] = 11
#    - (0, 4): nums[0] XOR nums[4] = 8
#    - (1, 2): nums[1] XOR nums[2] = 12
#    - (1, 3): nums[1] XOR nums[3] = 10
#    - (1, 4): nums[1] XOR nums[4] = 9
#    - (2, 3): nums[2] XOR nums[3] = 6
#    - (2, 4): nums[2] XOR nums[4] = 5
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] <= 2 * 104
#	1 <= low <= high <= 2 * 104
class Solution(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """
        def countPairsWithXORLessThanOrEqualTo(nums, limit):
            count = 0
            trie = {}
            
            def insert(num):
                node = trie
                for i in range(15, -1, -1):
                    bit = (num >> i) & 1
                    if bit not in node:
                        node[bit] = {}
                    node = node[bit]
                node['#'] = num
            
            def countLessThanOrEqual(num, limit):
                node = trie
                count = 0
                for i in range(15, -1, -1):
                    if node is None:
                        break
                    bit_num = (num >> i) & 1
                    bit_limit = (limit >> i) & 1
                    if bit_limit == 1:
                        if bit_num in node:
                            count += len(node[bit_num])
                        node = node.get(1 - bit_num)
                    else:
                        node = node.get(bit_num)
                return count
            
            for num in nums:
                count += countLessThanOrEqual(num, limit)
                insert(num)
            
            return count
        
        return countPairsWithXORLessThanOrEqualTo(nums, high) - countPairsWithXORLessThanOrEqualTo(nums, low - 1)

