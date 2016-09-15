float h = PI;
float w = PI;
float r = 10;
float x = 0;
float y = 0;

void setup(){
  size(800,800);
  background(220,120,160);
  
}

void draw(){
  //background(0);
  fill(255,50);
  noStroke();
  //strokeWeight(3);
  //stroke(255,100);
  ellipse(sin(x)*r+width/2,cos(y)*r+height/2,60*sin(w),60*cos(h));
  r+=0.2;
  w+= PI/72;
  h+= PI/90;
  x+= PI/42;
  y+= PI/58; //use GUI
  
  //println(x);
}