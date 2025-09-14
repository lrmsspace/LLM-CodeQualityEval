/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
char * reformat(char * s){
    int i,j,k,l,m,n,o,p,q,r,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17,s18,s19,s20,s21,s22,s23,s24,s25,s26,s27,s28,s29,s30,s31,s32,s33,
    s34,s35,s36,s37,s38,s39,s40,s41,s42,s43,s44,s45,s46,s47,s48,s49,s50,s51,s52,s53,s54,s55,s56,s57,s58,s59,s60,s61,s62,s63,s64,s65,s66,s67,s68,s69,s70,
         *a10, *a11, *a12, *a13, *a14, *a15, *a16, *a17, *a18, *a19,
         *a20, *a21, *a22, *a23, *a24, *a25, *a26, *a27, *a28, *a29,
         *a30, *a31,
         *a32, *a33, *a34, *a35, *a36, *a37, *a38, *a39, *a40, *a41, *a42, *a43, *a44, *a45, *a46, *a47, *a48, *a49, *a50, *a51, *a52, *a53, *a54, *a55, *a56, *a57,*a58, *a59, *a60, *a61, *a62, *a63, *a64, *a65, *a66, *a67, *a68, *a69, *a70;
         a10=malloc(sizeof(char)*100000);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s1++;
        }
        else
        {
            s2++;
        }
    }

    if(s1==s2||abs(s1-s2)>1)
    {
        return "";
    }
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            a10[s3]=s[i];
            s3++;
        }
        else
        {
            a10[s4]=s[i];
            s4++;
        }
    }
    for(i=0;i<s3;i++)
    {
        for(j=0;j<s4;j++)
        {
            if(abs(a10[i]-a10[j])>32)
            {
                return "";
            }
        }
    }
        a11=malloc(sizeof(char)*100000);
        for(i=0;i<s3;i++)
    {
        a11[i]=a10[i];
    }
    for(i=0;i<s4;i++)
    {
        a11[s3+i]=a10[s4+i];
    }
    return a11;
}