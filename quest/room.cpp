#include "room.hpp"

room_t::room_t ( string name, string description, bool available )
{  
  name_ = name;
  description_ = description;
  items_ = new list_t <item_t*> ( );
  neighbours_ = new list_t <room_t*> ( );
  available_ = available;
}

room_t::~room_t ( )
{
}

int room_t::visible_items_num ( )
{
  int n = 0;
  for (int i = 0; i<=(items_ -> get_len() ); i++)
  {
    item_t* curr_item = items_ ->  get_element(i);
    if (curr_item -> get_visible() )
    { 
      n++;
    }
  }
  return n;
}

int room_t::available_neighbours_num ( )
{
  int n = 0;
  for ( int i = 0; i <= ( neighbours_ -> get_len() ); i++ )
  {
    room_t* curr_elem = neighbours_ ->  get_element ( i );
    if (curr_elem -> available_)
    {
      n++;
    }
  }
  return n;
}

void room_t::show_room ( )
{ 
  std::cout << name_ << std::endl;
  std::cout << description_ << std::endl;
  int n = visible_items_num ( );
  std::cout << "There are " << n << " items in the room : " << std::endl;
  n = 1;
  for (int i = 0; i<= ( items_ -> get_len() ); i++)
  {
    item_t* curr_elem = items_ ->  get_element(i);
    if (curr_elem -> get_visible() )
    {
      std::cout << n << " - " << curr_elem -> get_name() << std::endl;
      n++;
    }
  }
  n = available_neighbours_num ( );
  std::cout << "The room has " << n << " neighbours : " << std::endl;
  n = 1;
  for ( int i = 0; i <= ( neighbours_ -> get_len() ); i++ )
  {
    room_t* curr_elem = neighbours_ ->  get_element ( i );
    if (curr_elem -> available_)
    {
      std::cout << n << " - " << curr_elem -> name_ << std::endl;
      n++;
    }
  }
}

void room_t::change_available ( )
{
  available_ = !available_;
}

void room_t::check ( )
{
  std::cout << "name : " << name_ << std::endl;
  std::cout << "description : " << description_ << std::endl;
  std::cout << "available : " << std::boolalpha << available_ << std::endl;
}

void room_t::add_neighbour ( room_t* neighbour )
{
  neighbours_->append_element ( neighbour );
  //tell neighbour
}

room_t* room_t::fetch_neighbour ( int num )
{
  int n = 1;
  for ( int i = 0; i <= ( neighbours_ -> get_len() ); i++ )
  {
    room_t* curr_elem = neighbours_ ->  get_element ( i );
    if (curr_elem -> available_)
    {
      if (n = num)
      { 
        return curr_elem;
      }
      n++;
    }
  }  
}

void room_t::add_item ( item_t* item )
{
  items_->append_element ( item );
}
 
item_t* room_t::fetch_item ( int num )
{  
  int n = 1;
  for (int i = 0; i<=(items_ -> get_len() ); i++)
  {
    item_t* curr_item = items_ ->  get_element(i);
    if (curr_item -> get_visible() )
    { 
      if (n = num)
      { 
        return curr_item;
      }
      n++;
    }
  }
}

void room_t::remove_item ( item_t* item)
{
  items_ -> delete_element_by_value ( item );
}

