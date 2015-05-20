#ifndef H_EVENT
#define H_EVENT

//----Headers--------------------------
#include "item.hpp"
#include "room.hpp"
//-------------------------------------

//----Classes--------------------------
class event_t
{
  item_t * used_;
  item_t * affected_;
  item_t * take_state_;
  item_t * visible_state_;
  room_t * room_;
};
//-------------------------------------


#endif