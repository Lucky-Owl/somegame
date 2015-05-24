#ifndef H_PLAYER
#define H_PLAYER

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
#include <stdio.h>
//-------------------------------------

//----Classes--------------------------
class player_t
{
  private:
    const char* name_;
    list_t <item_t*>* inventory_;

  public:  
    player_t ( const char* name );
    void take_item ( );
    void drop_item ( );
    void show_inventory ( );
} ;
//-------------------------------------


#endif
