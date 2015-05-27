#include "main.hpp"

void show_help ( )
{ 
  printf("navigation: \n  'help' - for these tips\n  'look_around' - for room description\n  'check_pocket' - to see your inventory\n  'take[enter][item number]' - to put item in inventory\n  'throw_away[enter][item number]' - to remove object from inventory\n  'use[enter][pair of item numbers]' - to make action\n  'go[enter][room number]' - to enter another room");
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
  printf ( "Enter your name: " );
  char * name = ( char* ) malloc ( 100 );
  scanf ( "%s", name );
  player_t* player  = new player_t ( name , yellow_room );
  printf ("Welcome to this game, %s!\n", player -> get_name ( ) );
  player -> show_current_room ( );
  show_help ();
  //game loop
  bool act_done = false;
  char * turn = ( char* ) malloc ( 100 ) ;
  int number = 0, 
      first = 0, 
      second = 0;
  while (!(done))
  {
    printf ("Take your action!\n");
    scanf ("%s", turn);
    act_done = false;
    if ( ( !act_done ) && ( strcmp( turn, "help" )==0 ) )
    {
      show_help ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp( turn, "look_around" )==0 ) )
    {
      player -> show_current_room ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp ( turn, "check_pocket" )==0 ) )
    {
      player -> show_inventory ( );
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp ( turn, "take" )==0 ) )
    {
      scanf ( "%d", &number );
      player -> take_item ( number);
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp( turn, "throw_away" )==0 ) )
    {
      scanf ( "%d", &number );
      player -> drop_item ( number);
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp ( turn, "use" )==0 ) )
    {
      scanf ( "%d %d", &first, &second );
      //here goes event ><
      act_done = true;
    }
    if ( ( !act_done ) && ( strcmp ( turn, "go" )==0 ) )
    {
      scanf ( "%d", &number );
      player -> change_current_room ( number);
      act_done = true;
    }
    if (!act_done)
    {
      printf ("Try again\n");
    }
  }

  return 0;
}
