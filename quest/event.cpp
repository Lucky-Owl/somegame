#include "event.hpp"
#include "list.cpp"
#include "item.cpp"
//#include "room.cpp"

event_regestry_t::event_regestry_t ( )
{
  events_ = new list_t <event_t *> ( );
  items_ = new list_t <item_pair_t *> ( );
}

event_regestry_t::~event_regestry_t ( )
{
  delete events_;
  delete items_;
}

void event_regestry_t::add_event ( event_t * event, item_t * first, item_t * second )
{
  events_->append_element ( event );
  item_pair_t * tmp = new item_pair_t ( first, second );
  items_->append_element ( tmp );
}

void event_regestry_t::activate ( item_t * first, item_t * second )
{
  item_pair_t * tmp = new item_pair_t ( first, second );
  int n = items_->get_number_by_element ( tmp );
  printf ( "OK\n" );
  event_t * current_event = events_->get_element ( n );
  for ( int i = 0; i <= current_event->usable_state_->get_len(); i++ )
  {
    current_event->usable_state_->get_element(i)->change_usable();
  }
  for ( int i = 0; i <= current_event->visible_state_->get_len(); i++ )
  {
    current_event->visible_state_->get_element(i)->change_visible();
  }
}

int main ( )
{
  event_regestry_t REG;
  item_t * item1 = new item_t ( "changeble item", "some desc", true, true );
  event_t * event = new event_t ( );
  event->add_usable ( item1 );
  event->add_visible ( item1 );
  item_t * item_to_use = new item_t ( "item to use", "some desc", true, true );
  item_t * item_for_use = new item_t ( "item for use", "some desc", true, true );
  REG.add_event ( event, item_to_use, item_for_use );
  REG.activate ( item_to_use, item_for_use );
}
