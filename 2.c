#include <stdio.h>

// 题目：
// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 你可以假设 nums1 和 nums2 不会同时为空。

// 目前自我测试OK，但是在leetcode运行失败，原因未知
// 错误例子：
// int p_nums1[2] ={1,2};
// int p_nums2[2] = {3,4};


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    if (nums1Size == 0 && nums2Size == 0 ) {
        printf("nums1Size=nums2Size=0 \n");
        return 0;
    }

    int *ns_now = NULL;
    int *ns_pro = NULL;
    int i=0,j=0;
    while ((i+j) <= (nums1Size+nums2Size)) {

        if (i+j == (nums1Size+nums2Size)/2+1) {
            break;
        }

        if (nums1[i] < nums2[j]) {
            if (ns_now) {
                ns_pro = ns_now;
            }
            ns_now = &nums1[i];
            i++;
        } else {
            if (ns_now) {
                ns_pro = ns_now;
            }
            ns_now = &nums2[j];
            j++;
        }
    }

    if ((nums1Size+nums2Size)%2) {
        return (double)*ns_now;
    } else {
        return ((double)*ns_now + (double)*ns_pro)/2;
    }
    
    return 0;
}
// int p_nums1[2] ={1,3};
// int p_nums2[1] = {2};
// printf("(nums1Size+nums2Size)u2:%d (nums1Size+nums2Size)/2+1:%d i:%d j:%d *ns_now:%d \n", (nums1Size+nums2Size)%2, (nums1Size+nums2Size)/2+1, i, j, *ns_now);
// printf("*ns_pro:%d \n", *ns_pro);
int p_nums1[2] ={1,2};
int p_nums2[2] = {3,4};
int main()
{
    // int i=0,z=0;
    // for (;i<3;i++,z++) {
    //     printf("i:%d z:%d\n", i, z);
    // }
    double n = findMedianSortedArrays(p_nums1, 2, p_nums2, 2);
    printf("n:%lf\n", n);
    return 0;
}