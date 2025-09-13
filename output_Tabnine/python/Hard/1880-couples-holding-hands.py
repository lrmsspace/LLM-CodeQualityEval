#https://leetcode.com/problems/couples-holding-hands/
#There are n couples sitting in 2n seats arranged in a row and want to hold hands.
#The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
#Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.
# 
#Example 1:
#Input: row = [0,2,1,3]
#Output: 1
#Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
#Example 2:
#Input: row = [3,2,0,1]
#Output: 0
#Explanation: All couples are already seated side by side.
# 
#Constraints:
#	2n == row.length
#	2 <= n <= 30
#	n is even.
#	0 <= row[i] < 2n
#	All the elements of row are unique.
class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        def find(x):
            while row[x]!= x:
                x = row[x]
            return x
        
        n = len(row) // 2
        parents = list(range(n * 2))
        
        for i in range(n):
            couple = row[i * 2] // 2
            parent1, parent2 = find(couple * 2), find(couple * 2 + 1)
            
            if parent1!= parent2:
                parents[parent1] = parent2
        
        swaps = 0
        for i in range(n):
            couple = row[i * 2] // 2
            parent = find(couple * 2)
            
            if couple * 2 + 1!= parents[parent]:
                swaps += 1
                row[couple * 2 + 1], row[parents[parent]] = row[parents[parent]], row[couple * 2 + 1]
                parents[parents[parent]] = couple * 2 + 1
                row[couple * 2 + 1], row[parents[parent]] = row[parents[parent]], row[couple * 2 + 1]
                parents[parents[parent]] = couple * 2 + 1
        
        return swaps
        