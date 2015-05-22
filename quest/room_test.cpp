#include "room.hpp"
#include <stdio.h>

int main()
{
  room_t room( "test", "text test", list_t <item_t*> (), 1 );
  return 0;
}
