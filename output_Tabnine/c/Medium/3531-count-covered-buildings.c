/*
 You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
 A building is covered if there is at least one building in all four directions: left, right, above, and below.
 Return the number of covered buildings.
 Example 1:
 Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
 Output: 1
 Explanation:
 Only building [2,2] is covered as it has at least one building:
 above ([1,2])
 below ([3,2])
 left ([2,1])
 right ([2,3])
 Thus, the count of covered buildings is 1.
 Example 2:
 Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
 Output: 0
 Explanation:
 No building has at least one building in all four directions.
 Example 3:
 Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
 Output: 1
 Explanation:
 Only building [3,3] is covered as it has at least one building:
 above ([1,3])
 below ([5,3])
 left ([3,2])
 right ([3,5])
 Thus, the count of covered buildings is 1.
 Constraints:
 2 <= n <= 105
 1 <= buildings.length <= 105 
 buildings[i] = [x, y]
 1 <= x, y <= n
 All coordinates of buildings are unique.
*/

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    int* top = (int*)malloc(sizeof(int) * n);
    int* bottom = (int*)malloc(sizeof(int) * n);
    
    memset(left, 0, sizeof(int) * n);
    memset(right, n - 1, sizeof(int) * n);
    memset(top, 0, sizeof(int) * n);    

    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        left[x] = max(left[x], y);

        right[x] = min(right[x], n - y - 1);
        top[y] = max(top[y], x);
        bottom[y] = min(bottom[y], n - x - 1);
    }
    int covered = 0;
    for (int i = 0; i < n; i++) {
        for (int j = left[i]; j <= right[i]; j++) {
            if (top[j] <= i && i <= bottom[j]) {
                covered++;
                break;
            }
        }
    }
    free(left);
    free(right);
    free(top);
    free(bottom);
    return covered;
    
}