#include "ListBuilder.h"
#include "Reverser.h"

int main(int argc, char *argv[]) {

  ListBuilder listBuilder;
  Node *list = listBuilder.build(1, 20);

  Reverser reverser;

  // before reversing
  std::cout << "before:\t";
  list->printList();

  reverser.exec(list);

  // after reversing
  std::cout << "after:\t";
  list->printList();

  // free memory
  delete list;

  return 0;
}
