#include "list.h"
#include <stdio.h>

int sq( int x ) {
  return x * x;
}

int plus( int x, int y ) {
  return x + y;
}

int main(void) {
  int N = 10;
  List list = empty_list();

  for( int i = 1; i <= N; ++i ) {
    list_append( &list, i );
  }

  list_print( list );

  printf( "Deleting 5...\n" );
  list_delete( &list, 5 );
  list_print( list );
  printf( "list length = %ld\n", list.length );

  printf( "Deleting 1...\n" );
  list_delete( &list, 1 );
  list_print( list );
  printf( "list length = %ld\n", list.length );

  printf( "Sum of list ...\n" );
  printf( "%d = 33\n", list_reduce( &list, &plus ) );

  printf( "list_insert_before  5 befoe 6...\n" );
  list_insert_before( &list, 5, 6 );
  list_print( list );

  printf( "Apply sq ...\n" );
  list_apply( &list, &sq );
  list_print( list );

  printf( "list_clear()...\n" );
  list_clear( &list );
  list_print( list );

  return 0;
}
