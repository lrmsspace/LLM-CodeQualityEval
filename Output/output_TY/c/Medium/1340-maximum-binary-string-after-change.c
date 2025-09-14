/**https://leetcode.com/problems/maximum-binary-string-after-change/ */
//You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:
//	Operation 1: If the number contains the substring "00", you can replace it with "10".
//	
//		For example, "00010" -> "10010"
//	
//	
//	Operation 2: If the number contains the substring "10", you can replace it with "01".
//	
//		For example, "00010" -> "00001"
//	
//	
//Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.
// 
//Example 1:
//Input: binary = "000110"
//Output: "111011"
//Explanation: A valid transformation sequence can be:
//"000110" -> "000101" 
//"000101" -> "100101" 
//"100101" -> "110101" 
//"110101" -> "110011" 
//"110011" -> "111011"
//Example 2:
//Input: binary = "01"
//Output: "01"
//Explanation: "01" cannot be transformed any further.
// 
//Constraints:
//	1 <= binary.length <= 105
//	binary consist of '0' and '1'.
char * maximumBinaryString(char * binary){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
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
    while(binary[i]!='\0'){
        if(binary[i]=='0'){
            j++;
        }
        i++;
    }
    if(j==0){
        return binary;
    }
    if(j==1){
        binary[i-1]='1';
        return binary;
    }
    for(i=0;i<j-1;i++){
        binary[i]='1';
    }
    binary[i]='0';
    return binary;
}