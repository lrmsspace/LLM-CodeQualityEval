/**https://leetcode.com/problems/sort-the-students-by-their-kth-score/ */
//There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
//You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
//Return the matrix after sorting it.
// 
//Example 1:
//Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
//Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
//Explanation: In the above diagram, S denotes the student, while E denotes the exam.
//- The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
//- The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
//- The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.
//Example 2:
//Input: score = [[3,4],[5,6]], k = 0
//Output: [[5,6],[3,4]]
//Explanation: In the above diagram, S denotes the student, while E denotes the exam.
//- The student with index 1 scored 5 in exam 0, which is the highest score, so they got first place.
//- The student with index 0 scored 3 in exam 0, which is the lowest score, so they got second place.
// 
//Constraints:
//	m == score.length
//	n == score[i].length
//	1 <= m, n <= 250
//	1 <= score[i][j] <= 105
//	score consists of distinct integers.
//	0 <= k < n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes){
    int i,j,temp,*p,*q,*r,*s,*t,*u,*v,*w,*x,*y,*z;
    p=malloc(sizeof(int)*scoreSize);
    q=malloc(sizeof(int)*scoreSize);
    r=malloc(sizeof(int)*scoreSize);
    s=malloc(sizeof(int)*scoreSize);
    t=malloc(sizeof(int)*scoreSize);
    u=malloc(sizeof(int)*scoreSize);
    v=malloc(sizeof(int)*scoreSize);
    w=malloc(sizeof(int)*scoreSize);
    x=malloc(sizeof(int)*scoreSize);
    y=malloc(sizeof(int)*scoreSize);
    z=malloc(sizeof(int)*scoreSize);
    for(i=0;i<scoreSize;i++){
        p[i]=score[i][k];
    }
    for(i=0;i<scoreSize;i++){
        for(j=0;j<scoreSize;j++){
            if(p[i]>p[j]){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=q[i];
                q[i]=q[j];
                q[j]=temp;
               temp=r[i];
            }
        }
    }
    for(i=0;i<scoreSize;i++){
        for(j=0;j<scoreSize;j++){
            if(p[i]==q[j]){
                s[i]=score[j][0];
                t[i]=score[j][1];
                u[i]=score[j][2];
                v[i]=score[j][3];
                w[i]=score[j][4];
            }
        }
    }
    for(i=0;i<scoreSize;i++){
        for(j=0;j<scoreSize;j++){
            if(p[i]==r[j]){
                x[i]=score[j][0];
                y[i]=score[j][1];
                z[i]=score[j][2];
            }
        }
    }
    returnSize[0]=scoreSize;
    returnColumnSizes[0]=scoreColSize[0];
    return score;
}