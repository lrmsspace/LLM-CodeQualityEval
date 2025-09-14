#https://leetcode.com/problems/cat-and-mouse/
#A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
#The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
#The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
#During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
#Additionally, it is not allowed for the Cat to travel to the Hole (node 0).
#Then, the game can end in three ways:
#	If ever the Cat occupies the same node as the Mouse, the Cat wins.
#	If ever the Mouse reaches the Hole, the Mouse wins.
#	If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
#Given a graph, and assuming both players play optimally, return
#	1 if the mouse wins the game,
#	2 if the cat wins the game, or
#	0 if the game is a draw.
# 
#Example 1:
#Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
#Output: 0
#Example 2:
#Input: graph = [[1,3],[0],[3],[0,2]]
#Output: 1
# 
#Constraints:
#	3 <= graph.length <= 50
#	1 <= graph[i].length < graph.length
#	0 <= graph[i][j] < graph.length
#	graph[i][j] != i
#	graph[i] is unique.
#	The mouse and the cat can always move. 
class Solution(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        # Initialize the variables
        n = len(graph)
        mouse, cat, hole = 1, 2, 0
        visited = [[[False] * n for _ in range(n)] for _ in range(n)]
        
        # Define a helper function to simulate the game
        def simulate(mouse, cat, turn):
            if visited[mouse][cat][turn]:
                return 0
            visited[mouse][cat][turn] = True
            
            # Check if the mouse or cat wins the game
            if mouse == hole:
                return 1
            if cat == hole:
                return 2
            
            # Check if the game is a draw
            if turn == n * n:
                return 0
            
            # Simulate the game for each possible move
            moves = [(mouse, cat + 1), (mouse - 1, cat), (mouse + 1, cat), (mouse, cat - 1)]
        # BFS to find the optimal strategy
        queue = [(mouse, cat, 0)]
        while queue:
            m, c, t = queue.pop(0)
            result = simulate(m, c, t)
            if result!= 0:
                return result
            
            for next_mouse, next_cat in graph[m]:
                if next_mouse == next_cat:
                    continue
                queue.append((next_mouse, next_cat, t + 1))
        
        return 0
        