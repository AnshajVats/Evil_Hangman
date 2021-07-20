#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "Common.h"

struct my_vector_public;
typedef struct my_vector_public* MY_VECTOR;
typedef void* Item_ptr;

struct my_vector_public
{
    /*****PUBLIC********/
    //Precondition: hMy_vector holds the address of an opaque
    //              object of type MY_VECTOR ready to be destroyed.
    //Postcondition: All memory for the vector indicated by hMy_vector
    //               has been released.
    void(*destroy)(MY_VECTOR* phMy_vector);
    Status(*push_back)(MY_VECTOR hMy_vector, Item_ptr item);
    Status(*pop_back)(MY_VECTOR hMy_vector);
    Item_ptr(*at)(MY_VECTOR hMy_vector, int index); //checks array bounds
    int(*get_size)(MY_VECTOR hMy_vector); //Accessor function
    int(*get_capacity)(MY_VECTOR hMy_vector); //Accessor function
};





MY_VECTOR my_vector_init_default(void(*item_destroy)(Item_ptr* item_handle),
    Status(*item_assign)(Item_ptr* item_handle, Item_ptr item));

#endif