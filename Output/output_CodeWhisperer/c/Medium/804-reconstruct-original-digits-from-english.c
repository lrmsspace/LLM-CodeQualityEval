/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
char* originalDigits(char* s) {
    int count[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }
    int num[10] = {0};
    num[0] = count['z' - 'a'];
    num[2] = count['w' - 'a'];
    num[4] = count['u' - 'a'];
    num[6] = count['x' - 'a'];
    num[8] = count['g' - 'a'];
    num[1] = count['o' - 'a'] - num[0] - num[2] - num[4];
    num[3] = count['h' - 'a'] - num[8];
    num[5] = count['f' - 'a'] - num[4];
    num[7] = count['s' - 'a'] - num[6];
    num[9] = count['i' - 'a'] - num[5] - num[6] - num[8];
    char* res = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num[i]; j++) {
            res[index++] = i + '0';
        }
    }
    res[index] = '\0';
    return res;
}