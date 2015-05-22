#ifndef H_EVENT
#define H_EVENT

//----Headers--------------------------
#include "item.hpp"
#include "room.hpp"
//-------------------------------------

//----Classes--------------------------
class event_t
{
  public :
    list_t <item_t *> take_state_;
    list_t <item_t *> visible_state_;
    list_t <room_t *> rooms_;
};

class item_pair_t
{
  public :
    item_t * first_;
    item_t * second_;
};

class event_regestry_t
{
  private :
    list_t <event_t *> events_;
    list_t <item_pair_t *> > items_;

  public :
    event_regestry_t ( list_t <event_t *> events, list_t <item_pair_t *> > items );
    ~event_regestry_t ( );
    void activate ( item_t * first, item_t * second );
};
//-------------------------------------


#endif
