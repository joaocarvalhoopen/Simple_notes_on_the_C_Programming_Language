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

typedef enum { UP, DOWN } LST_DIRECTION;

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


LST *  lst_new(/* NULL or pointer to function equals == */);
bool   lst_free(LST * lstObj);

int    lst_size(LST * lstObj);

void * lst_get_first(LST * lstObj);
void * lst_get_last(LST * lstObj);
void * lst_get_at(LST * lstObj, int pos);

bool   lst_insert_first(LST * lstObj, void * elem);
bool   lst_insert_last(LST * lstObj, void * elem);
bool   lst_insert_at(LST * lstObj, void * elem, int pos);

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

// Stack
//
// Queue FIFO - First In First Out
//
// Queue LIFO - Last In First Out
//

//////////
// Not yet implemented...

void   lst_sort(LST * lstObj /*, pointer to function compare > */ );
void * lst_find_first(LST * lstObj, void * elem /*, pointer to function equals == */ );
void * lst_find_last(LST * lstObj, void * elem /*, pointer to function equals == */ );
void * lst_find_all(LST * lstObj, void * elem /*, pointer to function equals == */ );

// Not used in lists, used in arrayLists.
void * lst_binary_search(LST * lstObj, void * elem /*, pointer to function equals == */ );

#endif
