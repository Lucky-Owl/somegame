#ifndef H_ROOM
#define H_ROOM

//----Headers------------------------------------------------------------------
#include "item.hpp"
#include "list.hpp"
#include <stdio.h>
//-----------------------------------------------------------------------------

//----Classes------------------------------------------------------------------
class room_t
{ 
  private:
    const char* name_;    
    const char* description_;
    list_t <item_t*>* items_;
    list_t <room_t*>* neighbours_;
    bool available_;  

  public:
    room_t ( const char* name, const char* description, bool available );
    ~room_t ( );
    int visible_items_num ( );
    int available_neighbours_num ( );
    void show_room ( );
    void change_available ( );
    void check ( );
    void add_neighbour ( room_t* neighbour );
    room_t* get_neighbour ( int num );  
    void add_item ( item_t* item );
    item_t* get_item ( int num );
    void remove_item ( item_t* item);
};
//-----------------------------------------------------------------------------

#endif
