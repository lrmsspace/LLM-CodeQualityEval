/**https://leetcode.com/problems/rearrange-words-in-a-sentence/ */
//Given a sentence text (A sentence is a string of space-separated words) in the following format:
//	First letter is in upper case.
//	Each word in text are separated by a single space.
//Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
//Return the new text following the format shown above.
// 
//Example 1:
//Input: text = "Leetcode is cool"
//Output: "Is cool leetcode"
//Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
//Output is ordered by length and the new first word starts with capital letter.
//Example 2:
//Input: text = "Keep calm and code on"
//Output: "On and keep calm code"
//Explanation: Output is ordered as follows:
//"On" 2 letters.
//"and" 3 letters.
//"keep" 4 letters in case of tie order by position in original text.
//"calm" 4 letters.
//"code" 4 letters.
//Example 3:
//Input: text = "To be or not to be"
//Output: "To be or to be not"
// 
//Constraints:
//	text begins with a capital letter and then contains lowercase letters and single space between words.
//	1 <= text.length <= 10^5
char * arrangeWords(char * text){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[1000];
    char b[1000][1000];
    char c[1000];
    i=0;
    j=0;
    k=0;
    l=0;
    m=0;
    n=0;
    o=0;
    p=0;
    q=0;
    r=0;
    s=0;
    t=0;
    u=0;
    v=0;
    w=0;
    x=0;
    y=0;
    z=0;
    while(text[i]!='\0'){
        if(text[i]==' '){
            a[j]=i-k;
        }
        }
        j++;
        k=i+1;
        i++;
        while(text[i]!='\0'){
            b[j][l]=text[i];
            i++;
            l++;
        }
        a[j]=i-k;
        j++;
        l=0;
        k=0;
        while(j>0){
            for(i=0;i<j-1;i++){
                if(a[i]>a[i+1]){
                    a[i]=a[i]^a[i+1];
                    a[i+1]=a[i]^a[i+1];
                    a[i]=a[i]^a[i+1];
                    for(k=0;k<a[i+1];k++){
                        b[i][k]=b[i][k]^b[i+1][k];
                    }
                }
            }
        }
        for(i=0;i<j;i++){
            c[i]=b[i][0];
        }
    for(i=0;i<j;i++){
        b[i][0]=toupper(b[i][0]);
    }
    for(i=0;i<j;i++){
        for(k=0;k<a[i];k++){
            c[i+1]=c[i+1]^b[i][k];
        }
    }
    for(i=0;i<j;i++){
        for(k=0;k<a[i];k++){
            c[i+1+a[i]]=c[i+1+a[i]]^b[i][k];
        }
    }
    for(i=0;i<j+a[j]-1;i++){
        c[i+1]=c[i+1]^c[i];
    }
    return c;
}