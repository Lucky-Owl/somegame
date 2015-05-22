#ifndef H_ROOM
#define H_ROOM
//----Headers--------------------------
#include "item.hpp"
#include "list.hpp"
//-------------------------------------

//----Classes--------------------------
class room_t
{ 
  private:
    const char* name;    
    const char* description;
    list_t <item_t*> items;
    int available;  

  public:
    room_t ( const char* name, const char* description,  list_t <item_t*> items , int available );
};
//-------------------------------------


#endif
