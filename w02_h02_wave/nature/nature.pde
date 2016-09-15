float y=0;

void setup(){
  size(800,800);
  
}

void draw(){
  background(200,150,50);
  //strokeWeight(10);
  for(int i=0; i <20; i++){
    //line(0,400+sin(y)*400,width,400+sin(y)*400);
    noStroke();
    fill(0,100,150,50);
    rect(0,0,width,20*i+sin(y+25*PI/i)*400);
  }
  y+=PI/72;
}