#https://leetcode.com/problems/distribute-money-to-maximum-children/
#You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.
#You have to distribute the money according to the following rules:
#	All money must be distributed.
#	Everyone must receive at least 1 dollar.
#	Nobody receives 4 dollars.
#Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.
# 
#Example 1:
#Input: money = 20, children = 3
#Output: 1
#Explanation: 
#The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
#- 8 dollars to the first child.
#- 9 dollars to the second child. 
#- 3 dollars to the third child.
#It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
#Example 2:
#Input: money = 16, children = 2
#Output: 2
#Explanation: Each child can be given 8 dollars.
# 
#Constraints:
#	1 <= money <= 200
#	2 <= children <= 30
class Solution(object):
    def distMoney(self, money, children):
        """
        :type money: int
        :type children: int
        :rtype: int
        """
        # Calculate the maximum number of children that can receive 8 dollars
        max_eights = money // 8
        
        # Calculate the remaining money after giving 8 dollars to max_eights children
        remaining_money = money - (max_eights * 8)
        
        # If the remaining money is less than the number of children minus the number of children who received 8 dollars, return -1
        if remaining_money < (children - max_eights):
            return -1
        
        # If the remaining money is equal to 4 and there are still children left to give money to, return max_eights - 1
        if remaining_money == 4 and (children - max_eights) > 0:
            return max_eights - 1
        
        # Otherwise, return the maximum number of children who received 8 dollars
        return max_eights      