/**https://leetcode.com/problems/second-minimum-time-to-reach-destination/ */
//A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
//Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
//The second minimum value is defined as the smallest value strictly larger than the minimum value.
//	For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
//Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.
//Notes:
//	You can go through any vertex any number of times, including 1 and n.
//	You can assume that when the journey starts, all signals have just turned green.
// 
//Example 1:
//        
//Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
//Output: 13
//Explanation:
//The figure on the left shows the given graph.
//The blue path in the figure on the right is the minimum time path.
//The time taken is:
//- Start at 1, time elapsed=0
//- 1 -> 4: 3 minutes, time elapsed=3
//- 4 -> 5: 3 minutes, time elapsed=6
//Hence the minimum time needed is 6 minutes.
//The red path shows the path to get the second minimum time.
//- Start at 1, time elapsed=0
//- 1 -> 3: 3 minutes, time elapsed=3
//- 3 -> 4: 3 minutes, time elapsed=6
//- Wait at 4 for 4 minutes, time elapsed=10
//- 4 -> 5: 3 minutes, time elapsed=13
//Hence the second minimum time is 13 minutes.      
//Example 2:
//Input: n = 2, edges = [[1,2]], time = 3, change = 2
//Output: 11
//Explanation:
//The minimum time path is 1 -> 2 with time = 3 minutes.
//The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
// 
//Constraints:
//	2 <= n <= 104
//	n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
//	edges[i].length == 2
//	1 <= ui, vi <= n
//	ui != vi
//	There are no duplicate edges.
//	Each vertex can be reached directly or indirectly from every other vertex.
//	1 <= time, change <= 103
int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change){
    int i, j, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31,n32, n33, n34, n35, n36, n  = 0;
    int *a = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        a[i] = 0;
    }
    for(i = 0; i < edgesSize; i++){
        n1 = edges[i][0];
        n2 = edges[i][1];
        a[n1]++;
        a[n2]++;
    }
    for(i = 0; i < n; i++){
        if(a[i] == 1){
            n++;
        }
    }
    if(n == 0){
        return 0;
    }
    int *b = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        b[i] = 0;
    }
    for(i = 0; i < edgesSize; i++){
        n1 = edges[i][0];
    }
    for(i = 0; i < edgesSize; i++){
        n1 = edges[i][0];
        n2 = edges[i][1];
        if(a[n1] == 1){
            b[n1]++;
        }
        if(a[n2] == 1){
            b[n2]++;
        }
    }
    for(i = 0; i < n; i++){
        if(b[i] == 0){
            n1 = i;
            break;
        }
    }
    for(i = 0; i < edgesSize; i++){
        n1 = edges[i][0];
        n2 = edges[i][1];
        if(n1 == n2){
            edges[i][0] = 0;
            edges[i][1] = 0;
        }
    }
    for(i = 0; i < edgesSize; i++){
        if(edges[i][0] == n1){
            n2 = edges[i][1];
            break;
        }
        if(edges[i][1] == n1){
            n2 = edges[i][0];
            break;
        }
    }
    for(i = 0; i < edgesSize; i++){
        if(edges[i][0] == n2){
            n3 = edges[i][1];
            break;
        }
        if(edges[i][1] == n2){
            n3 = edges[i][0];
            break;
        }
        for(i = 0; i < edgesSize; i++){
            if(edges[i][0] == n3){
                n4 = edges[i][1];
                break;
            }
            if(edges[i][1] == n3){
                n4 = edges[i][0];
                break;
            }
        }
        for(i = 0; i < edgesSize; i++){
            if(edges[i][0] == n4){
                n5 = edges[i][1];
                break;
            }
            if(edges[i][1] == n4){
                n5 = edges[i][0];
                break;
            }
        }

    }
    return 0;

}
