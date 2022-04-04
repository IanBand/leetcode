/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    *returnSize = 2;
    int* indices = (int *) malloc(2 * sizeof(int));
    
    int i, j;
    
    for(i = 0; i < numsSize; ++i){
        for(j = 0; j < numsSize; ++j){
            if(j != i && nums[i] + nums[j] == target){
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
    return indices;
}

// brute force, compare everything to everything

// for the challenge of reducing the runtime to less than O(n^2), 
// my inital idea is to sort nums[] in O(n lon n) time and then iterate through it once,
// but Im not sure on the specifics and honestly I cant implement merge sort or heap sort in C off the top of my head
