#include <math.h>

int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize < 3) {
        return numsSize;
    }
    int bitLength = 32 - __builtin_clz(numsSize);
    
    return 1 << bitLength;
}