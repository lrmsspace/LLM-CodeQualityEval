/*
 A magician has various spells.
 You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
 It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
 Each spell can be cast only once.
 Return the maximum possible total damage that a magician can cast.
 Example 1:
 Input: power = [1,1,3,4]
 Output: 6
 Explanation:
 The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
 Example 2:
 Input: power = [7,1,6,6]
 Output: 13
 Explanation:
 The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
 Constraints:
 1 <= power.length <= 105
 1 <= power[i] <= 109
*/

long long maximumTotalDamage(int* power, int powerSize) {

    // Sort the array in ascending order
    qsort(power, powerSize, sizeof(int), compare);
    
    // Initialize the maximum total damage as 0
    long long maxTotalDamage = 0;
    
    // Iterate through the sorted array from the beginning
    for (int i = 0; i < powerSize - 1; i++) {
        
        // If the current damage is not a multiple of 3, subtract it from the next damage
        if (power[i] % 3!= 0) {
            power[i + 1] -= power[i];
        }
        
        // Update the maximum total damage
        maxTotalDamage += power[i];
    }
    
    return maxTotalDamage;
    
}