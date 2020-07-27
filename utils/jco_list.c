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
#include "jco_list.h"

/* 
  Returns:
    The LST object allocated
    or NULL in case of error allocating the object memory.

  ERRORS:
    See stderr for the errors.
*/
LST * lst_new(/* NULL or pointer to function equals == */){
    LST * obj = (LST *) malloc(sizeof(LST));
    if (obj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_new: error while allocating the obj memory.\n");
        return NULL;
    }
    obj->firstNode = NULL;
    obj->lastNode = NULL;
    obj->iterator = NULL;
    obj->size = 0;
    return obj;
}


/*
  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    true if the memory was made free,
    or false if the lstObj was in an incorrect state to be free.

  ERRORS:
    See stderr for the errors.
*/
bool lst_free(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_free: lstObj is NULL!\n");
        return false;
    }else if ( (*lstObj).size != 0){
        fprintf(stderr,
            "ERROR: jco_list in func lst_free: lstObj has %d elements!\n", (*lstObj).size);
        return false;
    }else if (   (*lstObj).firstNode != NULL
              || (*lstObj).lastNode != NULL
         //   || (*lstObj).iterator != NULL
                ){
        fprintf(stderr,
            "ERROR: jco_list in func lst_free: lstObj has incoherent state!\n");
        return false;
    }else{
        // DEBUG Uncomment.
        free(lstObj);
        return true;
    }
}


/*
  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    int - The number of elements in the list.
          or a negative number in case of error.

  ERRORS:
    See stderr for the errors.
*/
int lst_size(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_size: lstObj is NULL!\n");
        return -1;
    }else if ( (*lstObj).size < 0){
        fprintf(stderr,
            "ERROR: jco_list in func lst_size: lstObj has impossible size of %d elements!\n", (*lstObj).size);
    }
    return (*lstObj).size;
}


/////////
// GET

/*
  NOTE: Alias for lst_get_at() pos = 0. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    void * - The element in the pos, you can't deallocate it's memory. 
             In case of error it return NULL.

  ERRORS:
    See stderr for the errors.
*/
void * lst_get_first(LST * lstObj){
    int pos = 0;
    return lst_get_at(lstObj, pos);
}


/*
  NOTE: Alias for lst_get_at() pos = last element. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    void * - The element in the pos, you can't deallocate it's memory. 
             In case of error it return NULL.

  ERRORS:
    See stderr for the errors.
*/
void * lst_get_last(LST * lstObj){
    int pos = lst_size(lstObj) - 1;
    return lst_get_at(lstObj, pos);
}


/*
  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

    pos - Pos of the element. 0 <= pos < size - 1 .

  Returns:
    void * - The element in the pos, you can't deallocate it's memory. 
             In case of error it return NULL.

  ERRORS:
    See stderr for the errors.
*/
void * lst_get_at(LST * lstObj, int pos){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_get_at: lstObj is NULL!\n");
        return NULL;
    }else if ( pos < 0 || pos >= lstObj->size ){
        fprintf(stderr, "ERROR: jco_list in func lst_get_at: pos out of bounds, 0 <= pos < size !\n");
        return NULL;
    }else{
        NODE * currNode = NULL;
        // Decide if start from the begin or from the end?
        // Find the node corresponding to the position before the position.
        if ((float)pos <= (float)lstObj->size / 2){
            // First half of the list.
            currNode = lstObj->firstNode;
            for(int i = 1; i <= pos; ++i){
                currNode = currNode->next;
            }
        }else{
            // Second half of the list.
            // From last pos to the begining (last half).
            currNode = lstObj->lastNode;
            for(int i = lstObj->size - 2; i >= pos; --i){
                currNode = currNode->prev;
            }
        }
        return currNode->elem;
    }
}


/////////
// INSERT

/*
  NOTE: Alias for lst_insert_at() pos = 0. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

    void * elem - The element to be added, a previously allocated element.

  Returns:
    bool - In case of error while inserting a new element in the list.

  ERRORS:
    See stderr for the errors.
*/
bool lst_insert_first(LST * lstObj, void * elem){
    int pos = 0;
    return lst_insert_at(lstObj, elem, pos);
}


/*
  NOTE: Alias for lst_insert_at() pos = last element + 1. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

    void * elem - The element to be added, a previously allocated element.

  Returns:
    bool - In case of error while inserting a new element in the list.

  ERRORS:
    See stderr for the errors.
*/
bool   lst_insert_last(LST * lstObj, void * elem){
    int pos = lst_size(lstObj);
    return lst_insert_at(lstObj, elem, pos);
}


