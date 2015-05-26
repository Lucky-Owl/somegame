#include "main.hpp"

void show_help ( )
{ 
  printf("navigation: \n  'help' - for these tips\n  'look around' - for room description\n  'check pocket' - to see your inventory\n  'take [number of item]' - to put item in inventory\n  'use [pair of item numbers]' - to make action\n  'go [room number]' - to enter another room");
}

int main ( )
{
  room_t * red_room = new room_t ( "red_room", "you find yourself in a red room", true);
  room_t * yellow_room = new room_t ( "yellow_room", "you find yourself in a yellow room", true);
  room_t * green_room = new room_t ( "green_room", "you find yourself in a green room", false);
  item_t * closed_door = new item_t ("closed door", "you can't open it without a key", true, false);
  item_t * opened_door = new item_t ("opened door","just door", false, false);
  item_t * rusted_key = new item_t  ("rusted key", "old rusted key",true, true);
  yellow_room->add_item (closed_door);
  yellow_room->add_item (opened_door);
  red_room->add_item(rusted_key);
  red_room->add_neighbour(yellow_room);
  yellow_room->add_neighbour(green_room);
  yellow_room->add_neighbour(red_room);
  green_room->add_neighbour(yellow_room);
  event_regestry_t REG;
  event_t * opening_door = new event_t();
  opening_door->add_visible (opened_door);
  opening_door->add_visible (closed_door);

  opening_door->add_available (green_room);

  bool done = false;
  char c = '\n';
  room_t * current_room = yellow_room;
 
/*
take
use
go
show
*/
  current_room->show_room();
  show_help ();
  while (!(done))
  {
    
/*   c = getchar();
    switch (c)
    {
      case 't' :
        c = getchar();
        
      case 'u' :
      case 'g' :
      case 's' :
      default  : break;
    }
*/
  }

  return 0;
}
