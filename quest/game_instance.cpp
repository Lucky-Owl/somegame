#include "game_instance.hpp"

game_instance_t::game_instance_t ( string name, room_t* current_room, event_regestry_t* REG )
{
  name_ = name;
  current_room_ = current_room;
  REG_ = REG;
  inventory_ = new list_t <item_t*> ( );
}

string game_instance_t::get_name ( )
{
  return name_;
}

//------inventory functions----------------------------------------------------

void game_instance_t::show_inventory ( )
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

void game_instance_t::take_item ( int num )
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

item_t* game_instance_t::find_item ( int num )
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

void game_instance_t::drop_item ( int num )
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

void game_instance_t::change_current_room ( int num )
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

item_t* game_instance_t::fetch_room_item ( int num )
{
  if ( ( num>0 ) && (num <= current_room_ -> visible_items_num() ) )
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

void game_instance_t::show_help ( ) 
{ 
  std::cout << "navigation:" << std::endl <<  "  'help' - for these tips" << std::endl <<  "  'look_around' - for room description" << std::endl <<  "  'check_pocket' - to see your inventory" << std::endl <<  "  'take [item number]' - to put item in inventory" << std::endl <<  "  'throw_away [item number]' - to remove object from inventory" << std::endl <<  "  'use [pair of item numbers]' - to make action" << std::endl <<  "  'go [room number]' - to enter another room"  << std::endl << "  'give_up' - to end game" << std::endl;
}

int game_instance_t::action ( string turn)   
{
  int number = 0, 
      first = 0, 
      second = 0;
  if ( turn == "help" ) 
  {
    show_help ( );
    return 0;
  }
  if ( turn == "look_around" )
  {
    current_room_ -> show_room ( );
    return 0;
  }
  if ( turn == "check_pocket" ) 
  {
    show_inventory ( );
    return 0;
  }
  if ( turn == "take" ) 
  {
    std::cin >>  number ;
    take_item ( number);
    return 0;
  }
  if ( turn == "throw_away" ) 
  {
    std::cin >> number ;
    drop_item ( number);
    std::cin.clear();
    std::cin.sync();
    return 0;
  }
  if ( turn == "use" ) 
  {
    std::cin >> first >> second ;
    REG_ -> activate ( find_item ( first ), fetch_room_item ( second ) );
    std::cin.clear();
    std::cin.sync();
    return 0;
  }
  if ( turn == "go" )
  {
    std::cin >> number ;
    change_current_room ( number);
    std::cin.clear();
    std::cin.sync();
    return 0;
  }
  if ( turn == "give_up" )
  {
    std::cout << "Thanks for playing." << std::endl;
    return -1;
  }
  std::cout << "Please, try again." << std::endl;
  return 0;
}
