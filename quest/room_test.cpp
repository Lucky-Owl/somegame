#include "list.hpp"
#include "list.cpp"
#include "room.hpp"
#include "room.cpp"
#include "item.hpp"
#include "item.cpp"

int main()
{ 
  room_t room( "test1", "text test", true );
  room_t room2 ("test2", "text test2", false);
  room.add_neighbour ( &room2 );
  item_t item ( "test", "description test", true, false );
  room.add_item ( &item );
  room.show_room ( );
  room.change_available ( );
  room.check ( );
  room.remove_item ( &item);
  room.show_room ( );
  return 0;
}
