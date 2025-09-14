/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.
// 
//Example 1:
//Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
//Output: [[0,1],[2,3,4,5]]
//Explanation: The figure above describes the graph.
//The following figure shows all the possible MSTs:
//Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
//The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
//Example 2:
//Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
//Output: [[],[0,1,2,3]]
//Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
// 
//Constraints:
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= ai < bi < n
//	1 <= weighti <= 1000
//	All pairs (ai, bi) are distinct.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findCriticalAndPseudoCriticalEdges(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes){   
    int i,j,k,l,m,n1,n2,w,p,q,r,s,t,u,v,x,y,z,a,b,c,d,e,f,g,h,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,A,B,C,D,E,F,G,H;
    int* p1=malloc(n*sizeof(int));
    i
    for(i=0;i<n;i++) p1[i]=i;
    for(i=0;i<edgesSize;i++)
    {
        for(j=0;j<edgesSize-i-1;j++)
        {
            if(edges[j][2]>edges[j+1][2])
            {
                w=edges[j][2];
                edges[j][2]=edges[j+1][2];
                edges[j+1][2]=w;
            }
        }
    }
    for(i=0;i<edgesSize;i++)
    {
        for(j=0;j<n;j++)
        {
            p1[j]=j;
        }
        for(j=0;j<edgesSize;j++)
        {
            if(i!=j)
            {
                n1=edges[j][0];
                n2=edges[j][1];
                w=edges[j][2];
            }
        }
    }
    for(i=0;i<edgesSize;i++)
    {
        for(j=0;j<n;j++)
        {
            p1[j]=j;
        }
        for(j=0;j<edgesSize;j++)
        {
            if(i==j)
            {
                n1=edges[j][0];
                n2=edges[j][1];
                w=edges[j][2];
            }
        }
    }
    for(i=0;i<edgesSize;i++)
    {
        for(j=0;j<n;j++)
        {
            p1[j]=j;
        }
        for(j=0;j<edgesSize;j++)
        {
            if(i!=j)
            {
                n1=edges[j][0];
                n2=edges[j][1];
                w=edges[j][2];
            }
        }
    }
    for(i=0;i<edgesSize;i++)
    {
        for(j=0;j<n;j++)
        {
            p1[j]=j;
        }
        for(j=0;j<edgesSize;j++)
        {
            if(i==j)
            {
                n1=edges[j][0];
                n2=edges[j][1];
                w=edges[j][2];
            }
        }
    }
}