#include "item.hpp"

int main()
{
  item_t item ( "test", "description test", true, false );
  const char* test = item.get_description ( );
  printf ( "%s \n", test );
  item.change_visible ( );
  item.change_usable ( );
  item.check ( );
  return 0;
}
