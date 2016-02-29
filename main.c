#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  screen s;
  color c;
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  clear_screen(s);
  struct matrix *edges;
  struct matrix *transformation;
  //Made too small to prove I can add columns
  edges=new_matrix(4,2);
  //A loop to make 100 squares and shift em and stuff
  int n;
  for (n=0;n<100;n++){
    edges=new_matrix(4,2);
    //Make a square
    add_edge(edges,0,0,0,10,0,0);
    add_edge(edges,0,0,0,0,10,0);
    add_edge(edges,0,10,0,10,10,0);
    add_edge(edges,10,0,0,10,10,0);
    //Scale square
    scalar_mult((n/3)+1,edges);
    //Scale it along different axes
    //Rotate it
   
    //Translate it
    transformation=make_translate(n*2,n*2,0);
    matrix_mult(transformation,edges);
    draw_lines(edges,s,c);
    free_matrix( edges );
    free_matrix(transformation);
  }
  free_matrix( edges );
  display(s);
  save_extension(s, "lines.png");
}  
