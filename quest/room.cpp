#include "room.hpp"

room_t::room_t ( const char* name, const char* description, list_t <item_t*> items , int available ):
	name ( name ), description ( description ), items ( items ), available ( available )
{
 
}
