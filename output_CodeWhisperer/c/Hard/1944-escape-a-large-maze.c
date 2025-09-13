/**https://leetcode.com/problems/escape-a-large-maze/ */
//There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
//Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
//Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.
// 
//Example 1:
//Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
//Output: false
//Explanation: The target square is inaccessible starting from the source square because we cannot move.
//We cannot move north or east because those squares are blocked.
//We cannot move south or west because we cannot go outside of the grid.
//Example 2:
//Input: blocked = [], source = [0,0], target = [999999,999999]
//Output: true
//Explanation: Because there are no blocked cells, it is possible to reach the target square.
// 
//Constraints:
//	0 <= blocked.length <= 200
//	blocked[i].length == 2
//	0 <= xi, yi < 106
//	source.length == target.length == 2
//	0 <= sx, sy, tx, ty < 106
//	source != target
//	It is guaranteed that source and target are not blocked.
bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize) {
    int blockedCount = blockedSize;
    int* blockedSet = (int*)malloc(sizeof(int) * 1000000 * 1000000);

    memset(blockedSet, 0, sizeof(int) * 1000000 * 1000000);
    for (int i = 0; i < blockedSize; i++) {
        blockedSet[blocked[i][0] * 1000000 + blocked[i][1]] = 1;
    }
    int* visited = (int*)malloc(sizeof(int) * 1000000 * 1000000);
    int* queue = (int*)malloc(sizeof(int) * 1000000 * 1000000);

    int queueSize = 1;

    queue[0] = source[0] * 1000000 + source[1];

    visited[source[0] * 1000000 + source[1]] = 1;

    int* directions = (int*)malloc(sizeof(int) * 4);

    directions[0] = -1;

    directions[1] = 1;

    directions[2] = 0;

    directions[3] = 0;





    while (queueSize > 0) {
        int* current = (int*)malloc(sizeof(int) * 2);

        current[0] = queue[0] / 1000000;

        current[1] = queue[0] % 1000000;

        queue++;

        queueSize--;

        for (int i = 0; i < 4; i++) {
            int* next = (int*)malloc(sizeof(int) * 2);

            next[0] = current[0] + directions[i];

            next[1] = current[1] + directions[i + 1];

            if (next[0] < 0 || next[0] >= 1000000 || next[1] < 0 || next[1] >= 1000000) {
                continue;
            }

            if (next[0] == target[0] && next[1] == target[1]) {
                return true;
            }

            if (blockedSet[next[0] * 1000000 + next[1]] == 1) {
                blockedCount--;
            }

            if (blockedCount < 200 && visited[next[0] * 1000000 + next[1]] == 0) {
                queue[queueSize] = next[0] * 1000000 + next[1];

                queueSize++;

                visited[next[0] * 1000000 + next[1]] = 1;
            }
        }
    }


    return false;
}