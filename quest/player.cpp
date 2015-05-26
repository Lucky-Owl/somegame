#include "player.hpp"

player_t::player_t ( const char* name, room_t* current_room)
{
  name_ = name;
  room_t* current_room_ = current_room;
  inventory_ = new list_t <item_t*> ( );
}

void player_t::take_item ( int num )
{ 
  inventory_ -> append_element (current_room_ -> get_item ( num ) ); 
}

void player_t::drop_item ( int num )
{  
   inventory_ -> delete_element_by_number ( num );
}

void player_t::show_inventory ( )
{
  printf ( "There are %d items in your inventory : \n", ( ( inventory_ -> get_len() ) +1 ) );
  for ( int i = 0; i <= ( inventory_ -> get_len() ); i++ )
  {
    item_t* curr_elem = inventory_ ->  get_element ( i );
    printf( "%d - %s\n", (i+1), curr_elem -> get_name() );
  }
} 
