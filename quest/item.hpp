#ifndef H_ITEM
#define H_ITEM

//----Classes--------------------------
class item_t
{
  private:
    const char* name_;
    bool visible_;
    bool usable_;

  public:  
    item_t ( const char* name_, bool visible_, bool usable_ ); 
    void change_visible ( bool visible_ );
    void change_usable ( bool usable_ );
    void check ( const char* name_, bool visible_, bool usable_ );

} ;
//-------------------------------------


#endif
