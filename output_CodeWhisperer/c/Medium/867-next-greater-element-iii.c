/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
int nextGreaterElement(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int len = strlen(s);
    int i = len - 1;
    while (i > 0 && s[i] <= s[i - 1]) {
        i--;
    }
    if (i == 0) {
        return -1;
    }
    int j = len - 1;
    while (s[j] <= s[i - 1]) {
        j--;
    }
    char temp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = temp;
    j = len - 1;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    long long res = atoll(s);
    return res > INT_MAX ? -1 : (int)res;
}