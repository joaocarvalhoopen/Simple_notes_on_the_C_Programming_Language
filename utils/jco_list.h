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

#ifndef JCO_LIST_H
#define JCO_LIST_H

#include <stdbool.h>


#define toi (int *)
#define tof (float *)
#define tod (double *)
#define toc (char *)
#define tob (bool *)

typedef enum { LST_D_UP, LST_D_DOWN } LST_DIRECTION;
// typedef enum { LST_Q_ONE, LST_Q_ALL } LST_QUANT;


typedef struct node{
    void * elem;
    struct node * next;
    struct node * prev;
} NODE;

typedef struct{
    NODE * firstNode;
    NODE * lastNode;
    int size;
    NODE * iterator;
} LST;


int cmp_int(void * aIn, void * bIn);
int cmp_float(void * aIn, void * bIn);
int cmp_double(void * aIn, void * bIn);
int cmp_single_char(void * aIn, void * bIn);
int cmp_null_term_str(void * aIn, void * bIn);


LST *  lst_new(/* NULL or pointer to function equals == */);
bool   lst_free(LST * lstObj);

int    lst_size(LST * lstObj);

void * lst_get_first(LST * lstObj);
void * lst_get_last(LST * lstObj);
void * lst_get_at(LST * lstObj, int pos);

// Returns the previous existing element in that pos.
void * lst_set(LST * lstObj, void * elem, int pos);

bool   lst_insert_first(LST * lstObj, void * elem);
bool   lst_insert_last(LST * lstObj, void * elem);
bool   lst_insert_at(LST * lstObj, void * elem, int pos);

// Receives a pointer to a function compare that as 
// 2 parameters "a" and "b" and returns int,
// 1 if a > b, 0 if a == b and -1 if a < b.
 bool   lst_insert_ordered(LST * lstObj, void * elem,
                          int (* const ptr_to_funct_cmp) (void * a, void * b ) );

void * lst_remove_first(LST * lstObj);
void * lst_remove_last(LST * lstObj);
void * lst_remove_at(LST * lstObj, int pos);

// Iterators NEXT and PREV.
bool   lst_iter_get_first(LST * lstObj);
bool   lst_iter_get_last(LST * lstObj);
void * lst_iter_next(LST * lstObj);
void * lst_iter_prev(LST * lstObj);
bool   lst_iter_is_begin(LST * lstObj);
bool   lst_iter_is_end(LST * lstObj);

void * lst_find(LST * lstObj, void * elem, 
                int (* const ptr_to_funct_cmp) (void * a, void * b),
                LST_DIRECTION direction,
                NODE * currNode,
                NODE ** foundNode);


// Stack
//
// Queue FIFO - First In First Out
//
// Queue LIFO - Last In First Out
//


//////////
// Not yet implemented...

void   lst_sort(LST * lstObj /*, pointer to function compare > */ );
// Not used in lists, used in arrayLists.
void * lst_binary_search(LST * lstObj, void * elem /*, pointer to function equals == */ );

//////////
// The following 3 function can be made with the function lst_find()
void * lst_find_first(LST * lstObj, void * elem, int (* const ptr_to_funct_equals) (void * a, void * b) );
void * lst_find_last(LST * lstObj, void * elem, int (* const ptr_to_funct_equals) (void * a, void * b) );
void * lst_find_all(LST * lstObj, void * elem, int (* const ptr_to_funct_equals) (void * a, void * b) );


#endif
