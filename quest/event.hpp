#ifndef H_EVENT
#define H_EVENT

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
#include "room.hpp"
//-------------------------------------

//----Classes--------------------------
class event_t
{
  public :
    list_t <item_t *> * usable_state_;
    list_t <item_t *> * visible_state_;
    list_t <room_t *> available_state_;
    event_t ( )
    {
      usable_state_ = new list_t <item_t *> ();
      visible_state_ = new list_t <item_t *> ();
    }
    void add_usable ( item_t * item )
    {
      usable_state_->append_element ( item );
    }
    void add_visible ( item_t * item )
    {
      visible_state_->append_element ( item );
    }
};

class event_regestry_t
{
  private :
    list_t <event_t *> * events_;
    list_t <item_t *> * items_to_use_;
    list_t <item_t *> * items_for_use_;

  public :
    event_regestry_t ( );
    ~event_regestry_t ( );
    void add_event ( event_t * event, item_t * first, item_t * second );
    void activate ( item_t * first, item_t * second );
};
//-------------------------------------


#endif
