#ifndef H_ITEM
#define H_ITEM

//----Headers------------------------------------------------------------------
#include <stdio.h>
//-----------------------------------------------------------------------------

//----Classes------------------------------------------------------------------
class item_t
{
  private:
    const char* name_;
    const char* description_;
    bool visible_;
    bool usable_;

  public:  
    item_t ( const char* name_, const char* description_, bool visible_, bool usable_ ); 
    ~item_t ( );
    const char* get_name ( );
    const char* get_description ( );
    bool get_visible ( );
    bool get_usable ( );
    void change_visible ( );
    void change_usable ( );
    void check ( );
} ;
//-----------------------------------------------------------------------------

#endif
