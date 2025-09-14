/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//	i + 1 where: i + 1 < arr.length.
//	i - 1 where: i - 1 >= 0.
//	j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	-108 <= arr[i] <= 108
int minJumps(int* arr, int arrSize) {
    
    int* visited = (int*)malloc(sizeof(int) * arrSize);
    memset(visited, 0, sizeof(int) * arrSize);
    int* queue = (int*)malloc(sizeof(int) * arrSize);
    int front = 0, rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    int steps = 0;
    while (front < rear) {
        int size = rear - front;
        while (size-- > 0) {
            int i = queue[front++];
            if (i == arrSize - 1) {
                free(visited);
                free(queue);
                return steps;
            }
            if (i + 1 < arrSize && !visited[i + 1]) {
                queue[rear++] = i + 1;
                visited[i + 1] = 1;
            }
            if (i - 1 >= 0 && !visited[i - 1]) {
                queue[rear++] = i - 1;
                visited[i - 1] = 1;
            }
            for (int j = i + 1; j < arrSize; j++) {
                if (arr[j] == arr[i]) {
                    if (j == arrSize - 1) {
                        free(visited);
                        free(queue);
                        return steps + 1;
                    }
                    if (!visited[j]) {
                        queue[rear++] = j;
                        visited[j] = 1;
                    }
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] == arr[i]) {
                    if (j == arrSize - 1) {
                        free(visited);
                        free(queue);
                        return steps + 1;
                    }
                    if (!visited[j]) {
                        queue[rear++] = j;
                        visited[j] = 1;
                    }
                }
            }
        }
        steps++;
    }
    free(visited);
    free(queue);
    return -1;
}