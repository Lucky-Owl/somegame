#ifndef H_EVENT
#define H_EVENT

//----Headers--------------------------
#include "list.hpp"
#include "item.hpp"
//#include "room.hpp"
//-------------------------------------

//----Classes--------------------------
class event_t
{
  public :
    list_t <item_t *> * usable_state_;
    list_t <item_t *> * visible_state_;
    //list_t <room_t *> available_state_;
};

class item_pair_t
{
  public :
    item_t * first_;
    item_t * second_;
    item_pair_t ( item_t * first, item_t * second )
    {
      first_ = first;
      second_ = second;
    }
};

class event_regestry_t
{
  private :
    list_t <event_t *> * events_;
    list_t <item_pair_t *> * items_;

  public :
    event_regestry_t ( );
    ~event_regestry_t ( );
    void add_event ( event_t * event, item_t * first, item_t * second );
    void activate ( item_t * first, item_t * second );
};
//-------------------------------------


#endif
