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
// 
//Constraints:
//	1 <= routes.length <= 500.
//	1 <= routes[i].length <= 105
//	All the values of routes[i] are unique.
//	sum(routes[i].length) <= 105
//	0 <= routes[i][j] < 106
//	0 <= source, target < 106
int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int source, int target) {
        if (source == target) return 0;

        // Map to store which buses stop at each bus stop
        int stopToBuses[1000000] = {0};
        for (int i = 0; i < routesSize; i++) {
            for (int j = 0; j < routesColSize[i]; j++) {
                stopToBuses[routes[i][j]] |= (1 << i);
            }
        }

        // BFS setup
        int visitedBuses[500] = {0};    
        int visitedStops[1000000] = {0};
        int queue[1000000];
        int front = 0, rear = 0;

        queue[rear++] = source;
        visitedStops[source] = 1;
        int busesTaken = 0;

        while (front < rear) {
            int size = rear - front;
            busesTaken++;

            for (int i = 0; i < size; i++) {
                int stop = queue[front++];
                int buses = stopToBuses[stop];

                for (int bus = 0; bus < routesSize; bus++) {
                    if ((buses & (1 << bus)) && !visitedBuses[bus]) {
                        visitedBuses[bus] = 1;

                        for (int j = 0; j < routesColSize[bus]; j++) {
                            int nextStop = routes[bus][j];
                            if (nextStop == target) return busesTaken;
                            if (!visitedStops[nextStop]) {
                                visitedStops[nextStop] = 1;
                                queue[rear++] = nextStop;
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
}