#include "event.hpp"
#include "list.cpp"
#include "item.cpp"
//#include "room.cpp"

event_regestry_t::event_regestry_t ( )
{
  events_ = new list_t <event_t *> ( );
  items_ = new list_t <item_pair_t> ( );
}

event_regestry_t::~event_regestry_t ( )
{
}

void event_regestry_t::add_event ( event_t * event, item_t * first, item_t * second )
{
  events_->append_element ( event );
  item_pair_t * tmp = { first, second };
  items_->append_element ( tmp );
}

void event_regestry_t::activate ( item_t * first, item_t * second )
{
  item_pair_t tmp = { first, second };
  //int n = items_->get_number_by_element ( tmp );
  
}

int main ( )
{
}
