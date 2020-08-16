/*
 ============================================================================
 Name        : Clustering.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"
#include "Common.h"
#include "Utility.h"

int main(int argc, char *argv[]) {
	Status status = INVALID_STATUS_CODE;
	int M, *k;
	int n;
	spmat *A ;
	status = extract_matrix_size(argc, argv, &n);
	A =spmat_allocate_list(n); /*allocation check within the function*/
	if(NULL == A){
		status = MALLOC_FAILED_CODE;
		get_error_message(status);
		goto l_cleanup;
	}
	k = (int*)malloc(n * sizeof(double)); /* changed here to int */
	if(NULL == k){
		status = MALLOC_FAILED_CODE;
		get_error_message(status);
		goto l_cleanup;
	}
	status = graph_loading(argc, argv, A, &k, &M);
	printf("total number of vertices %d,", A->n);
	status = SUCCESS_STATUS_CODE;
	return 0;

	l_cleanup:
	exit(status);
}
