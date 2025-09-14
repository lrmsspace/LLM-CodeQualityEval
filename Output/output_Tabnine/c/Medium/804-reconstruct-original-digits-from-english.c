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
    int freq[10] = {0};
    char* result = (char*)malloc(sizeof(char) * 10);
    int result_index = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }
    
    freq['e' - 'a'] = count['o' - 'a'] + count['n' - 'a'];
    freq['o' - 'a'] = count['o' - 'a'] - freq['e' - 'a'] - freq['i' - 'a'];
    freq['i' - 'a'] = count['i' - 'a'] - freq['e' - 'a'];
    
    freq['f' - 'a'] = count['f' - 'a'] - freq['t' - 'a'];
    freq['t' - 'a'] = count['t' - 'a'] - freq['f' - 'a'] - freq['s' - 'a'];
    freq['s' - 'a'] = count['s' - 'a'];
    
    freq['g' - 'a'] = count['g' - 'a'] - freq['e' - 'a'] - freq['i' - 'a'];
    freq['e' - 'a'] = freq['e' - 'a'] - freq['g' - 'a'];
    freq['i' - 'a'] = freq['i' - 'a'] - freq['g' - 'a'];
    
    freq['h' - 'a'] = count['h' - 'a'] - freq['t' - 'a'];
    freq['t' - 'a'] = freq['t' - 'a'] - freq['h' - 'a'];
    
    freq['u' - 'a'] = count['u' - 'a'] - freq['f' - 'a'];
    freq['f' - 'a'] = freq['f' - 'a'] - freq['u' - 'a'];
    
    freq['v' - 'a'] = count['v' - 'a'] - freq['s' - 'a'];
    freq['s' - 'a'] = freq['s' - 'a'] - freq['v' - 'a'];
    
    freq['w' - 'a'] = count['w' - 'a'] - freq['t' - 'a'];
    freq['t' - 'a'] = freq['t' - 'a'] - freq['w' - 'a'];
    
    freq['x' - 'a'] = count['x' - 'a'] - freq['s' - 'a'];
    freq['s' - 'a'] = freq['s' - 'a'] - freq['x' - 'a'];
    
    freq['z' - 'a'] = count['z' - 'a'] - freq['e' - 'a'] - freq['r' - 'a'];
    freq['e' - 'a'] = freq['e' - 'a'] - freq['z' - 'a'];
    freq['r' - 'a'] = freq['r' - 'a'] - freq['z' - 'a'];
    
    for (int i = 0; i < 10; i++) {
        while (freq[i] > 0) {
            result[result_index++] = i + '0';
            freq[i]--;
        }
    }
    
    result[result_index] = '\0';
    return result;
    
}