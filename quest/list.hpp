#ifndef H_CLIST
#define H_CLIST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

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
    list_t ( T value );
    ~list_t ( );
    void append_element ( T value );
    void set_element ( int n, T value );
    T get_element ( int n );
    void delete_element_by_number ( int n );
};
//-----------------------------------------------------------------------------

#endif