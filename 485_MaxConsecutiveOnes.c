#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int findMaxConsecutiveOnes(int* nums, int numsSize);


int main(){

//size of array
int numsSize;
printf("Enter size of array: ");
scanf("%d", &numsSize);

//memory allocation 
int *nums =(int *)malloc(numsSize*sizeof(int));
if(nums == NULL){
    printf("Memory allocation failed\n");
    return -1;
}


//Enter elements in array 
printf("Enter %d elements (0s and 1s only): \n", numsSize);
for(int i=0;i<numsSize;i++){ 
    scanf("%d \n",&nums[i]);
    if(nums[i] != 0 && nums[i] != 1){
        printf("Invalid input. Please enter only 0s and 1s.\n");
        free(nums);
        return -1;
    }

    //call function 
    int result =  findMaxConsecutiveOnes (nums, numsSize);
    printf("Max consecutive ones: %d\n", result);

    free (nums);
    return 0;
}
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans=0,cnt=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 1)
        {
             cnt++;
        }
        else{
            cnt=0;
        }
        ans = fmax(ans,cnt);
    }
    return ans;
}