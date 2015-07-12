#include "main.hpp"
using std::string;

int main ( )
{
//game constructor
  room_t * red_room = new room_t ( "red room", "it seems like walls in here are painted with blood", true );
  room_t * yellow_room = new room_t ( "yellow room", "you find yourself in a yellow room", true );
  room_t * green_room = new room_t ( "green room", "you win", false );
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
  event_regestry_t* REG = new event_regestry_t;
  event_t * opening_door = new event_t();
  opening_door -> add_visible ( opened_door );
  opening_door -> add_visible ( closed_door );
  opening_door -> add_available (green_room);
  REG -> add_event( opening_door, rusted_key, closed_door );
// game interface
  //init game instance
  bool done = false;
  system ("clear");
  std::cout << "Enter your name: " ;
  string name = ""; 
  std::cin >> name ;
  game_instance_t* game  = new game_instance_t ( name , yellow_room, REG );
  std::cout << "Welcome to this game, " << game -> get_name ( )  << "!" << std::endl;
  game -> show_help ();
  //game loop
  string turn = ""; 
  std::cout << "Take your action!" << std::endl ;
  while (!(done))
  {
    std::cin >> turn ;
    if ( game -> action ( turn ) == -1) 
    {
      done = true;
    } 
  }
  return 0;
}

