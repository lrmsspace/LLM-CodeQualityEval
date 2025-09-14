# You are given a 2D integer array edges representing an undirected graph having n nodes, where edges[i] = [ui, vi] denotes an edge between nodes ui and vi.
# Construct a 2D grid that satisfies these conditions:
# The grid contains all nodes from 0 to n - 1 in its cells, with each node appearing exactly once.
# Two nodes should be in adjacent grid cells (horizontally or vertically) if and only if there is an edge between them in edges.
# It is guaranteed that edges can form a 2D grid that satisfies the conditions.
# Return a 2D integer array satisfying the conditions above. If there are multiple solutions, return any of them.
# Example 1:
# Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]]
# Output: [[3,1],[2,0]]
# Explanation:
# Example 2:
# Input: n = 5, edges = [[0,1],[1,3],[2,3],[2,4]]
# Output: [[4,2,3,1,0]]
# Explanation:
# Example 3:
# Input: n = 9, edges = [[0,1],[0,4],[0,5],[1,7],[2,3],[2,4],[2,5],[3,6],[4,6],[4,7],[6,8],[7,8]]
# Output: [[8,6,3],[7,4,2],[1,0,5]]
# Explanation:
# Constraints:
# 2 <= n <= 5 * 104
# 1 <= edges.length <= 105
# edges[i] = [ui, vi]
# 0 <= ui < vi < n
# All the edges are distinct.
# The input is generated such that edges can form a 2D grid that satisfies the conditions.

class Solution(object):
    def constructGridLayout(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        # Step 1: Build adjacency list
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Step 2: Find a node with minimal degree (could be corner or edge)
        degrees = [(len(graph[i]), i) for i in range(n)]
        degrees.sort()
        start_node = degrees[0][1]

        # Step 3: BFS to assign coordinates
        visited = set()
        coord_map = {}  # node -> (x, y)
        queue = deque()
        queue.append((start_node, 0, 0))
        visited.add(start_node)
        coord_map[start_node] = (0, 0)

        max_x, max_y = 0, 0

        while queue:
            node, x, y = queue.popleft()

            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    # Try to assign new coordinate (simple grid layout assumption)
                    dx, dy = 0, 0
                    for nx, ny in [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]:
                        if (nx, ny) not in coord_map.values():
                            dx, dy = nx, ny
                            break
                    coord_map[neighbor] = (dx, dy)
                    queue.append((neighbor, dx, dy))
                    max_x = max(max_x, dx)
                    max_y = max(max_y, dy)

        # Step 4: Build the grid from coordinate map
        grid = [[-1]*(max_y+1) for _ in range(max_x+1)]
        for node, (x, y) in coord_map.items():
            grid[x][y] = node

        return grid

        