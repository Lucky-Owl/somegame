#include "room.hpp"

int main()
{ 
  room_t room( "test", "text test", item_list , room_list , true );
  room.show_room ( );
  room.change_available ( );
  room.check ( );
  return 0;
}
