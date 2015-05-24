#ifndef H_ROOM
#define H_ROOM
//----Headers--------------------------
#include "item.hpp"
#include "list.hpp"
#include <stdio.h>
//-------------------------------------

//----Classes--------------------------
class room_t
{ 
  private:
    const char* name_;    
    const char* description_;
    list_t <item_t*> items_;
    list_t <room_t*> neighbours_;
    bool available_;  

  public:
    room_t ( const char* name_, const char* description_,  list_t <item_t*> items_ , list_t <room_t*> neighbours_, bool available_ );
    ~room_t ( );
    const char* get_description ( );
    void show_room ( ); //show description of the current room and all items in it
    void change_available ( );
    void check ( );
    void add_neighbour ( room_t * neighbour ); //we should be able to add new neighbour after creating room
};
//-------------------------------------


#endif
