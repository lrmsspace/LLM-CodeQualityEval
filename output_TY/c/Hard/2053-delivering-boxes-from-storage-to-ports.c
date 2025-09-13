/**https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/ */
//You have the task of delivering some boxes from storage to their ports using only one ship. However, this ship has a limit on the number of boxes and the total weight that it can carry.
//You are given an array boxes, where boxes[i] = [ports​​i​, weighti], and three integers portsCount, maxBoxes, and maxWeight.
//	ports​​i is the port where you need to deliver the ith box and weightsi is the weight of the ith box.
//	portsCount is the number of ports.
//	maxBoxes and maxWeight are the respective box and weight limits of the ship.
//The boxes need to be delivered in the order they are given. The ship will follow these steps:
//	The ship will take some number of boxes from the boxes queue, not violating the maxBoxes and maxWeight constraints.
//	For each loaded box in order, the ship will make a trip to the port the box needs to be delivered to and deliver it. If the ship is already at the correct port, no trip is needed, and the box can immediately be delivered.
//	The ship then makes a return trip to storage to take more boxes from the queue.
//The ship must end at storage after all the boxes have been delivered.
//Return the minimum number of trips the ship needs to make to deliver all boxes to their respective ports.
// 
//Example 1:
//Input: boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight = 3
//Output: 4
//Explanation: The optimal strategy is as follows: 
//- The ship takes all the boxes in the queue, goes to port 1, then port 2, then port 1 again, then returns to storage. 4 trips.
//So the total number of trips is 4.
//Note that the first and third boxes cannot be delivered together because the boxes need to be delivered in order (i.e. the second box needs to be delivered at port 2 before the third box).
//Example 2:
//Input: boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes = 3, maxWeight = 6
//Output: 6
//Explanation: The optimal strategy is as follows: 
//- The ship takes the first box, goes to port 1, then returns to storage. 2 trips.
//- The ship takes the second, third and fourth boxes, goes to port 3, then returns to storage. 2 trips.
//- The ship takes the fifth box, goes to port 2, then returns to storage. 2 trips.
//So the total number of trips is 2 + 2 + 2 = 6.
//Example 3:
//Input: boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, maxBoxes = 6, maxWeight = 7
//Output: 6
//Explanation: The optimal strategy is as follows:
//- The ship takes the first and second boxes, goes to port 1, then returns to storage. 2 trips.
//- The ship takes the third and fourth boxes, goes to port 2, then returns to storage. 2 trips.
//- The ship takes the fifth and sixth boxes, goes to port 3, then returns to storage. 2 trips.
//So the total number of trips is 2 + 2 + 2 = 6.
// 
//Constraints:
//	1 <= boxes.length <= 105
//	1 <= portsCount, maxBoxes, maxWeight <= 105
//	1 <= ports​​i <= portsCount
//	1 <= weightsi <= maxWeight
int boxDelivering(int** boxes, int boxesSize, int* boxesColSize, int portsCount, int maxBoxes, int maxWeight){
    int *dp = malloc(sizeof(int) * (boxesSize + 1));
    int *weight = malloc(sizeof(int) * (boxesSize + 1));
    int *count = malloc(sizeof(int) * (boxesSize + 1));
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    dp[0] = 0;
    weight[0] = 0;
    count[0] = 0;
    for (i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0; i < boxesSize; i++) {
        dp[i + 1] = dp[i] + 2 + (
            weight[i] > maxWeight ? 1 : 0
        );
        weight[i + 1] = weight[i] + boxes[i][1];
        count[i + 1] = count[i] + (
            boxes[i][0] != boxes[i - 1][0] ? 1 : 0
        );
        if (i == 0 || boxes[i][0] != boxes[i - 1][0]) {
            dp[i + 1] = dp[i + 1] - 1;
        }
        if (i >= maxBoxes - 1) {
            dp[i + 1] = dp[i + 1] - (
                count[i + 1] - count[i + 1 - maxBoxes] > 1 ? 2 : 0
            );
            dp[i + 1] = dp[i + 1] + (
                weight[i + 1] - weight[i + 1 - maxBoxes] > maxWeight ? 1 : 0
            );  
        }
    }
    return dp[boxesSize];
}
