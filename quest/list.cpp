#include "list.hpp"

template <typename T>
list_t<T>::list_t ( )
{
  len_ = -1;
  head_ = NULL;
}

template <typename T>
list_t<T>::~list_t ( )
{
  elem_t <T> * tmp = head_;
  if ( head_ != NULL )
  {
    while ( tmp->next_ != NULL )
    {
      tmp = tmp->next_;
      delete tmp;
    }
    delete head_;
  }
  len_ = -1;
}

template <typename T>
void list_t<T>::append_element ( T value )
{
  elem_t <T> * tmp = head_;
  if ( tmp == NULL )
  {
    head_ = new elem_t <T>;
    head_->value_ = value;
    head_->next_ = NULL;
  }
  else
  {
    while ( tmp->next_ != NULL )
    {
      tmp = tmp->next_;
    }
    tmp->next_ = new elem_t <T>;
    tmp->next_->value_ = value;
    tmp->next_->next_ = NULL;
  }
  len_++;
}

template <typename T>
void list_t<T>::set_element ( int n, T value )
{
  assert ( n <= len_ );
  assert ( n >= 0 );
  elem_t <T> * tmp = head_;
  while ( n != 0 )
  {
    tmp = tmp->next_;
    n--;
  }
  tmp->value_ = value;
}

template <typename T>
T list_t<T>::get_element ( int n )
{
  assert ( n <= len_ );
  assert ( n >= 0 );
  elem_t <T> * tmp = head_;
  while ( n != 0 )
  {
    tmp = tmp->next_;
    n--;
  }
  return tmp->value_;
}

template <typename T>
void list_t<T>::delete_element_by_number ( int n )
{
  assert ( n <= len_ );
  assert ( n >= 0 );
  if ( n == 0 )
    head_ = head_->next_;
  else
  {
    n--;
    elem_t <T> * current = head_->next_;
    elem_t <T> * last = head_;
    while ( n != 0 )
    {
      current = current->next_;
      last = last->next_;
      n--;
    }
    last->next_ = current->next_;
    delete current;
  }
  len_--;
}

template <typename T>
int list_t<T>::get_number_by_element ( T element )
{
  int n = 0;
  elem_t <T> * tmp = head_;
  while ( tmp->value_ != element )
  {
    tmp = tmp->next_;
    n++;
    if ( ( tmp->next_ == NULL ) && ( tmp->value_ != element ) )
      return -1;
  }
  return n;
}

template <typename T>
int list_t<T>::get_len ( )
{
  return len_;
}
