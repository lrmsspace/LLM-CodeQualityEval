/**https://leetcode.com/problems/movement-of-robots/ */
//Some robots are standing on an infinite number line with their initial coordinates given by a 0-indexed integer array nums and will start moving once given the command to move. The robots will move a unit distance each second.
//You are given a string s denoting the direction in which robots will move on command. 'L' means the robot will move towards the left side or negative side of the number line, whereas 'R' means the robot will move towards the right side or positive side of the number line.
//If two robots collide, they will start moving in opposite directions.
//Return the sum of distances between all the pairs of robots d seconds after the command. Since the sum can be very large, return it modulo 109 + 7.
//Note: 
//	For two robots at the index i and j, pair (i,j) and pair (j,i) are considered the same pair.
//	When robots collide, they instantly change their directions without wasting any time.
//	Collision happens when two robots share the same place in a moment.
//	
//		For example, if a robot is positioned in 0 going to the right and another is positioned in 2 going to the left, the next second they'll be both in 1 and they will change direction and the next second the first one will be in 0, heading left, and another will be in 2, heading right.
//		For example, if a robot is positioned in 0 going to the right and another is positioned in 1 going to the left, the next second the first one will be in 0, heading left, and another will be in 1, heading right.
//	
//	
// 
//Example 1:
//Input: nums = [-2,0,2], s = "RLL", d = 3
//Output: 8
//Explanation: 
//After 1 second, the positions are [-1,-1,1]. Now, the robot at index 0 will move left, and the robot at index 1 will move right.
//After 2 seconds, the positions are [-2,0,0]. Now, the robot at index 1 will move left, and the robot at index 2 will move right.
//After 3 seconds, the positions are [-3,-1,1].
//The distance between the robot at index 0 and 1 is abs(-3 - (-1)) = 2.
//The distance between the robot at index 0 and 2 is abs(-3 - 1) = 4.
//The distance between the robot at index 1 and 2 is abs(-1 - 1) = 2.
//The sum of the pairs of all distances = 2 + 4 + 2 = 8.
//Example 2:
//Input: nums = [1,0], s = "RL", d = 2
//Output: 5
//Explanation: 
//After 1 second, the positions are [2,-1].
//After 2 seconds, the positions are [3,-2].
//The distance between the two robots is abs(-2 - 3) = 5.
// 
//Constraints:
//	2 <= nums.length <= 105
//	-2 * 109 <= nums[i] <= 2 * 109
//	0 <= d <= 109
//	nums.length == s.length 
//	s consists of 'L' and 'R' only
//	nums[i] will be unique.
int sumDistance(int* nums, int numsSize, char * s, int d){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a[numsSize], b[numsSize], c[numsSize], d[numsSize], e[numsSize], f[numsSize], g[numsSize], h[numsSize], i[numsSize], j[numsSize], k[numsSize],l[numsSize], m[numsSize], n[numsSize], o[numsSize], p[numsSize], q[numsSize], r[numsSize], s[numsSize], t[numsSize], u[numsSize], v[numsSize], w[numsSize], x[numsSize], y[numsSize], z[numsSize];
    for(i=0;i<numsSize;i++){
        a[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        b[i]=s[i];
    }
    for(i=0;i<numsSize;i++){
        c[i]=d;
    }
    for(i=0;i<numsSize;i++){
        d[i]=0;
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                d[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                e[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                f[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                g[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                h[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                i[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                j[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                k[i]++;
            }
        }
    }

        for(i=0;i<numsSize;i++){
            for(j=0;j<numsSize;j++){
                if(a[i]==a[j]){
                    l[i]++;
                }
            }
        }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                m[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                n[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                o[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                p[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                q[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                r[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                s[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                t[i]++;
            }
        }
    }

        for(i=0;i<numsSize;i++){
            for(j=0;j<numsSize;j++){
                if(a[i]==a[j]){
                    u[i]++;
                }
            }
        }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                v[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                w[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                x[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                y[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(a[i]==a[j]){
                z[i]++;
            }
        }
    }
    return 0;
}