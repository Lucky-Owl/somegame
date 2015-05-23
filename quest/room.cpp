#include "room.hpp"

room_t::room_t ( const char* name_, const char* description_, list_t <item_t*> items_ , list_t <room_t*> neighbours_, bool available_ ):
	name_ ( name_ ), description_ ( description_ ), items_ ( items_ ), neighbours_ ( neighbours_ ), available_ ( available_ )
{  
}

room_t::~room_t ( )
{
  name_ = NULL;
  description_ = NULL;
  //lists
}

const char* room_t::get_description ( )
{
return description_;
}

void room_t::show_items ( )
{
}

void room_t::show_neighbours ( )
{
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
