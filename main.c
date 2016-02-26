#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  add_point(edges,3,6,12);
  print_matrix(edges);
  add_edge(edges,10,15,30,150,200,10);
  print_matrix(edges);
  //transform = new_matrix(4, 4);

  
  //free_matrix( transform );
  free_matrix( edges );
}  
