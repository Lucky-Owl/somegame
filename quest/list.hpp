#ifndef H_CLIST
#define H_CLIST

//----Headers------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//-----------------------------------------------------------------------------

//----Classes------------------------------------------------------------------
template <typename T>
class elem_t
{
  public :
    T value_;
    elem_t <T> * next_;
};

template <typename T>
class list_t
{
  private :
    int len_;
    elem_t <T> * head_;

  public :
    list_t ( );
    ~list_t ( );
    void append_element ( T value );
    void set_element ( int n, T value );
    T get_element ( int n );
    void delete_element_by_number ( int n );
    void delete_element_by_value ( T value );
    void get_number_by_element ( T element, list_t <int> * answer );
    int get_len ( );
};
//-----------------------------------------------------------------------------

#endif
