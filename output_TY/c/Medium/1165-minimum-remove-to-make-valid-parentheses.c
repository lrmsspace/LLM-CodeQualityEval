/**https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/ */
//Given a string s of '(' , ')' and lowercase English characters.
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
//Formally, a parentheses string is valid if and only if:
//	It is the empty string, contains only lowercase characters, or
//	It can be written as AB (A concatenated with B), where A and B are valid strings, or
//	It can be written as (A), where A is a valid string.
// 
//Example 1:
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
//Example 2:
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
//Example 3:
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either'(' , ')', or lowercase English letter.
char * minRemoveToMakeValid(char * s){
    int i,j,k,l,n,m,cnt,flag;
    n=strlen(s);
    cnt=0;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
        }else if(s[i]==')'){
            cnt--;
        }
    }
    flag=0;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            if(cnt==0){
                flag=1;
                break;
            }
            cnt--;
        }else if(s[i]==')'){
            cnt++;
        }
    }
    if(flag==0){
        return s;
    }
    for(i=n-1;i>=0;i--){
        if(s[i]==')'){
            if(cnt==0){
                s[i]='\0';
                break;
            }
            cnt--;
        }else if(s[i]=='('){
            cnt++;
        }
    }
    return s;
}