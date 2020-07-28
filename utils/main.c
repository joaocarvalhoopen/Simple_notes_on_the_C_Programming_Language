/*******************************************************************
* Name:   Abstract Double Linked List - jco_list.h and jco_list.c  *
* Author: Joao Nuno Carvalho                                       *
* Date:   2020.07.26                                               *
* License: MIT Open Source Licence                                 *
* Files:   jco_list.h                                              *
*          jco_list.c                                              *
*          main.c     (Test and example of usage code)             *
********************************************************************
* Notes: Read the main.c for examples on usage of this             *
*        Abstract Double Linked List.                              *
*******************************************************************/ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jco_list.h"


int test_lst_01(){
    char * testName = "test_lst_01";
    printf("\n=>Starting %s...\n", testName);
    int numErrors = 0;
    bool resB = false;
    LST * lst = lst_new();
    if (lst == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_new() returned a NULL pointer!\n", numErrors); 
    }

    int numElem = lst_size(lst);
    if (numElem != 0){
        numErrors++;
        printf("TEST_ERROR %d: lst_size() returned %d and should be 0 elements!\n",
               numErrors, numElem); 
    }

    int * var_int_0 = (int *) malloc(sizeof(int));
    int * var_int_1 = (int *) malloc(sizeof(int));
    int * var_int_2 = (int *) malloc(sizeof(int));
    int * var_int_3 = (int *) malloc(sizeof(int));
    *var_int_0 = 10;
    *var_int_1 = 11;
    *var_int_2 = 12;
    *var_int_3 = 13;
    

    ////////
    // Insert elements.

    // Insert elem in final pos num 1. (empty list)
    int pos = 0;
    resB = lst_insert_at(lst, var_int_1, pos); 
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_insert_at() returned a false!\n", numErrors);
    }
    // Insert elem in final pos num 0. ( not empty list)
    pos = 0;
    resB = lst_insert_at(lst, var_int_0, pos); 
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_insert_at() returned a false!\n", numErrors);
    }
    // Insert elem in final pos num 3. (last)
    pos = 2;
    resB = lst_insert_at(lst, var_int_3, pos);
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_insert_at() returned a false!\n", numErrors);
    }
    pos = 2;
    // Insert elem in final pos num 2. (middle)
    resB = lst_insert_at(lst, var_int_2, pos);
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_insert_at() returned a false!\n", numErrors);
    }

    //////
    // Iterators

    printf(" GET AT lst list values:\n");
    for(int i=0; i<lst_size(lst); ++i){
        pos = i;
        int * pTmpI = (int *) lst_get_at(lst, pos); 
        printf("%d\n", *pTmpI);
    }

    printf(" Iterator NEXT lst list values:\n");
    bool iterOK = lst_iter_get_first( lst );
    while( !lst_iter_is_end( lst ) ){
        int * pTmpI = (int *) lst_iter_next( lst );
        if (pTmpI != NULL)
            printf("%d\n", *pTmpI);
    }

    printf(" Iterator PREV lst list values:\n");
    iterOK = lst_iter_get_last( lst );
    while( !lst_iter_is_begin( lst ) ){
        int * pTmpI = (int *) lst_iter_prev( lst );
        if (pTmpI != NULL)
            printf("%d\n", *pTmpI);
    }


    //////
    // GET

    pos = 0;
    int * pGet_0 = (int *) lst_get_at(lst, pos); 
    if (pGet_0 != var_int_0){
        numErrors++;
        printf("TEST_ERROR %d: lst_get_at() returned the wrong value!\n", numErrors);
    }
    pos = 1;
    int * pGet_1 = (int *) lst_get_at(lst, pos); 
    if (pGet_1 != var_int_1){
        numErrors++;
        printf("TEST_ERROR %d: lst_get_at() returned the wrong value!\n", numErrors);
    }
    pos = 2;
    int * pGet_2 = (int *) lst_get_at(lst, pos); 
    if (pGet_2 != var_int_2){
        numErrors++;
        printf("TEST_ERROR %d: lst_get_at() returned the wrong value!\n", numErrors);
    }
    pos = 3;
    int * pGet_3 = (int *) lst_get_at(lst, pos); 
    if (pGet_3 != var_int_3){
        numErrors++;
        printf("TEST_ERROR %d: lst_get_at() returned the wrong value!\n", numErrors);
    }
    pos = 4;
    pGet_3 = (int *) lst_get_at(lst, pos); 
    if (pGet_3 != NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_get_at() returned a value != NULL !\n", numErrors);
    }


    ////////
    // Remove elements.

    // Remove element 1, in the middle.
    pos = 1;
    int * pInt_0 = (int *) lst_remove_at(lst, pos);
    if (pInt_0 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 1, in the last pos.
    pos = 1;
    int * pInt_1 = (int *) lst_remove_at(lst, pos);
    if (pInt_1 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 0, in the first pos.
    pos = 0;
    int * pInt_2 = (int *) lst_remove_at(lst, pos);
    if (pInt_2 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 0, in the first pos.
    pos = 0;
    int * pInt_3 = (int *) lst_remove_at(lst, pos);
    if (pInt_3 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }

    // Free the block of memory that the pointer points to objects or structures. 
    free(pInt_0);
    free(pInt_1);
    free(pInt_2);
    free(pInt_3);

    fflush(stdout);

    resB = lst_free(lst);
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_free() returned a false!\n", numErrors);
    }
    if (numErrors == 0)
        printf("    %s Passed.\n", testName);
    else
        printf("    %s Failed.\n", testName);
    return numErrors;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int test_lst_02(){
    char * testName = "test_lst_02";
    printf("\n=>Starting %s...\n", testName);
    int numErrors = 0;
    bool resB = false;
    LST * lst = lst_new();
    
    int numElem = lst_size(lst);
    
    int * var_int_0 = (int *) malloc(sizeof(int));
    int * var_int_1 = (int *) malloc(sizeof(int));
    int * var_int_2 = (int *) malloc(sizeof(int));
    int * var_int_3 = (int *) malloc(sizeof(int));
    *var_int_0 = 10;
    *var_int_1 = 11;
    *var_int_2 = 12;
    *var_int_3 = 13;
    
    ////////
    // Insert elements.

    // Insert ordered elem in final pos num 1. (empty list)
    resB = lst_insert_ordered(lst, var_int_1, cmp_int); 
    
    // Insert ordered elem in final pos num 0. ( not empty list)
    resB = lst_insert_ordered(lst, var_int_0, cmp_int); 
    
    // Insert ordered elem in final pos num 3. (last)
    resB = lst_insert_ordered(lst, var_int_3, cmp_int);
    
    // Insert ordered elem in final pos num 2. (middle)
    resB = lst_insert_ordered(lst, var_int_2, cmp_int);
    

    //////
    // Iterators

    printf(" Iterator NEXT lst list values:\n");
    bool iterOK = lst_iter_get_first( lst );
    while( !lst_iter_is_end( lst ) ){
        int * pTmpI = (int *) lst_iter_next( lst );
        if (pTmpI != NULL)
            printf("%d\n", *pTmpI);
    }


    /////////
    // Test lst_find
    
    NODE * currNode = NULL;
    NODE ** foundNode = (NODE **) calloc(1, sizeof(NODE *));
    
    int * var_int_n = (int * ) malloc(sizeof(int));
    *var_int_n = 33;
    const int NUM_PTRS = 5;
    int * ptrArInt[5] = {var_int_0, var_int_1, var_int_2, var_int_3, var_int_n};

    for(int i = 0; i < NUM_PTRS; ++i){
        if (foundNode == NULL)
            printf("ERROR: While allocating NODE ** foundNode.\n");
        int * var_tmp = ptrArInt[i];
        int * pInt_n = (int *) lst_find(lst, var_tmp, cmp_int, LST_D_UP,
                                        NULL, NULL);
                                   //  currNode, foundNode);
        if (pInt_n == NULL)
            printf("TEST_ERROR %d: lst_find() returned NULL error or not found!\n", numErrors);
        else
            printf("Found value %d\n", *pInt_n);
    }


    /////////
    // Test lst_find() detecting several occurrences  of element inside an object.

    // Insert one more element, copy of var_int_0.
    *var_int_n = *var_int_0;
    lst_insert_last(lst, var_int_n);
    printf(" Value %d added to the end of the list, repeated two times.\n", *var_int_n);
    

    int * pInt_n_1 = (int *) lst_find(lst, var_int_0, cmp_int, LST_D_UP,
                                     currNode, foundNode);
    printf("Found in sequence value %d\n", *pInt_n_1);
    
    // Dereference the pointer to pointer to Node and advances to the NEXT.
    currNode = (*foundNode)->next;
    // foundNode = NULL;
    int * pInt_n_2 = (int *) lst_find(lst, var_int_0, cmp_int, LST_D_UP,
                                     currNode, foundNode);
    if (pInt_n_1 != pInt_n_2)
        printf(" Correct - Pointer pInt_n_1 != pInt_n_2 - %p != %p \n", pInt_n_1, pInt_n_2);

    printf("Found in sequence value %d\n", *pInt_n_2);
    
    free(foundNode);
    free(var_int_n);

    lst_remove_last(lst);

    ///////////
    // Test SET
   
    int * var_int_10 = (int *) malloc(sizeof(int));
    int * var_int_11 = (int *) malloc(sizeof(int));
    int * var_int_12 = (int *) malloc(sizeof(int));
    int * var_int_13 = (int *) malloc(sizeof(int));
    *var_int_10 = 20;
    *var_int_11 = 21;
    *var_int_12 = 22;
    *var_int_13 = 23;
   
    int pos = 0;
    int * p_tmp_old = (int *) lst_set(lst, var_int_10, pos);
    if (p_tmp_old == NULL || *p_tmp_old != *var_int_0){
        numErrors++;
        printf("TEST_ERROR %d: lst_set() returned NULL or int value is different!\n",
               numErrors);
    }
    free(p_tmp_old);

    pos = 1;
    p_tmp_old = (int *) lst_set(lst, var_int_11, pos);
    if (p_tmp_old == NULL || *p_tmp_old != *var_int_1){
        numErrors++;
        printf("TEST_ERROR %d: lst_set() returned NULL or int value is different!\n",
               numErrors);
    }
    free(p_tmp_old);

    pos = 2;
    p_tmp_old = (int *) lst_set(lst, var_int_12, pos);
    if (p_tmp_old == NULL || *p_tmp_old != *var_int_2){
        numErrors++;
        printf("TEST_ERROR %d: lst_set() returned NULL or int value is different!\n",
               numErrors);
    }
    free(p_tmp_old);

    pos = 3;
    p_tmp_old = (int *) lst_set(lst, var_int_13, pos);
    if (p_tmp_old == NULL || *p_tmp_old != *var_int_3){
        numErrors++;
        printf("TEST_ERROR %d: lst_set() returned NULL or int value is different!\n",
               numErrors);
    }
    free(p_tmp_old);


    //////
    // Iterators

    printf("After lst_set() - Iterator NEXT lst list values:\n");
    iterOK = lst_iter_get_first( lst );
    while( !lst_iter_is_end( lst ) ){
        int * pTmpI = (int *) lst_iter_next( lst );
        if (pTmpI != NULL)
            printf("%d\n", *pTmpI);
    }


    ////////
    // Remove elements.

    // Remove element 1, in the middle.
    pos = 1;
    int * pInt_0 = (int *) lst_remove_at(lst, pos);
    if (pInt_0 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 1, in the last pos.
    pos = 1;
    int * pInt_1 = (int *) lst_remove_at(lst, pos);
    if (pInt_1 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 0, in the first pos.
    pos = 0;
    int * pInt_2 = (int *) lst_remove_at(lst, pos);
    if (pInt_2 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }
    // Remove element 0, in the first pos.
    pos = 0;
    int * pInt_3 = (int *) lst_remove_at(lst, pos);
    if (pInt_3 == NULL){
        numErrors++;
        printf("TEST_ERROR %d: lst_remove_at() returned NULL!\n", numErrors);
    }

    // Free the block of memory that the pointer points to objects or structures. 
    free(pInt_0);
    free(pInt_1);
    free(pInt_2);
    free(pInt_3);

    fflush(stdout);

    resB = lst_free(lst);
    if (!resB){
        numErrors++;
        printf("TEST_ERROR %d: lst_free() returned a false!\n", numErrors);
    }
    if (numErrors == 0)
        printf("    %s Passed.\n", testName);
    else
        printf("    %s Failed.\n", testName);
    return numErrors;
}


int main(){
    printf("\nTest program start....!\n");

    // stderr = stdout;

    // Test 1
    test_lst_01();

    // Test 2
    test_lst_02();

}