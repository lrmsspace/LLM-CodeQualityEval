/*
 There is a directed graph consisting of n nodes numbered from 0 to n - 1 and n directed edges.
 You are given a 0-indexed array edges where edges[i] indicates that there is an edge from node i to node edges[i].
 Consider the following process on the graph:
 You start from a node x and keep visiting other nodes through edges until you reach a node that you have already visited before on this same process.
 Return an array answer where answer[i] is the number of different nodes that you will visit if you perform the process starting from node i.
 Example 1:
 Input: edges = [1,2,0,0]
 Output: [3,3,3,4]
 Explanation: We perform the process starting from each node in the following way:
 - Starting from node 0, we visit the nodes 0 -> 1 -> 2 -> 0. The number of different nodes we visit is 3.
 - Starting from node 1, we visit the nodes 1 -> 2 -> 0 -> 1. The number of different nodes we visit is 3.
 - Starting from node 2, we visit the nodes 2 -> 0 -> 1 -> 2. The number of different nodes we visit is 3.
 - Starting from node 3, we visit the nodes 3 -> 0 -> 1 -> 2 -> 0. The number of different nodes we visit is 4.
 Example 2:
 Input: edges = [1,2,3,4,0]
 Output: [5,5,5,5,5]
 Explanation: Starting from any node we can visit every node in the graph in the process.
 Constraints:
 n == edges.length
 2 <= n <= 105
 0 <= edges[i] <= n - 1
 edges[i] != i
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int node, int* edges, int* visited, int* inStack, int* count, 
         int* cycleLen, int* result, int curStep) {
    // 如果已经计算过这个节点的结果，直接返回
    if (result[node] != 0) {
        *count = result[node];
        return;
    }
    
    // 如果在当前路径中遇到已访问的节点，说明找到了环
    if (inStack[node]) {
        *cycleLen = curStep - visited[node];
        *count = curStep - visited[node];
        return;
    }
    
    // 如果节点已经被其他路径访问过但不在当前路径中
    if (visited[node]) {
        *count = result[node];
        return;
    }
    
    // 标记当前节点为已访问且在当前路径中
    visited[node] = curStep;
    inStack[node] = 1;
    
    // 递归访问下一个节点
    int nextCount = 0, nextCycleLen = 0;
    dfs(edges[node], edges, visited, inStack, &nextCount, &nextCycleLen, 
        result, curStep + 1);
    
    // 从环中出来后更新结果
    if (nextCycleLen > 0) {
        result[node] = nextCycleLen;
        if (curStep + nextCount - visited[node] >= nextCycleLen) {
            *cycleLen = nextCycleLen;
        }
    } else {
        result[node] = nextCount + 1;
    }
    
    *count = result[node];
    inStack[node] = 0;
}

int* countVisitedNodes(int* edges, int edgesSize, int* returnSize) {
    // 分配结果数组
    int* result = (int*)calloc(edgesSize, sizeof(int));
    *returnSize = edgesSize;
    
    // 访问标记数组
    int* visited = (int*)calloc(edgesSize, sizeof(int));
    // 当前路径中的节点标记
    int* inStack = (int*)calloc(edgesSize, sizeof(int));
    
    // 对每个未访问的节点进行DFS
    for (int i = 0; i < edgesSize; i++) {
        if (!visited[i]) {
            int count = 0, cycleLen = 0;
            dfs(i, edges, visited, inStack, &count, &cycleLen, result, 1);
        }
    }
    
    // 释放内存
    free(visited);
    free(inStack);
    
    return result;
}
