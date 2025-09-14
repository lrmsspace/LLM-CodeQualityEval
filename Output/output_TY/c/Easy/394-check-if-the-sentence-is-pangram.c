/**https://leetcode.com/problems/check-if-the-sentence-is-pangram/ */
//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
// 
//Example 1:
//Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
//Output: true
//Explanation: sentence contains at least one of every letter of the English alphabet.
//Example 2:
//Input: sentence = "leetcode"
//Output: false
// 
//Constraints:
//	1 <= sentence.length <= 1000
//	sentence consists of lowercase English letters.
bool checkIfPangram(char * sentence){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    i=j=k=l=m=n=o=p=q=r=s=t=u=v=w=x=y=z=0;
    while(*sentence){
        switch(*sentence){
            case 'a':
                i++;
        }
    }
    return (i==1);
}