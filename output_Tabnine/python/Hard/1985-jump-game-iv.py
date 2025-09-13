#https://leetcode.com/problems/jump-game-iv/
#Given an array of integers arr, you are initially positioned at the first index of the array.
#In one step you can jump from index i to index:
#	i + 1 where: i + 1 < arr.length.
#	i - 1 where: i - 1 >= 0.
#	j where: arr[i] == arr[j] and i != j.
#Return the minimum number of steps to reach the last index of the array.
#Notice that you can not jump outside of the array at any time.
# 
#Example 1:
#Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
#Output: 3
#Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
#Example 2:
#Input: arr = [7]
#Output: 0
#Explanation: Start index is the last index. You do not need to jump.
#Example 3:
#Input: arr = [7,6,9,6,9,6,9,7]
#Output: 1
#Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
# 
#Constraints:
#	1 <= arr.length <= 5 * 104
#	-108 <= arr[i] <= 108
class Solution(object):
    def minJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        # Step 1: Create a dictionary to store indices of elements in the array
        index_dict = {}
        for i, num in enumerate(arr):
            index_dict[num] = i
        
        # Step 2: Create a queue to store indices that need to be visited
        queue = collections.deque([0])
        visited = set([0])
        steps = 0
        
        while queue:
            size = len(queue)
            for _ in range(size):
                curr = queue.popleft()
                
                # Check if we have reached the last index
                if curr == n - 1:
                    return steps
                
                # Check if the current index can be jumped to
                for neighbor in (curr + 1, curr - 1, arr.index(arr[curr])):
                    if 0 <= neighbor < n and neighbor not in visited:
                        queue.append(neighbor)
        return -1
        