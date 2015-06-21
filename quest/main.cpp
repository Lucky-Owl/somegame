#include "main.hpp"
using std::string;

void show_help ( ) //change ending of words, looking at number  ; 
{ 
  std::cout << "navigation:" << std::endl <<  "  'help' - for these tips" << std::endl <<  "  'look_around' - for room description" << std::endl <<  "  'check_pocket' - to see your inventory" << std::endl <<  "  'take [item number]' - to put item in inventory" << std::endl <<  "  'throw_away [item number]' - to remove object from inventory" << std::endl <<  "  'use [pair of item numbers]' - to make action" << std::endl <<  "  'go [room number]' - to enter another room"  << std::endl << "  'give_up' - to end game" << std::endl;
}

int main ( )
{
//game constructor
  room_t * red_room = new room_t ( "red_room", "you find yourself in a red room", true );
  room_t * yellow_room = new room_t ( "yellow_room", "you find yourself in a yellow room", true );
  room_t * green_room = new room_t ( "green_room", "you find yourself in a green room", false );
  item_t * closed_door = new item_t ( "closed door", "you can't open it without a key", true, false );
  item_t * opened_door = new item_t ( "opened door","just door", false, false );
  item_t * rusted_key = new item_t  ( "rusted key", "old rusted key",true, true );
  yellow_room -> add_item ( closed_door );
  yellow_room -> add_item ( opened_door );
  red_room -> add_item ( rusted_key );
  red_room -> add_neighbour( yellow_room );
  yellow_room -> add_neighbour ( green_room );
  yellow_room -> add_neighbour ( red_room );
  green_room -> add_neighbour ( yellow_room );
  event_regestry_t REG;
  event_t * opening_door = new event_t();
  opening_door -> add_visible ( opened_door );
  opening_door -> add_visible ( closed_door );
  opening_door -> add_available (green_room);
// game interface
  //init player
  bool done = false;
  system ("clear");
  std::cout << "Enter your name: " ;
  string name = ""; 
  std::cin >> name ;
  player_t* player  = new player_t ( name , yellow_room );
  std::cout << "Welcome to this game, " << player -> get_name ( )  << "!" << std::endl;
  player -> show_current_room ( );
  show_help ();
  //game loop
  bool act_done = false;
  string turn = ""; 
  int number = 0, 
      first = 0, 
      second = 0;
  while (!(done))
  {
    std::cout << "Take your action!" << std::endl ;
    std::cin >> turn ;
    act_done = false;
    if ( ( !act_done ) && ( turn=="help" ) )
    {
      show_help ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="look_around" ) )
    {
      player -> show_current_room ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="check_pocket" ) )
    {
      player -> show_inventory ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="take" ) )
    {
      std::cin >>  number ;
      player -> take_item ( number);
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="throw_away" ) )
    {
      std::cin >> number ;
      player -> drop_item ( number);
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="use" ) )
    {
      std::cin >> first >> second ;
      REG.activate ( player -> find_item ( first ), player -> fetch_room_item ( second ) );
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="go" ) )
    {
      std::cin >> number ;
      player -> change_current_room ( number);
      act_done = true;
    }
    if ( ( !act_done ) && ( turn=="give_up" ) )
    {
      std::cout << "Thanks for playing." << std::endl;
      act_done = true;
      done = true;
    }
    if (!act_done)
    {
      std::cout << "Please, try again." << std::endl;
    }
  }

  return 0;
}
