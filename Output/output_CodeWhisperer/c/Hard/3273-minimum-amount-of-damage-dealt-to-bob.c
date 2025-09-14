/*
 You are given an integer power and two integer arrays damage and health, both having length n.
 Bob has n enemies, where enemy i will deal Bob damage[i] points of damage per second while they are alive (i.e. health[i] > 0).
 Every second, after the enemies deal damage to Bob, he chooses one of the enemies that is still alive and deals power points of damage to them.
 Determine the minimum total amount of damage points that will be dealt to Bob before all n enemies are dead.
 Example 1:
 Input: power = 4, damage = [1,2,3,4], health = [4,5,6,8]
 Output: 39
 Explanation:
 Attack enemy 3 in the first two seconds, after which enemy 3 will go down, the number of damage points dealt to Bob is 10 + 10 = 20 points.
 Attack enemy 2 in the next two seconds, after which enemy 2 will go down, the number of damage points dealt to Bob is 6 + 6 = 12 points.
 Attack enemy 0 in the next second, after which enemy 0 will go down, the number of damage points dealt to Bob is 3 points.
 Attack enemy 1 in the next two seconds, after which enemy 1 will go down, the number of damage points dealt to Bob is 2 + 2 = 4 points.
 Example 2:
 Input: power = 1, damage = [1,1,1,1], health = [1,2,3,4]
 Output: 20
 Explanation:
 Attack enemy 0 in the first second, after which enemy 0 will go down, the number of damage points dealt to Bob is 4 points.
 Attack enemy 1 in the next two seconds, after which enemy 1 will go down, the number of damage points dealt to Bob is 3 + 3 = 6 points.
 Attack enemy 2 in the next three seconds, after which enemy 2 will go down, the number of damage points dealt to Bob is 2 + 2 + 2 = 6 points.
 Attack enemy 3 in the next four seconds, after which enemy 3 will go down, the number of damage points dealt to Bob is 1 + 1 + 1 + 1 = 4 points.
 Example 3:
 Input: power = 8, damage = [40], health = [59]
 Output: 320
 Constraints:
 1 <= power <= 104
 1 <= n == damage.length == health.length <= 105
 1 <= damage[i], health[i] <= 104
*/

long long minDamage(int power, int* damage, int damageSize, int* health, int healthSize) {
    int n = damageSize;
    int* sortedDamage = (int*)malloc(n * sizeof(int));
    int* sortedHealth = (int*)malloc(n * sizeof(int));
    int* indices = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        sortedDamage[i] = damage[i];
        sortedHealth[i] = health[i];
        indices[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedDamage[j] > sortedDamage[j + 1]) {
                int temp = sortedDamage[j];
                sortedDamage[j] = sortedDamage[j + 1];
                sortedDamage[j + 1] = temp;
                
                temp = sortedHealth[j];
                sortedHealth[j] = sortedHealth[j + 1];
                sortedHealth[j + 1] = temp;
                
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    long long totalDamage = 0;
    for (int i = 0; i < n; i++) {
        int enemyIndex = indices[i];
        int enemyDamage = sortedDamage[i];
        int enemyHealth = sortedHealth[i];
        
        int attacks = (enemyHealth + power - 1) / power;
        totalDamage += (long long)attacks * enemyDamage;
    }
    
    free(sortedDamage);
    free(sortedHealth);
    free(indices);
    
    return totalDamage;    
}