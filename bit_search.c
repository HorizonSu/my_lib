/*
 * 二分法查找
 * 2017-3-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* 函数实现 */
int bit_search(const int *arr, int len, int obj)
{
    int low = 0;
    int high = len - 1;
    int mid = 0;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (obj < arr[mid])
            high = mid - 1;
        else if (obj > arr[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/* 函数测试 */
int main(int argc, const char *argv[])
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int obj = 0;

    if (argc != 2) {
        printf("Input: %s 1~9\n", argv[0]);
        return -1;
    }

    obj = atoi(argv[1]);

    printf("%d\n", bit_search(arr, 10, obj));

    return 0;
}
