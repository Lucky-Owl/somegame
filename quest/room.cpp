#include "room.hpp"

room_t::room_t ( const char* name, const char* description, bool available )
{  
  name_ = name;
  description_ = description;
  items_ = new list_t <item_t*> ( );
  neighbours_ = new list_t <room_t*> ( );
  available_ = available;
}

room_t::~room_t ( )
{
  name_ = NULL;
  description_ = NULL;
  //lists
}

void room_t::show_room ( )
{
  printf ( "name : %s \n", name_ );
  printf ( "description : %s \n", description_ );
  printf ( "there are %d items in the room : \n", ((items_ -> get_len())+1));
  for (int i = 0; i<=(items_ -> get_len()); i++)
  {
    item_t* curr_elem = items_->  get_element(i);
    printf("%s", curr_elem -> get_name());
  }
  printf ( "the room has %d heighbours : \n", ((neighbours_ -> get_len())+1)); 
  for (int i = 0; i<=(neighbours_ -> get_len()); i++)
  {
    room_t* curr_elem = neighbours_->  get_element(i);
    printf("%s", curr_elem -> name_);
  }
  printf ( "available : %s \n", available_ ? "True" : "False");
}

void room_t::change_available ( )
{
  available_ = !available_;
}

void room_t::check ( )
{
  printf ( "name : %s \n", name_ );
  printf ( "description : %s \n", description_ );
  printf ( "available : %s \n", available_ ? "True" : "False");
}

void room_t::add_neighbour ( room_t* neighbour )
{
  neighbours_->append_element ( neighbour );
  //tell neighbour
}

void room_t::add_item ( item_t* item )
{
  items_->append_element ( item );
}

void room_t::remove_item ( item_t* item)
{
   items_ -> delete_element_by_value ( item );
}
