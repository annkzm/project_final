
#ifndef STACK_IMPL_H_
#define STACK_IMPL_H_
#include<stdio.h>
#include<stdlib.h>

typedef struct _elem {
	int *group;
	int size_of_group;
	struct _elem *next;
} elem;
/*
void push (int *group, int size_of_group,struct elem **top);
int isEmpty(struct elem *top);
int get_size_of_top (struct elem *top);
int* top(struct elem *top);
void pop(struct elem **top);

*/

#endif
