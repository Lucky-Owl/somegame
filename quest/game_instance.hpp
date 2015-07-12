#ifndef H_GAME_INSTANCE
#define H_GAME_INSTANCE

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
#include "room.hpp"
#include "event.hpp"
#include <iostream>
using std::string;
//-------------------------------------

//----Classes--------------------------
class game_instance_t
{
  private:
    event_regestry_t* REG_;
//  list_t <item_t*> items_;
//  list_t <room_t*> rooms_;

    string name_;
    room_t* current_room_ ;
    list_t <item_t*>* inventory_;

  public:  
    game_instance_t ( string name, room_t* current_room, event_regestry_t* REG ); // temporary constructor to test interface
//  ~game_instance_t ( );
//  save ( );
    string get_name ( );

    void show_inventory ( );
    void take_item ( int num );
    item_t* find_item ( int num );
    void drop_item ( int num ); 

    void change_current_room ( int num );
    item_t* fetch_room_item ( int num );

    void show_help (); 
    int action ( string turn );
 
} ;
//-------------------------------------


#endif
