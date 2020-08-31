#include <listh.h>
#include <stdio.h>

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

// Implement this
void list_append( List *list, int value ) {
  /* Function to append a new node containing 'value'
   * to the end of List *list. For example,
   * applied to { 5 -> 10 } as
   * list_append( list, 9 ); results in
   * { 5 -> 10 -> 9 }
   */
  List_node node;
  node = *list->front;
  while ( node.next != NULL ) node.next = node.next->next;
  node.next = create_node( value );
  list->length++;
}


// void my_print ( size_t *x ) {
//  printf("x = %lu\n", x);
//   printf("*x = %lu\n", *x);
// }

int main() {
//  size_t a = 16;
//  size_t *pointer = &a;
//  printf("a = %lu\n", a);
//  printf("&a = %lu\n", &a);
//  printf("*&a = %lu\n", *&a);
//  printf("pointer = %lu\n", pointer);
//  printf("*pointer = %lu\n", *pointer);

//  my_print(a);
//  my_print(&a);
//  if (2) printf("2 is True\n");
//  if (1) printf("1 is True\n");
//  if (!0) printf("!0 is True\n");
  return 0;
}
