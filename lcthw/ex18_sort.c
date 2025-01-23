#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *part(int *l , int *r, int (*compare)(int, int))
{
	int *p = l;
	int *l_t = l;
	int *r_t = r;
	int pivot = *l;
	while(l_t < r_t)
	{
		while(compare(*r_t, pivot)>=0 && l_t < r_t) // 从右直到比pivot小的数
			r_t--;
		while(compare(*l_t, pivot)<=0 && l_t < r_t) // 从左直到比pivot大的数或与r相遇
			l_t++;
		if(l_t != r_t)
			swap(l_t, r_t);							// 交换r与l
	}
	if(p!=l_t)
	swap(p, l_t);									// 交换p与l
	return l_t;
}
/*
	9 8 7 6 5 4 3 2 1 0
	0 9 7 6 5 4 3 2 1

*/
int* quick_sort(int *num, int *l, int *r, int count, int (*compare)(int, int))
{
	if(l < r)
	{
		int *p = part(l, r, compare);
		if( p > num)
		quick_sort(num, l, p-1, count, compare);
		quick_sort(num, p+1, r, count, compare);
	}
	else
		return NULL;

	return num;
}

int compare(int a, int b)
{
	return a - b;
}

// the usage of quick_sort

// int main()
// {
// 	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
// 	quick_sort(a, a, a+9, compare);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		fprintf(stdout, "%d ", a[i]);
// 	}

// 	return 0;
	

// }