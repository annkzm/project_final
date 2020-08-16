/*
 * stack_impl.c
 *
 *  Created on: 16 баев„ 2020
 *      Author: USER
 */
#include <stdio.h>
#include "stack_impl.h"
#include <stdlib.h>
#include "Common.h"

void push (int *group, int size_of_group,struct elem **top){
	Status status = INVALID_STATUS_CODE;
	int i=0;
	struct elem* element = (struct elem*)malloc(sizeof(struct elem));
	if (NULL == element) {
			status = MALLOC_FAILED_CODE;
			get_error_message(status);
			exit(status);
		}
	element->group =(int*)malloc(size_of_group*sizeof(int));
	if (NULL == element->group) {
			status = MALLOC_FAILED_CODE;
			get_error_message(status);
			exit(status);
		}
	element -> size_of_group = size_of_group;
	for(i=0;i<size_of_group; i++){
		element -> group[i] = group[i];
	}
	element->next = *top;
	(*top) = element;
	status = SUCCESS_STATUS_CODE;
}

int isEmpty(struct elem *top){
	return top==NULL;

}

int get_size_of_top (struct elem *top){
	Status status = INVALID_STATUS_CODE;
	if(!isEmpty(top)){
		return top->size_of_group; // @suppress("Field cannot be resolved")
		status = SUCCESS_STATUS_CODE;
	}
	else {
		status = NULL_ARGUMENT_CODE;
		get_error_message(status);
		exit(status);
	}
}

int* top(struct elem *top){
	Status status = INVALID_STATUS_CODE;
	int i;
	if(!isEmpty(top)){
			return top->group;
		}
	else {
			status = NULL_ARGUMENT_CODE;
			get_error_message(status);
			exit(status);
		}
}

void pop(struct elem **top){
	Status status = INVALID_STATUS_CODE;
	if(!isEmpty(top)){
		struct elem *temp = *top;
		*top = (*top)->next;
		free(temp->group);
		free(temp);
	}

}