/*
  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

    void * elem - The element to be added, a previously allocated element.

    pos - Pos of the element to be inserted. 0 <= pos <= size - 1 .

  Returns:
    bool - In case of error while inserting a new element in the list.

  ERRORS:
    See stderr for the errors.
*/
bool lst_insert_at(LST * lstObj, void * elem, int pos){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_insert_at: lstObj is NULL!\n");
        return false;
    }else if (elem == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_insert_at: elem is NULL!\n");
        return false;
    }else if ( pos < 0 && pos > lstObj->size ){
        fprintf(stderr, "ERROR: jco_list in func lst_insert_at: pos out of bounds, 0 <= pos <= size !\n");
        return false;
    }else{
        NODE * nodeToBeInserted = (NODE *) malloc(sizeof(NODE));
        if (nodeToBeInserted == NULL){
            fprintf(stderr, "ERROR: jco_list in func lst_insert_at: while allocating NODE!\n");
            return false;
        }

        NODE * currNode = NULL;
        // Decide if start from the begin or from the end?
        // Find the node corresponding to the position before the position.
        if ((float)pos <= (float)lstObj->size / 2){
            // First half of the list.
            if (lstObj->firstNode == NULL)
                currNode = NULL;
            else{
                if (pos == 0)
                    currNode = NULL;
                else{
                    // pos >= 1 ==> currNode >= 0 
                    currNode = lstObj->firstNode;
                    // Goes to pos >= 2.
                    for(int i=1; i <= pos - 1; ++i){
                        currNode = currNode->next;
                    }
                }
            }
        }else{
            // Second half of the list.
            // From last pos to the begining (last half).
            if (lstObj->lastNode == NULL)
                currNode = NULL;
            else{
                if (pos == 0)
                    currNode = NULL;
                else{
                    // pos >= 1 ==> currNode <= last node  
                    currNode = lstObj->lastNode;
                    // Goes to pos >= 2.
                    for(int i = lstObj->size - 2; i >= pos - 1; --i){
                        currNode = currNode->prev;
                    }
                }
            }
        }

        // Fill the node fields.
        nodeToBeInserted->elem = elem;
        if (pos == 0 && lstObj->firstNode == NULL){
            // Adding when the list is empty.
            nodeToBeInserted->prev = NULL;
            nodeToBeInserted->next = NULL;
            lstObj->firstNode = nodeToBeInserted;
            lstObj->lastNode  = nodeToBeInserted;
        }else if (pos == 0){
            // Adding at the end when size != 0.
            nodeToBeInserted->prev = NULL;
            nodeToBeInserted->next = lstObj->firstNode;
            lstObj->firstNode = nodeToBeInserted;
            // lstObj->lastNode  = ; // We don't change.
            // Node N + 1
            nodeToBeInserted->next->prev = nodeToBeInserted;   
            // Node N - 1
            // currNode->next = ; // It doesn't exists.
        }else if (pos == lstObj->size){
            // Adding at the end when size != 0.
            nodeToBeInserted->prev = currNode;
            nodeToBeInserted->next = NULL;
            // lstObj->firstNode = ;  // We don't change.
            lstObj->lastNode = nodeToBeInserted;
            // Node N + 1
            // currNode->next->prev = ; // It doesn't exists.
            // Node N - 1
            currNode->next = nodeToBeInserted; 
        }else{
            // Adding in the middle when size != 0.
            nodeToBeInserted->prev = currNode;
            nodeToBeInserted->next = currNode->next;
            // Node N + 1
            currNode->next->prev = nodeToBeInserted; 
            // Node N - 1
            currNode->next = nodeToBeInserted;
        }

        lstObj->size++;
        return true;
    }
}


/////////
// REMOVE

/*
  NOTE: Alias for lst_remove_at() pos = 0. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    void * - The pointer do the object encapsulated that as to be free (the memory),
             in case of error of parameters, returns NULL.
             It also return NULL if there are no elements in the list.

  ERRORS:
    See stderr for the errors.
*/
void * lst_remove_first(LST * lstObj){
    if ( lstObj->size == 0 ){
        fprintf(stderr, 
          "ERROR: jco_list in func lst_remove_first: list has no elements!\n");
        return NULL;
    }else{
        int pos = 0;
        return lst_remove_at(lstObj, pos);
    }
}


