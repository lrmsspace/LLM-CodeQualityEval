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
    if(num == 0) return "0";
    int n = abs(num);
    char *res = (char *)malloc(20);
    int i = 0;
    while(n) {
        res[i++] = n % 7 + '0';
        n /= 7;
    }
    if(num < 0) res[i++] = '-';
    res[i] = '\0';
    for(int j = 0; j < i / 2; j++) {
        char t = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = t;
    }
    return res;    
}