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
    int convertToMinutes(char* time) {
        int hours = (time[0] - '0') * 10 + (time[1] - '0');
        int minutes = (time[3] - '0') * 10 + (time[4] - '0');
        return hours * 60 + minutes;
    }

    int minDifference = 1440; // Maximum minutes in a day
    int* minutesArray = malloc(timePointsSize * sizeof(int));

    for (int i = 0; i < timePointsSize; i++) {
        minutesArray[i] = convertToMinutes(timePoints[i]);
    }

    qsort(minutesArray, timePointsSize, sizeof(int), cmpfunc);

    for (int i = 1; i < timePointsSize; i++) {
        int diff = minutesArray[i] - minutesArray[i - 1];
        if (diff < minDifference) {
            minDifference = diff;
        }
    }

    int overnightDiff = 1440 + minutesArray[0] - minutesArray[timePointsSize - 1];
    if (overnightDiff < minDifference) {
        minDifference = overnightDiff;
    }

    free(minutesArray);
    return minDifference;
}
