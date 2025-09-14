/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//	For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
// 
//Example 1:
//Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
//Output: 2
//Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
//Example 2:
//Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
//Output: -1
// 
//Constraints:
//	1 <= routes.length <= 500.
//	1 <= routes[i].length <= 105
//	All the values of routes[i] are unique.
//	sum(routes[i].length) <= 105
//	0 <= routes[i][j] < 106
//	0 <= source, target < 106
int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target){
    int i,j,k;
    if(source==target){
        return 0;
    }
    int *visit=(int *)malloc(sizeof(int)*routesSize);
    memset(visit,0,sizeof(int)*routesSize);
    for(i=0;i<routesSize;i++){
        for(j=0;j<routesColSize[i];j++){
            if(routes[i][j]==source){
                visit[i]=1;
                break;
            }
        }
    }
    for(i=0;i<routesSize;i++){
        if(visit[i]==1){
            for(j=0;j<routesColSize[i];j++){
                if(routes[i][j]==target){
                    return 1;
                }
            }
        }
    }
    return 0;
}