/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct NODE{
    int hashValue;
    int idx;
    struct NODE *next;
}NODE;

inline int hashFunc(int value, int hashSize){
    int r = value % hashSize;
    return (r > 0)? r : (-1)*r;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = (int *)malloc(2*sizeof(int));
    int hashSize = 2 * numsSize;
    NODE **hashTable = (NODE **)calloc(hashSize, sizeof(NODE *));

    for(int i=0; i<numsSize; i++){
        int value = nums[i];
        int complement = target - value;
        int key_comp = hashFunc(complement, hashSize);
        NODE *parser = hashTable[key_comp];
        while(parser != NULL){
            if(complement == parser->hashValue){
                ans[0] = parser->idx;
                ans[1] = i;
                return ans;
            }
            parser = parser->next;
        }
        int key = hashFunc(value, hashSize);
        NODE *newNODE =  (NODE *)malloc(sizeof(NODE));
        newNODE->hashValue = value;
        newNODE->idx = i;
        newNODE->next = hashTable[key];
        hashTable[key] = newNODE;
    }
    return ans;
}

