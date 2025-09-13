/**https://leetcode.com/problems/min-cost-to-connect-all-points/ */
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
// 
//Example 1:
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation: 
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
// 
//Constraints:
//	1 <= points.length <= 1000
//	-106 <= xi, yi <= 106
//	All pairs (xi, yi) are distinct.
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int i,j,k;
    int *parent = (int*)malloc(sizeof(int)*pointsSize);
    int *rank = (int*)malloc(sizeof(int)*pointsSize);
    int **edges = (int**)malloc(sizeof(int*)*pointsSize*pointsSize);
    int *edgesColSize = (int*)malloc(sizeof(int)*pointsSize*pointsSize);
    int *edgesSize = (int*)malloc(sizeof(int)*pointsSize);
    for(i=0;i<pointsSize;i++){
        parent[i] = i;
        rank[i] = 0;
        edges[i] = (int*)malloc(sizeof(int)*pointsSize);
        edgesColSize[i] = pointsSize;
        edgesSize[i] = 0;
    }
    for(i=0;i<pointsSize;i++){
        for(j=i+1;j<pointsSize;j++){
            edges[i][edgesSize[i]] = j;
            edges[j][edgesSize[j]] = i;
            edgesSize[i]++;
            edgesSize[j]++;
        }
    }
    int *dist = (int*)malloc(sizeof(int)*pointsSize);
    int *visited = (int*)malloc(sizeof(int)*pointsSize);
    for(i=0;i<pointsSize;i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[0] = 0;
    int minDist,minIndex;
    for(i=0;i<pointsSize;i++){
        minDist = INT_MAX;
        for(j=0;j<pointsSize;j++){
            if(visited[j]==0 && dist[j]<minDist){
                minDist = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for(j=0;j<edgesSize[minIndex];j++){
            k = edges[minIndex][j];
            if(visited[k]==0 && (abs(points[minIndex][0]-points[k][0])+abs(points[minIndex][1]-points[k][1]))<dist[k]){
                dist[k] = abs(points[minIndex][0]-points[k][0])+abs(points[minIndex][1]-points[k][1]);
            }
        }
    }
    int res = 0;
    for(i=0;i<pointsSize;i++){
        res += dist[i];
    }
    return res;    
}