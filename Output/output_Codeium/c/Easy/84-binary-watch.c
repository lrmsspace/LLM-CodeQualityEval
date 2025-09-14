/**https://leetcode.com/problems/binary-watch/ */
//A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
//	For example, the below binary watch reads "4:51".
//Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
//The hour must not contain a leading zero.
//	For example, "01:00" is not valid. It should be "1:00".
//The minute must consist of two digits and may contain a leading zero.
//	For example, "10:2" is not valid. It should be "10:02".
// 
//Example 1:
//Input: turnedOn = 1
//Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
//Example 2:
//Input: turnedOn = 9
//Output: []
// 
//Constraints:
//	0 <= turnedOn <= 10
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    int hourBits[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int minuteBits[60] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328};
    int* hours = (int*)malloc((1 << 4) * sizeof(int));
    int* minutes = (int*)malloc((1 << 6) * sizeof(int));
    int hourCount = 0;
    int minuteCount = 0;
    for (int i = 0; i < 12; i++) {
        if (turnedOn >= __builtin_popcount(hourBits[i])) {
            hours[hourCount++] = i;
        }
    }
    for (int i = 0; i < 60; i++) {
        if (turnedOn >= __builtin_popcount(minuteBits[i])) {
            minutes[minuteCount++] = i;
        }
    }
    char** result = (char**)malloc(hourCount * minuteCount * sizeof(char*));
    int resultIndex = 0;
    for (int i = 0; i < hourCount; i++) {
        for (int j = 0; j < minuteCount; j++) {
            result[resultIndex] = (char*)malloc(6 * sizeof(char));
            sprintf(result[resultIndex++], "%d:%02d", hours[i], minutes[j]);
        }
    }
    free(hours);
    free(minutes);
    *returnSize = resultIndex;
    return result;
}