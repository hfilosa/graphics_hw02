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
  struct matrix *m0;

  edges = new_matrix(4, 4);
  add_point(edges,3,6,12);
  print_matrix(edges);
  add_edge(edges,10,15,30,150,200,10);
  print_matrix(edges);
  add_edge(edges,9,9,3,1,2,300);
  print_matrix(edges);
  scalar_mult(2,edges);
  print_matrix(edges);
  m0=new_matrix(4,4);
  add_edge(m0,10,15,30,150,200,10);
  printf("M0 matrix. m0 * edges:\n\n");
  print_matrix(m0);
  matrix_mult(m0,edges);
  print_matrix(edges);
  //ident(edges);
  //print_matrix(edges);
  //transform = new_matrix(4, 4);

  
  //free_matrix( transform );
  free_matrix( edges );
  free_matrix(m0);
}  
