/**https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/ */
//LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.
//You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.
//Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".
//Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.
//Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.
// 
//Example 1:
//Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
//Output: ["daniel"]
//Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").
//Example 2:
//Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
//Output: ["bob"]
//Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").
// 
//Constraints:
//	1 <= keyName.length, keyTime.length <= 105
//	keyName.length == keyTime.length
//	keyTime[i] is in the format "HH:MM".
//	[keyName[i], keyTime[i]] is unique.
//	1 <= keyName[i].length <= 10
//	keyName[i] contains only lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** alertNames(char** keyName, int keyNameSize, char** keyTime, int keyTimeSize, int* returnSize) {
    *returnSize = 0;
    if (keyNameSize <= 0 || keyTimeSize <= 0) return NULL;
    
    // Create a map to store the key usage frequency for each worker
    int* frequencyMap = (int*)calloc(24 * 60, sizeof(int));
    for (int i = 0; i < keyNameSize; i++) {
        int hour = (keyTime[i][0] - '0') * 10 + keyTime[i][1] - '0';
        int minute = (keyTime[i][3] - '0') * 10 + keyTime[i][4] - '0';
        frequencyMap[hour * 60 + minute]++;
    }
    
    // Create a list to store the workers who received an alert
    char** alertWorkers = (char**)calloc(keyNameSize, sizeof(char*));
    int alertWorkersCount = 0;
    
    // Iterate through the frequency map to find workers who used the keycard three or more times
    for (int i = 0; i < 24 * 60; i++) {
        if (frequencyMap[i] >= 3) {
            int hour = i / 60;
            int minute = i % 60;
            char* alertTime = (char*)calloc(6, sizeof(char));
            sprintf(alertTime, "%02d:%02d", hour, minute);
            
            for (int j = 0; j < keyNameSize; j++) {
                int hour2 = (keyTime[j][0] - '0') * 10 + keyTime[j][1] - '0';
                int minute2 = (keyTime[j][3] - '0') * 10 + keyTime[j][4] - '0';
                if (hour2 == hour && minute2 == minute) {
                    alertWorkers[alertWorkersCount] = strdup(keyName[j]);
                    alertWorkersCount++;
                    break;
                }
            }
        }
    }
    
    // Sort the alert workers in ascending order alphabetically
    qsort(alertWorkers, alertWorkersCount, sizeof(char*), compareWorkerNames);
    
    *returnSize = alertWorkersCount;
    return alertWorkers;
    
}