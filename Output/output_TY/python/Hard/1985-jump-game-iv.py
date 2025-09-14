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
        if n == 1: return 0
        
        graph = defaultdict(list)
        for i in range(n):
            graph[arr[i]].append(i)
        
        visited = [False] * n
        queue = deque([(0, 0)])
        visited[0] = True
        
        while queue:
            node, step = queue.popleft()
            if node == n - 1: return step
            
            for next_node in graph[arr[node]] + [node - 1, node + 1]:
                if 0 <= next_node < n and not visited[next_node]:
                    visited[next_node] = True
                    queue.append((next_node, step + 1))
                    graph[arr[next_node]].remove(next_node)
                    graph[arr[node]].remove(next_node)
                    if not graph[arr[next_node]]:
                        del graph[arr[next_node]]
                        del graph[arr[node]]
                        break
                    if not graph[arr[node]]:
                        del graph[arr[node]]
                        break
                    if not graph[arr[next_node]]:
                        del graph[arr[next_node]]
                        break
                    if not graph[arr[node]]:
                        del graph[arr[node]]
                        break
                    break
                if not graph[arr[node]]:
                    del graph[arr[node]]
                    break
                if not graph[arr[next_node]]:
                    del graph[arr[next_node]]
                    break
                break
            if not graph[arr[node]]:
                del graph[arr[node]]
                break
            break
        return -1
    
