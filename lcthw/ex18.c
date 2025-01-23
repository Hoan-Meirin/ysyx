#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "ex18_sort.c"

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int *l,int *r,int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp, int*(sort)(int*,int*,int*,int,compare_cb))
{
    int i = 0;
	int *l = numbers;
	int *r = numbers + count - 1;
    int *sorted = sort(numbers,l,r, count, cmp);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // free(sorted);
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order, bubble_sort);
    test_sorting(numbers, count, reverse_order, quick_sort);
    test_sorting(numbers, count, strange_order, bubble_sort);

    free(numbers);

    return 0;
}

/*
	附加题第一题：疑似找到了，但有相同前缀的不止一个，要具体分析才能知道，但是我不知道机器码
	附加题第二题：免了
	附加题第三题：函数格式对肯定不会报错，但是唯心论排序。格式错了应该过不了编译
	附加题第四题：访问空指针是吧
	附加题第五题：没看懂要干什么，用回调调用回调？
*/