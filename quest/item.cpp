#include "item.hpp"

item_t::item_t ( const char* name_, bool visible_, bool usable_ ): name_ ( name_ ), visible_ ( visible_ ), usable_ ( usable_ )
{
}

void change_visible ( bool visible_ )
{
  this->visible_ = !visible_;
}

void change_usable ( bool usable_ )
{
  this->usable_ = !usable_;
}

void check ( const char* name_, bool visible_, bool usable_ )
{
  
}
