#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct List_node_s {
  List_node *next;
  int value;
};

List empty_list( void ) {
  return (List) { .length = 0, .front = NULL };
}


// Allocate memory for a single List_node
List_node* create_node( int value ) {
  List_node *new_node = malloc( sizeof( List_node ) );
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void destroy_node( List *list, List_node *node ) {
  List_node *prev_node;
  List_node *tmp_node;

  // node is beginning of list
  if ( list->front == node ) {
    tmp_node = list->front->next;
    free( list->front );
    list->front = tmp_node;
    if ( list->length == 0 ) {
      printf( "Error: List length less than 0. List has been corrupted.\n" );
      exit( EXIT_FAILURE );
    }
    --list->length;
    return;
  }

  // search for node in list
  prev_node = list->front;
  tmp_node = list->front->next;
  for ( size_t i = 1; i < list->length-1; ++i ) {
    if ( tmp_node == node ) {
      prev_node->next = tmp_node->next;
      free( node );
      --list->length;
      return;
    }
    prev_node = tmp_node;
    tmp_node = tmp_node->next;
  }
}

// Implement this
void list_append( List *list, int value ) {
  /* Function to append a new node containing 'value'
   * to the end of List *list. For example,
   * applied to { 5 -> 10 } as
   * list_append( list, 9 ); results in
   * { 5 -> 10 -> 9 }
   */
  if ( list->front == NULL ) {
    list->front = create_node( value );
  }
  else {
    List_node *p = list->front;
    for( size_t i = 1; i < list->length; ++i, p = p->next );
    p->next = create_node( value );
  }
  ++list->length;
}

// Implement this
void list_insert_before( List *list, int insert, int before ) {
  /* This function should take a pointer to a List *list,
   * a value to insert 'insert', and a value to insert before 'before'.
   * A new node should be inserted directly before the first
   * occurrence of "before" in the current list, like so:
   *
   * Starting with { 0 -> 5 -> 4 -> 5 }, call list_insert_before( list, -1, 5 ):
   * results in { 0 -> -1 -> 5 -> 4 -> 5 }
   *
   * NOTE: if the value 'before' does not exist in 'list', this
   * function should not modify the list or append anywhere.
   */
  if ( list-> front != NULL && list->front->value == before ) {
    List_node *new_node = create_node( insert );
    new_node->next = list->front;
    list->front = new_node;
    ++list->length;
  }
  else {
    List_node *prev = list->front;
    List_node *next = list->front->next;
    while( next != NULL ) {
      if ( next->value == before ) {
        prev->next = create_node( insert );
        prev->next->next = next;
        ++list->length;
        return;
      }
      prev = next;
      next = next->next;
    }
  }
}

void list_delete_from_front( List *list, int value ) {
  List_node *front = list->front;
  while( front != NULL && front->value == value ) {
    list->front = front->next;
    --list->length;
    free( front );
    front = list->front;
  }
}

// Implement this
void list_delete( List *list, int value ) {
  /* Delete all occurrences of the value 'value' in list.
   * For example, starting with { 0 -> 5 -> 4 -> 5 }
   * call list_delete( list, 5 ):
   * results in { 0 -> 4 }
   * If there are no values to delete, the function should
   * do nothing.
   */
  list_delete_from_front( list, value );
  if ( list->front == NULL ) {
    return;
  }

  List_node *prev = list->front;
  List_node *p = list->front->next;

  while( p != NULL ) {
    if( p->value == value ) {
      prev->next = p->next;
      free( p );
      --list->length;
      p = prev->next;
    }
    else {
      prev = p;
      p = p->next;
    }
  }
}

// Implement this
void list_apply( List *list, int (*function_ptr)(int) ) {
  /* Applies the function pointed to by function_ptr
   * to every value at nodes in list 'list'.
   * For example, starting with { 1 -> 2 -> 3 } and
   * a function 
   *
   *     int sq(int x) { return x * x; }
   * 
   * call to list_apply( list, sq );
   * results in { 1 -> 4 -> 9 }
   */
  for ( List_node *p = list->front; p != NULL; p = p->next ) {
    p->value = (*function_ptr)( p->value );
  }
}

int list_reduce( List *list, int (*function_ptr)( int, int ) ) {
  /* Takes an associative function pointed to by function_ptr
   * and returns the result of reducing the list with it.
   * For example, starting with { 1 -> 2 -> 3 } and
   * a function
   *
   *    int plus( int x, int y ) { return x + y; }
   * 
   * list_reduce( list, plus );
   * will return 1 + 2 + 3 = 6.
   * If the provided list contains 0 elements,
   * you should return 0; if the list has only one
   * element, return the value of that element.
   */
  if ( list->front == NULL ) {
    return 0;
  }
  int result = list->front->value;
  for ( List_node *node = list->front->next; node != NULL; node = node->next ) {
    result = (*function_ptr)( result, node->value );
  }
  return result;
}

// Print out a linked list in human-readable form
void list_print( List list ) {
  if( list.front == NULL ) {
    printf( "{}\n" );
  } else {
    printf( "{ " );

    List_node *p = list.front;
    size_t length = list.length;

    while( p->next != NULL && length > 0 ) {
      printf( "%d -> ", p->value );
      p = p->next; --length;
    }
    printf( "%d }\n", p->value );

    if( length != 1 ) {
      printf( "Error: badly formed list.\n" );
      exit( EXIT_FAILURE );
    }
  }
}

// Frees the memory in List *list
void list_clear( List *list ) {
  List_node *front = list->front;
  List_node *next;

  while( front != NULL && list->length > 0 ) {
    next = front->next;
    free( front );
    front = next;
    --list->length;
  }

  if( list->length != 0 ) {
    printf( "Error: failed to clean up list properly.\n" );
    exit( EXIT_FAILURE );
  }
  else {
    list->front = NULL;
  }
}
