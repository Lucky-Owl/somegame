#ifndef H_PLAYER
#define H_PLAYER

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
#include "room.hpp"
#include <stdio.h>
//-------------------------------------

//----Classes--------------------------
class player_t
{
  private:
    room_t* current_room_ ;
    const char* name_;
    list_t <item_t*>* inventory_;

  public:  
    player_t ( const char* name, room_t* current_room );
    const char* get_name ( );
    void change_current_room ( int num );
    void show_current_room ( );
    void take_item ( int num );
    void drop_item ( int num );
    void show_inventory ( );
} ;
//-------------------------------------


#endif
