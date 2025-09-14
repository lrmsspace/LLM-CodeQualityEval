/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
int findMinDifference(char** timePoints, int timePointsSize) {
    int* time = (int*)malloc(sizeof(int) * timePointsSize);
    for (int i = 0; i < timePointsSize; i++) {
        time[i] = atoi(timePoints[i]) * 60 + atoi(timePoints[i] + 3);
    }
    int min = 1440;
    for (int i = 0; i < timePointsSize; i++) {
        for (int j = i + 1; j < timePointsSize; j++) {
            int diff = time[j] - time[i];
            if (diff > 720) {
                diff = 1440 - diff;
            }
            if (diff < min) {
                min = diff;
            }
        }
    }
    free(time);
    return min;
}