#include "item.hpp"

item_t::item_t ( string name, string description, bool visible, bool usable ): name_ ( name ), description_ ( description ), visible_ ( visible ), usable_ ( usable )
{
}

item_t::~item_t ( )
{
}

string item_t::get_name ( )
{
  return name_;
}

string item_t::get_description ( )
{
  return description_;
}

bool item_t::get_visible ( )
{
  return visible_;
}

bool item_t::get_usable ( )
{
  return usable_;
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
  std::cout << "name : " << name_ << std::endl;
  std::cout << "description : " << description_ << std::endl;
  std::cout << "visible : " << std::boolalpha << visible_ << std::endl;
  std::cout << "usable : " << std::boolalpha << usable_ << std::endl;
}
