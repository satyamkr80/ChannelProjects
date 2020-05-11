#define motor1_in_1 8
#define motor1_in_2 9

#define motor2_in_1 10
#define motor2_in_2 11

#define horn 3
#define B_light 4
#define H_light 5


char command = 'S';
char prevCommand = 'A';
int velocity=0;

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module.
  
   pinMode(motor1_in_1 , OUTPUT);
   pinMode(motor1_in_2 , OUTPUT);
   pinMode(motor2_in_1 , OUTPUT);
   pinMode(motor2_in_2 , OUTPUT);
   pinMode(B_light , OUTPUT);
   pinMode(H_light , OUTPUT);
   pinMode(horn , OUTPUT);
  // analogWrite(9, 255);
   //analogWrite(10, 255);
   
}

void loop(){
  if(Serial.available() > 0){ 
 
    prevCommand = command;
    command = Serial.read(); 
    Serial.println(command);
    //Change pin mode only if new command is different from previous.   
    if(command!=prevCommand){
      //Serial.println(command);
      switch(command)
      {
      case 'F':  
      
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, HIGH);
        digitalWrite(motor2_in_2, LOW);
        
        break;
      case 'B':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH);
        break;
      case 'L':  
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH);
        break;
      case 'R':
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, HIGH);
        digitalWrite(motor2_in_2, LOW); 
        break;
      case 'S':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);
        break;
        
         case 'V':  
        digitalWrite(horn, HIGH);
        break; 
        
        case 'v':  
        digitalWrite(horn, LOW);
        break; 
        
        case 'W':  //Front ON 
        digitalWrite(H_light, HIGH);
        break;
      case 'w':  //Front OFF
        digitalWrite(H_light, LOW);
        break;

        case 'U':  //Back ON 
        digitalWrite(B_light, HIGH);
        break;
      case 'u':  //Back OFF 
        digitalWrite(B_light, LOW);
        break; 

  /*
  
      case 'I':  //FR  
        yellowCar.ForwardRight_4W(velocity);
        break; 
      case 'J':  //BR  
        yellowCar.BackRight_4W(velocity);
        break;        
      case 'G':  //FL  
        yellowCar.ForwardLeft_4W(velocity);
        break; 
      case 'H':  //BL
        yellowCar.BackLeft_4W(velocity);
        break;
      
      
      case 'D':  //Everything OFF 
        digitalWrite(pinfrontLights, LOW);
        digitalWrite(pinbackLights, LOW);
        yellowCar.Stopped_4W();
        break;   
  */     
      default:  //Get velocity
        if(command=='q'){
         
        }

      }
    }
  }
}
