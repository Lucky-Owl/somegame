#ifndef H_PLAYER
#define H_PLAYER

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
#include "room.hpp"
#include <iostream>
using std::string;
//-------------------------------------

//----Classes--------------------------
class player_t
{
  private:
    room_t* current_room_ ;
    string name_;
    list_t <item_t*>* inventory_;

  public:  
    player_t ( string name, room_t* current_room );
    string get_name ( );
    void show_inventory ( );
    void take_item ( int num );
    item_t* find_item ( int num );
    void drop_item ( int num ); 
    void change_current_room ( int num );
    void show_current_room ( );
    item_t* fetch_room_item ( int num );

} ;
//-------------------------------------


#endif
