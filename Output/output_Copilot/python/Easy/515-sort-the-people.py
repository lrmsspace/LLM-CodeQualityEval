#https://leetcode.com/problems/sort-the-people/
#You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
#For each index i, names[i] and heights[i] denote the name and height of the ith person.
#Return names sorted in descending order by the people's heights.
# 
#Example 1:
#Input: names = ["Mary","John","Emma"], heights = [180,165,170]
#Output: ["Mary","Emma","John"]
#Explanation: Mary is the tallest, followed by Emma and John.
#Example 2:
#Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
#Output: ["Bob","Alice","Bob"]
#Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
# 
#Constraints:
#	n == names.length == heights.length
#	1 <= n <= 103
#	1 <= names[i].length <= 20
#	1 <= heights[i] <= 105
#	names[i] consists of lower and upper case English letters.
#	All the values of heights are distinct.
class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        # 1. zip() 函数将 names 和 heights 列表打包成一个元组列表
        # 2. sorted() 函数根据第二个元素（height）进行排序，reverse=True 表示降序排列
        # 3. 使用列表推导式提取排序后的 names 列表
        return [name for name, height in sorted(zip(names, heights), key=lambda x: x[1], reverse=True)]        