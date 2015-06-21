#ifndef H_ITEM
#define H_ITEM

//----Headers------------------------------------------------------------------
#include <iostream>
using std::string; 
//-----------------------------------------------------------------------------

//----Classes------------------------------------------------------------------
class item_t
{
  private:
    string name_;
    string description_;
    bool visible_;
    bool usable_;

  public:  
    item_t ( string name_, string description_, bool visible_, bool usable_ ); 
    ~item_t ( );
    string get_name ( );
    string get_description ( );
    bool get_visible ( );
    bool get_usable ( );
    void change_visible ( );
    void change_usable ( );
    void check ( );
} ;
//-----------------------------------------------------------------------------

#endif
