#include "player.hpp"

player_t::player_t ( const char* name )
{
  name_ = name;
  inventory_ = new list_t <item_t*> ( );
}

void player_t::take_item ( item_t* item )
{
  inventory_ -> append_element ( item );
}

void player_t::drop_item ( item_t* item)
{
   inventory_ -> delete_element_by_value ( item );
}

void player_t::show_inventory ( )
{
  printf ( "there are %d items in your inventory : \n", ((inventory_ -> get_len())+1));
  for (int i = 0; i<=(inventory_ -> get_len()); i++)
  {
    item_t* curr_elem = inventory_ ->  get_element(i);
    printf("%s\n", curr_elem -> get_name());
  }
}
