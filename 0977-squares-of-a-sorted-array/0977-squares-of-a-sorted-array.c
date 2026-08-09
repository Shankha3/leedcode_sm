

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if (numsSize == 0) {
        return NULL;
    }

    int* result = (int*) malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] * nums[i];
    }
    
  
    for (int i = 0; i < numsSize - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                int c = result[j];
                result[j] = result[j + 1];
                result[j + 1] = c;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    return result;
}