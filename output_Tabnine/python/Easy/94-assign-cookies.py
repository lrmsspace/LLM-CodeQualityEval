#https://leetcode.com/problems/assign-cookies/
#Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
#Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
# 
#Example 1:
#Input: g = [1,2,3], s = [1,1]
#Output: 1
#Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
#And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
#You need to output 1.
#Example 2:
#Input: g = [1,2], s = [1,2,3]
#Output: 2
#Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
#You have 3 cookies and their sizes are big enough to gratify all of the children, 
#You need to output 2.
# 
#Constraints:
#	1 <= g.length <= 3 * 104
#	0 <= s.length <= 3 * 104
#	1 <= g[i], s[j] <= 231 - 1
# 
#Note: This question is the same as  2410: Maximum Matching of Players With Trainers.
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        # Sort both arrays in non-decreasing order
        g.sort()
        s.sort()
        
        # Initialize two pointers: one for greed factors and one for cookie sizes
        i, j = 0, 0
        
        # Initialize the maximum number of content children as 0
        max_content_children = 0
        
        # Iterate through both arrays simultaneously
        while i < len(g) and j < len(s):
            # If the current cookie size is greater than or equal to the current greed factor
            if s[j] >= g[i]:
                # Increment the maximum number of content children and move both pointers forward
                max_content_children += 1
                i += 1
                j += 1
            # If the current cookie size is less than the current greed factor
            else:
                # Move the pointer for cookie sizes forward
                j += 1
        
        # Return the maximum number of content children
        return max_content_children
        