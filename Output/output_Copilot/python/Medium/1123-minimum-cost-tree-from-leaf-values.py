#https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#Given an array arr of positive integers, consider all binary trees such that:
#	Each node has either 0 or 2 children;
#	The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
#	The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
#Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
#A node is a leaf if and only if it has zero children.
# 
#Example 1:
#Input: arr = [6,2,4]
#Output: 32
#Explanation: There are two possible trees shown.
#The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
#Example 2:
#Input: arr = [4,11]
#Output: 44
# 
#Constraints:
#	2 <= arr.length <= 40
#	1 <= arr[i] <= 15
#	It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
class Solution(object):
    def mctFromLeafValues(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # 1. 先创建一个栈 stack，初始化为空
        stack = []
        # 2. 初始化变量 res 为 0
        res = 0
        # 3. 遍历 arr 中的每个元素 num
        for num in arr:
            # 4. 当栈不为空且栈顶元素小于等于 num 时，执行以下操作
            while stack and stack[-1] <= num:
                # 5. 弹出栈顶元素 top，赋值给变量 top
                top = stack.pop()
                # 6. 如果栈不为空，则将 res 加上 top 和栈顶元素的乘积，否则将 res 加上 top 和 num 的乘积
                if stack:
                    res += top * min(stack[-1], num)
                else:
                    res += top * num
            # 7. 将当前元素 num 压入栈中
            stack.append(num)
        # 8. 遍历完 arr 后，继续弹出栈中的元素，直到栈为空
        while len(stack) > 1:
            res += stack.pop() * stack[-1]
        return res        