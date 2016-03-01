#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
  int radius=10;
  double theta=0;
  double x;
  double y;
  for (n=0;n<100;n++){
    c.green=c.green-1;
    c.red=c.red+1;
    edges=new_matrix(4,2);
    //Make a square
    add_edge(edges,0,0,0,10,0,0);
    add_edge(edges,0,0,0,0,10,0);
    add_edge(edges,0,10,0,10,10,0);
    add_edge(edges,10,0,0,10,10,0);
    //Scale square so they get steadily bigger
    //scalar_mult((n/10.)+1,edges);
    //Scale it along different axes
    //transformation=make_scale(1.0/((n%7)+1),1.0/((n%13)+1),0);
    // matrix_mult(transformation,edges);
    //free_matrix(transformation);
    //Rotate it along x
    // transformation=make_rotZ((M_PI*2)/10);
    // matrix_mult(transformation,edges);
    //  free_matrix(transformation);
    //Translate it
    x=radius*cos(theta);
    y=radius*sin(theta);
    //Adjust for origin being in lower left
    x+=XRES/2;
    y+=YRES/2;
    transformation=make_translate(x,y,0);
    matrix_mult(transformation,edges);
    print_matrix(edges);
    draw_lines(edges,s,c);
    free_matrix( edges );
    free_matrix(transformation);
    radius+=10;
    theta+=(M_PI/6.0);
  }
  display(s);
  save_extension(s, "lines.png");
}  
