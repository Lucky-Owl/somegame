#include "event.hpp"

event_regestry_t::event_regestry_t ( )
{
  events_ = new list_t <event_t *> ( );
  items_to_use_ = new list_t <item_t *> ( );
  items_for_use_ = new list_t <item_t *> ( );
}

event_regestry_t::~event_regestry_t ( )
{
  delete events_;
  delete items_to_use_;
  delete items_for_use_;
}

void event_regestry_t::add_event ( event_t * event, item_t * first, item_t * second )
{
  events_->append_element ( event );
  items_to_use_->append_element ( first );
  items_for_use_->append_element ( second );
}

void event_regestry_t::activate ( item_t * first, item_t * second )
{
  int n = 0;
  list_t <int> first_items;
  items_to_use_->get_number_by_element ( first, &first_items );
  bool done = false;
  bool check = true;
  for ( int i = 0;( ( i <= first_items.get_len ( ) ) && ( ! ( done ) ) ); i++ )
  {
    n = first_items.get_element ( i );
    if ( items_for_use_->get_element ( n ) == second )
    {
      done = true;
      check = false;
    }
  }
  if ( check )
    assert ( NULL );
  event_t * current_event = events_->get_element ( n );
  for ( int i = 0; i <= current_event->usable_state_->get_len(); i++ )
  {
    current_event->usable_state_->get_element(i)->change_usable();
  }
  for ( int i = 0; i <= current_event->visible_state_->get_len(); i++ )
  {
    current_event->visible_state_->get_element(i)->change_visible();
  }
  for ( int i = 0; i <= current_event->available_state_->get_len(); i++ )
  {
    current_event->available_state_->get_element(i)->change_available();
  }
}
