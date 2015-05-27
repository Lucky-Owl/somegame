#include "player.hpp"

player_t::player_t ( const char* name, room_t* current_room)
{
  name_ = name;
  current_room_ = current_room;
  inventory_ = new list_t <item_t*> ( );
}

const char* player_t::get_name ( )
{
  return name_;
}

void player_t::change_current_room ( int num )
{   
  if ( ( num > 0 ) && (num <= current_room_ -> available_neighbours_num ( ) ) )
  {  
    current_room_ = current_room_ -> fetch_neighbour ( num );
  }
  else
  {
    printf ("Wrong neighbour room number!");
  }
}

void player_t::show_current_room ( )
{
  current_room_ -> show_room ( );
}

void player_t::take_item ( int num )
{ 
  if ( ( num <= 0 ) || ( current_room_ -> visible_items_num() < num ) )
  {
    printf ("Wrong item number!");
  }
  else
  {
    inventory_ -> append_element ( current_room_ -> fetch_item ( num ) ); 
  }
}

void player_t::drop_item ( int num )
{  
  if ( ( num>0 )&& (num <= ( ( inventory_ -> get_len() ) +1 ) ) )
  {
    inventory_ -> delete_element_by_number ( num );
  }
  else 
  { 
    printf ("Wrong item number!");
  }
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
