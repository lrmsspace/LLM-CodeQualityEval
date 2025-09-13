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
char * originalDigits(char * s){
    int freq[26]={0};
    for(int i=0;s[i];i++)
        freq[s[i]-'a']++;
    int ans[10]={0};
    ans[0]=freq['z'-'a'];
    ans[2]=freq['w'-'a'];
    ans[4]=freq['u'-'a'];
    ans[6]=freq['x'-'a'];
    ans[8]=freq['g'-'a'];
    ans[7]=freq['s'-'a']-ans[6];
    ans[3]=freq['h'-'a']-ans[8];
    ans[5]=freq['f'-'a']-ans[4];
    ans[1]=freq['o'-'a']-ans[2]-ans[4]-ans[0];
    ans[9]=freq['n'-'a']-ans[5]-ans[6]-ans[1];
    char *res=(char*)malloc(11*sizeof(char));
    for(int i=0;i<10;i++)
        for(int j=0;j<ans[i];j++)
            res[i*2+j]=(char)(i+'0');
    res[20]='\0';
    return res;
}