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
    int count[10] = {0};
    for (int i = 0; s[i]; i++) {
        switch (s[i]) {
            case 'z': count[0]++; break;
            case 'w': count[2]++; break;
            case 'u': count[4]++; break;
            case 'x': count[6]++; break;
            case 'g': count[8]++; break;
            case 'o': count[1]++; break;
            case 'h': count[3]++; break;
            case 'f': count[5]++; break;
            case 's': count[7]++; break;
            case 'i': count[9]++; break;
        }
    }
    
    char* res = (char*)malloc(1024);
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        while (count[i]--) {
            res[idx++] = '0' + i;
        }
    }
    res[idx] = '\0';
    
    return res;
}