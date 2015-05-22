#ifndef H_ITEM
#define H_ITEM

//----Classes--------------------------
class item_t
{
  private:
    const char* name;
    int visible;
    int usable;

  public:  
    item_t ( const char* name, int visible, int usable);
} ;
//-------------------------------------


#endif
