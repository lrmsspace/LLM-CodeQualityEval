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
    int* visited = (int*)calloc(arrSize, sizeof(int));
    int* queue = (int*)calloc(arrSize, sizeof(int));
    int front = 0, rear = 0;
    visited[0] = 1;
    queue[rear++] = 0;
    int steps = 0;
    while (front < rear) {
        int curr = queue[front++];
        if (curr == arrSize - 1) {
            free(visited);
            free(queue);
            return steps;
        }
        for (int i = -1; i <= 1; ++i) {
            int next = curr + i;
            if (next >= 0 && next < arrSize &&!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
                if (i == 0) {
                    steps++;
                } else {
                    steps = 2;
                }
            }
        }
        for (int i = 0; i < arrSize; ++i) {
            if (arr[curr] == arr[i] &&!visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
                steps = 2;
            }
        }
    }
    free(visited);
    free(queue);
    return -1;
}