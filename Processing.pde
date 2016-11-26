import com.leapmotion.leap.*;
import processing.serial.*;
Serial ardu;
Controller controller = new Controller();

byte out[] = new byte[2];


void setup(){
  size( 500, 500 );
 ardu = new Serial(this,"COM9",9600);
 
}

void draw(){
  background(0);
  
  Frame frame = controller.frame(); // controller is a Controller object

Hand hand = frame.hands().frontmost();
Matrix basis = hand.basis();
Vector yBasis = basis.getYBasis();
float yaw = hand.direction().yaw();
Vector handCenter = hand.palmPosition();
  text( round(handCenter.get(1))/10+ " cm", 50, 50 );
  text( frame.fingers().count() + " Fingers", 50, 100 );
  
   out[0] = byte(round(handCenter.get(1))/10);
  
  if(frame.fingers().count()==10){
 out[1] = byte(1); }
 else{
 out[1] = byte(0);}
 
  ardu.write(out);
 println(out);
 
}
