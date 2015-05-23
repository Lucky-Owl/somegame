#include "room.hpp"

int main()
{ 
  list_t <item_t*> item_list ;
  list_t <room_t*> room_list ;
  room_t room( "test", "text test", item_list , room_list , true );
  const char* test = room.get_description ( );
  printf ( "%s \n", test );
  //room.show_items ( );
  //room.show_neighbours ( );
  room.change_available ( );
  room.check ( );
  return 0;
}
