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

//------inventory functions----------------------------------------------------

void player_t::show_inventory ( )
{
  int it_num = ( inventory_ -> get_len() ) +1;
  if ( it_num == 0 )
  {
    std::cout << "You have no items yet."<< std::endl;
  }
  else if ( it_num == 1 )
  {
    std::cout << "There is one item in your inventory : "<< std::endl;
  }
  else
  {
    std::cout << "There are "<< it_num <<" items in your inventory : "<< std::endl;
  }
  for ( int i = 0; i <= ( inventory_ -> get_len() ); i++ )
  {
    item_t* curr_elem = inventory_ ->  get_element ( i );
    std::cout << (i+1) <<" - "<< curr_elem -> get_name() << std::endl;
  }
} 

void player_t::take_item ( int num )
{ 
  if ( ( num <= 0 ) || ( current_room_ -> visible_items_num() < num ) )
  {
    std::cout << "Wrong item number!" << std::endl;
  }
  else
  {
    item_t* candidate = current_room_ -> fetch_item ( num );
    if ( candidate -> get_usable () )
    {
      inventory_ -> append_element ( candidate ); 
      current_room_ -> remove_item ( candidate );
    }
    else
    {
      std::cout << "Sorry, you can't take this item!" << std::endl;
    }
  }
}

item_t* player_t::find_item ( int num )
{  
  if ( ( num>0 )&& (num <= ( ( inventory_ -> get_len() ) +1 ) ) )
  {
    item_t* element = inventory_ -> get_element ( num-1 );
    inventory_ -> delete_element_by_number ( num-1 );
    return element;
  }
  else 
  { 
    std::cout << "Wrong inventory item number!" << std::endl;
  }
}

void player_t::drop_item ( int num )
{  
  if ( ( num>0 )&& ( num <= ( ( inventory_ -> get_len() ) +1 ) ) )
  {
    item_t* element = inventory_ -> get_element ( num-1 );
    current_room_ -> add_item ( element );
  }
  else 
  { 
    std::cout << "Wrong item number!" << std::endl;
  }
}

//--------current room manipulations-------------------------------------------

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

item_t* player_t::fetch_room_item ( int num )
{
  if ( ( num>0 )&& (num <= current_room_ -> visible_items_num() ) )
  {
    item_t* element = current_room_ -> fetch_item ( num );
    return element;
  }
  else 
  { 
    std::cout << "Wrong room item number!" << std::endl;
  }
}

//-------interface-------------------------------------------------------------
/*
if we do this, event.reg should become part of player as well, but this can help to avoid usage of some transferring methods

int will_analyse ( string turn)   
{

}
*/
