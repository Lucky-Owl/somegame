#include "room.hpp"

room_t::room_t ( const char* name, const char* description, list_t <item_t*>* items , list_t <room_t*>* neighbours, bool available )
{  
  name_ = name;
  description_ = description;
  list_t <item_t*>* items_ = new list_t <item_t*> ;
  list_t <room_t*>* neighbours_ = new list_t <room_t*> ;
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
  printf ( "there are %d items in the room : \n", ((items_.get_len)+1);
  //how to look through list?
  printf ( "the room has %d heighbours : \n", ((neighbours_.get_len)+1); 
  // -||-
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

void room_t::add_neighbour ( room_t * neighbour )
{
  neighbours_.append_element ( room_t * neighbour );
}

void room_t::add_item ( item_t* item )
{
  items_.append_element ( item_t* item );
}
