#https://leetcode.com/problems/fruit-into-baskets/
#You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
#You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
#	You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
#	Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
#	Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
#Given the integer array fruits, return the maximum number of fruits you can pick.
# 
#Example 1:
#Input: fruits = [1,2,1]
#Output: 3
#Explanation: We can pick from all 3 trees.
#Example 2:
#Input: fruits = [0,1,2,2]
#Output: 3
#Explanation: We can pick from trees [1,2,2].
#If we had started at the first tree, we would only pick from trees [0,1].
#Example 3:
#Input: fruits = [1,2,3,2,2]
#Output: 4
#Explanation: We can pick from trees [2,3,2,2].
#If we had started at the first tree, we would only pick from trees [1,2].
# 
#Constraints:
#	1 <= fruits.length <= 105
#	0 <= fruits[i] < fruits.length
class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        # Initialize variables
        max_count = 0
        basket_1_count = 0
        basket_2_count = 0
        basket_1_type = -1
        basket_2_type = -1
        i = 0
        
        # Iterate through the array
        while i < len(fruits):
            # If the current fruit is the same as the last fruit in basket_1
            if fruits[i] == basket_1_type:
                basket_1_count += 1
            # If the current fruit is the same as the last fruit in basket_2
            elif fruits[i] == basket_2_type:
                basket_2_count += 1
            # If the current fruit is not the same as either basket_1 or basket_2
            else:
                # If both baskets are full, remove the fruit that was picked the least recently
                if basket_1_count == basket_2_count:
                    if fruits[i-1] == basket_1_type:
                        basket_1_count -= 1
                    else:
                        basket_2_count -= 1
        
                # Update the last fruit in basket_1 and the count
                basket_1_type = fruits[i]
                basket_1_count = 1
                
                # Update the last fruit in basket_2 and the count
                basket_2_type = -1
                basket_2_count = 0
            
            # Update the maximum count
            max_count = max(max_count, basket_1_count + basket_2_count)
            
            i += 1
        
        return max_count    
        