/*
 You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.
 The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".
 An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.
 Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.
 Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.
 Return a list that contains the names of high-access employees with any order you want.
 Example 1:
 Input: access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
 Output: ["a"]
 Explanation: "a" has three access times in the one-hour period of [05:32, 06:31] which are 05:32, 05:49, and 06:21.
 But "b" does not have more than two access times at all.
 So the answer is ["a"].
 Example 2:
 Input: access_times = [["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
 Output: ["c","d"]
 Explanation: "c" has three access times in the one-hour period of [08:08, 09:07] which are 08:08, 08:09, and 08:29.
 "d" has also three access times in the one-hour period of [14:10, 15:09] which are 14:10, 14:44, and 15:08.
 However, "e" has just one access time, so it can not be in the answer and the final answer is ["c","d"].
 Example 3:
 Input: access_times = [["cd","1025"],["ab","1025"],["cd","1046"],["cd","1055"],["ab","1124"],["ab","1120"]]
 Output: ["ab","cd"]
 Explanation: "ab" has three access times in the one-hour period of [10:25, 11:24] which are 10:25, 11:20, and 11:24.
 "cd" has also three access times in the one-hour period of [10:25, 11:24] which are 10:25, 10:46, and 10:55.
 So the answer is ["ab","cd"].
 Constraints:
 1 <= access_times.length <= 100
 access_times[i].length == 2
 1 <= access_times[i][0].length <= 10
 access_times[i][0] consists only of English small letters.
 access_times[i][1].length == 4
 access_times[i][1] is in 24-hour time format.
 access_times[i][1] consists only of '0' to '9'.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findHighAccessEmployees(char*** access_times, int access_timesSize, int* access_timesColSize, int* returnSize) {
    *returnSize = 0;
    if (access_timesSize == 0) {
        return NULL;
    }
    
    // Create a map to store the access times of each employee
    int** accessTimesMap = (int**)malloc(access_timesSize * sizeof(int*));
    for (int i = 0; i < access_timesSize; i++) {
        accessTimesMap[i] = (int*)malloc(2 * sizeof(int));
        accessTimesMap[i][0] = i;
        accessTimesMap[i][1] = atoi(access_times[i][1]);
    }
    
    // Sort the access times by employee name and access time
    qsort(accessTimesMap, access_timesSize, sizeof(int*), compareAccessTimes);
    
    // Initialize the result array
    char** result = (char**)malloc(access_timesSize * sizeof(char*));
    
    // Initialize the count of high-access employees
    int count = 0;
    // Iterate through the sorted access times
    int prevEmployee = -1;
    int prevAccessTime = -1;
    for (int i = 0; i < access_timesSize; i++) {
        int employee = accessTimesMap[i][0];
        int accessTime = accessTimesMap[i][1];
        
        // Check if the current access time is within a one-hour period
        if (prevEmployee == employee && accessTime - prevAccessTime <= 60) {
            // Increment the count of high-access employees for the current employee
            count++;
        } else {
            // Update the count of high-access employees for the previous employee
            if (count >= 3) {
                result[(*returnSize)++] = access_times[prevEmployee][0];
            }
            count = 1;
        }
        
        prevEmployee = employee;
        prevAccessTime = accessTime;
    }
    
    // Update the count of high-access employees for the last employee
    if (count >= 3) {
        result[(*returnSize)++] = access_times[prevEmployee][0];
    }
    
    // Free the memory allocated for the access times map
    for (int i = 0; i < access_timesSize; i++) {
        free(accessTimesMap[i]);
    }
    free(accessTimesMap);
    
    return result;
    
}