/**https://leetcode.com/problems/subsets/ */
//Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
//	All the numbers of nums are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int* a;
    int* b;
    int* c;
    int* d;
    int* e;
    int* f;
    int* g;
    int* h;
    int* i;
    int* j;
    int* k;
   int* l;
    int* m;
    int* n;
    int* o;
    int* p;
    int* q;
    int* r;
    int* s;
    int* t;
    int* u;
    int* v;
    int* w;
    int* x;
    int* y;
    int* z;
    int** A;
    int** B;
    int** C;
    int** D;
    int** E;
    int** F;
    int**G;
    int** H;
    int** I;
    int** J;
    int** K;
    int** L;
    int** M;
    int** N;
    int** O;
    int** P;
    int** Q;
    int** R;
    int** S;
    int** T;
    int** U;
    int** V;
    int** W;
    int** X;
    int** Y;
    int** Z;
    *returnSize = 1;
    for(i=1;i<=numsSize;i++){
        *returnSize += pow(2,i);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = i+1;
    }
    A = (int**)malloc(sizeof(int*)*(*returnSize));
    for(i=0;i<*returnSize;i++){
        A[i] = (int*)malloc(sizeof(int)*(i+1));
    }
    for(i=0;i<*returnSize;i++){
        for(j=0;j<=i;j++){
            A[i][j] = 0;
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<*returnSize;j++){
            if(j%(pow(2,i+1))==0){
                A[j][i+1] = nums[i];
            }
        }
    }
    return A;
}