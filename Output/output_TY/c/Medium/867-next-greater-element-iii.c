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
int nextGreaterElement(int n){
    char *s = malloc(sizeof(char) * 32);
    sprintf(s, "%d", n);
    int i = strlen(s) - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i == -1)
        return -1;
    int j = strlen(s) - 1;
    while (j > i&& s[j] <= s[i])
        j--;
        swap(&s[i], &s[j]);
    return atoi(s);    
}