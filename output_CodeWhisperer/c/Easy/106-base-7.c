/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.
// 
//Example 1:
//Input: num = 100
//Output: "202"
//Example 2:
//Input: num = -7
//Output: "-10"
// 
//Constraints:
//	-107 <= num <= 107
char* convertToBase7(int num) {
    if (num == 0) {
        char* res = (char*)malloc(2 * sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }
    char* res = (char*)malloc(12 * sizeof(char));
    int i = 0;
    while (num > 0) {
        res[i++] = num % 7 + '0';
        num /= 7;
    }
    if (isNegative) {
        res[i++] = '-';
    }
    res[i] = '\0';
    int left = 0, right = i - 1;
    while (left < right) {
        char temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left++;
        right--;
    }
    return res;
    
}