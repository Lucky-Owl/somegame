#include "player.hpp"

player_t::player_t ( string name, room_t* current_room)
{
  name_ = name;
  current_room_ = current_room;
  inventory_ = new list_t <item_t*> ( );
}

string player_t::get_name ( )
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
    std::cout << "Wrong neighbour room number!" << std::endl;
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
    std::cout << "Wrong item number!" << std::endl;
   //delete from room
  }
  else
  {
    inventory_ -> append_element ( current_room_ -> fetch_item ( num ) ); 
  }
}

item_t* player_t::find_item ( int num )
{  
  if ( ( num>0 )&& (num <= ( ( inventory_ -> get_len() ) +1 ) ) )
  {
    item_t* element = inventory_ -> get_element ( num );
    inventory_ -> delete_element_by_number ( num );
    return element;
  }
  else 
  { 
    std::cout << "Wrong item number!" << std::endl;
  }
}

item_t* player_t::fetch_room_item ( int num )
{
  if ( ( num>0 )&& (num <= current_room_ -> visible_items_num() ) )
  {
    item_t* element = current_room_ -> fetch_item ( num );
    return element;
  }
  else 
  { 
    std::cout << "Wrong item number!" << std::endl;
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
    std::cout << "Wrong item number!" << std::endl;
  }
}

void player_t::show_inventory ( )
{
  std::cout << "There are "<< ( ( inventory_ -> get_len() ) +1 ) <<" items in your inventory : "<< std::endl;
  for ( int i = 0; i <= ( inventory_ -> get_len() ); i++ )
  {
    item_t* curr_elem = inventory_ ->  get_element ( i );
    std::cout << (i+1) <<" - "<< curr_elem -> get_name() << std::endl;
  }
} 
