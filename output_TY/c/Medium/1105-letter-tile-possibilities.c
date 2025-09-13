/**https://leetcode.com/problems/letter-tile-possibilities/ */
//You have n  tiles, where each tile has one letter tiles[i] printed on it.
//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
// 
//Example 1:
//Input: tiles = "AAB"
//Output: 8
//Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
//Example 2:
//Input: tiles = "AAABBC"
//Output: 188
//Example 3:
//Input: tiles = "V"
//Output: 1
// 
//Constraints:
//	1 <= tiles.length <= 7
//	tiles consists of uppercase English letters.
int numTilePossibilities(char * tiles){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[26]={0};
    for(i=0;i<strlen(tiles);i++){
        a[tiles[i]-'A']++;
    }
    int sum=0;
    for(i=0;i<26;i++){
        if(a[i]==0) continue;
        sum+=a[i];
        for(j=i+1;j<26;j++){
            if(a[j]==0) continue;
            sum+=a[i]*a[j];
            for(k=j+1;k<26;k++){
                if(a[k]==0) continue;
                sum+=a[i]*a[j]*a[k];
            }
        }
    }
    return sum+1;
}