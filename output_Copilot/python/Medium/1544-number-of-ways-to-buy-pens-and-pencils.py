#https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
#You are given an integer total indicating the amount of money you have. You are also given two integers cost1 and cost2 indicating the price of a pen and pencil respectively. You can spend part or all of your money to buy multiple quantities (or none) of each kind of writing utensil.
#Return the number of distinct ways you can buy some number of pens and pencils.
# 
#Example 1:
#Input: total = 20, cost1 = 10, cost2 = 5
#Output: 9
#Explanation: The price of a pen is 10 and the price of a pencil is 5.
#- If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
#- If you buy 1 pen, you can buy 0, 1, or 2 pencils.
#- If you buy 2 pens, you cannot buy any pencils.
#The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.
#Example 2:
#Input: total = 5, cost1 = 10, cost2 = 10
#Output: 1
#Explanation: The price of both pens and pencils are 10, which cost more than total, so you cannot buy any writing utensils. Therefore, there is only 1 way: buy 0 pens and 0 pencils.
# 
#Constraints:
#	1 <= total, cost1, cost2 <= 106
class Solution(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        :type total: int
        :type cost1: int
        :type cost2: int
        :rtype: int
        """
        # 计算最多能买多少支笔和铅笔
        max_pens = total // cost1
        max_pencils = total // cost2
        
        # 初始化结果为0
        result = 0
        
        # 遍历每种可能的笔的数量
        for pens in range(max_pens + 1):
            # 计算剩余的钱
            remaining_money = total - pens * cost1
            
            # 计算可以购买的铅笔数量
            pencils = remaining_money // cost2
            
            # 更新结果
            result += pencils + 1        

        return result