/*
  NOTE: Alias for lst_remove_at() pos = last elem pos. 

  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    void * - The pointer do the object encapsulated that as to be free (the memory),
             in case of error of parameters, returns NULL.
             It also return NULL if there are no elements in the list.

  ERRORS:
    See stderr for the errors.
*/
void * lst_remove_last(LST * lstObj){
    if ( lstObj->size == 0 ){
        fprintf(stderr, 
          "ERROR: jco_list in func lst_remove_last: list has no elements!\n");
        return NULL;
    }else{    
        int pos = lst_size(lstObj) - 1;
        return lst_remove_at(lstObj, pos);
    }
}

/*
  Parameters:
    LST * lstObj - This is a list object created with the lst_new() func.

  Returns:
    void * - The pointer do the object encapsulated that as to be free (the memory),
             in case of error of parameters, returns NULL.

  ERRORS:
    See stderr for the errors.
*/
void * lst_remove_at(LST * lstObj, int pos){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_remove_at: lstObj is NULL!\n");
        return NULL;
    }else if (pos < 0 ){
        fprintf(stderr, "ERROR: jco_list in func lst_remove_at: pos is negative!\n");
        return NULL;
    }else if (pos > (lstObj->size - 1) ){
        fprintf(stderr, 
          "ERROR: jco_list in func lst_remove_at: pos greater then max elements in the list!\n");
        return NULL;
    }else {
        NODE * currNode = NULL;
        // Decide if start from the begin or from the end?
        if ((float)pos <= (float)lstObj->size / 2){
            // First half of the list.
            // Zero pos case.
            currNode = lstObj->firstNode;
            // Goes to pos > 0.
            for(int i=1; i <= pos; ++i){
                currNode = currNode->next;
            }
        }else{
            // Second half of the list.
            // Last last pos case.
            currNode = lstObj->lastNode;
            // Goes to pos > 0.
            for(int i = lstObj->size - 2; i >= pos; --i){
                currNode = currNode->prev;
            }
        }
        // Element to return to be free by the user.
        void * retElem = currNode->elem;
        // Zero case LST start pointer.
        if (pos == 0){
            lstObj->firstNode = currNode->next;
        }
        // Last case LST end pointer.
        if (pos == lstObj->size - 1){
            lstObj->lastNode = currNode->prev;
        }
        NODE * prevNode = currNode->prev;
        if (prevNode != NULL)
            prevNode->next = currNode->next;
        NODE * nextNode = currNode->next;
        if (nextNode != NULL)
            nextNode->prev = currNode->prev;
        // DEBUG: Uncomment.
        free(currNode);
        lstObj->size--;
        return retElem;
    }
}


///////////
// Iterator

bool lst_iter_get_first(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_get_first: lstObj is NULL!\n");
        return false;
    } else {
        if (lstObj->firstNode == NULL)
            return false;
        lstObj->iterator = lstObj->firstNode;
        return true;
    }
}


bool lst_iter_get_last(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_get_last: lstObj is NULL!\n");
        return false;
    } else {
        if (lstObj->lastNode == NULL)
            return false;
        lstObj->iterator = lstObj->lastNode;
        return true;
    }
}


void * lst_iter_next(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_next: lstObj is NULL!\n");
        return NULL;
    } else {
        if (lstObj->iterator == NULL)
            return NULL;
        else{
            // Makes a ptr to the curr Iterator.
            NODE * lastNode = lstObj->iterator;
            // Advances the iterator.
            lstObj->iterator = lastNode->next;
            // Returns the element.
            return lastNode->elem;
        }
    }
}


void * lst_iter_prev(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_prev: lstObj is NULL!\n");
        return NULL;
    } else {
        if (lstObj->iterator == NULL)
            return NULL;
        else{
            // Makes a ptr to the curr Iterator.
            NODE * lastNode = lstObj->iterator;
            // Advances the iterator to the previous.
            lstObj->iterator = lastNode->prev;
            // Returns the element.
            return lastNode->elem;
        }
    }
}


bool lst_iter_is_begin(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_next: lstObj is NULL!\n");
        return false;
    } else {
        if (lstObj->iterator == NULL)
            return true;
        else
            return false;
        
    }
}


bool lst_iter_is_end(LST * lstObj){
    if (lstObj == NULL){
        fprintf(stderr, "ERROR: jco_list in func lst_iter_next: lstObj is NULL!\n");
        return false;
    } else {
        if (lstObj->iterator == NULL)
            return true;
        else
            return false;
    }
}

