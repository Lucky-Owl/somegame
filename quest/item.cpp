#include "item.hpp"

item_t::item_t ( const char* name, const char* description, bool visible, bool usable ): name_ ( name ), description_ ( description ), visible_ ( visible ), usable_ ( usable )
{
}

item_t::~item_t ( )
{
  name_ = NULL;
  description_ = NULL;
}

const char* item_t::get_name ( )
{
  return name_;
}

const char* item_t::get_description ( )
{
  return description_;
}

void item_t::change_visible ( )
{
  visible_ = !visible_;
}

void item_t::change_usable ( )
{
  usable_ = !usable_;
}

void item_t::check ( )
{
  printf ( "name : %s \n", name_ );
  printf ( "description : %s \n", description_ );
  printf ( "visible : %s \n", visible_ ? "True" : "False");
  printf ( "usable : %s \n", usable_ ? "True" : "False");
}
