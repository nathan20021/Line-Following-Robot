#define rights A5// Define a variable called "rights" to store the analog pin of the right sensor
#define lefts A0 // Define a variable called "lefts" to store the analog pin of the left sensor
int greenled = 11; // Create a variable called 'greenled' to store the pin of the green led
int redled = 6; // Create a variable called 'redled' to store the the red led pin
int button = 4 ; // Create a variable called 'button' to store the input of the push button
int mBL = 8; //Create a variable called 'mBL' to store the pin of the back left motor
int mBR = 9;//Create a variable called 'mBR' to store the pin of the back right motor
int mFL = 7;//Create a variable called 'mFL' to store the pin of the front left motor
int mFR = 10;//Create a variable called 'mFR' to store the pin of the front right motor
int x = 0;//Create "x" as a variable to store the value of the black line counter
bool a;//Set "
int num = 8;// Create a variable called "num" to store the number of the double black line 
int wait = 2000;//Create a variable to store the wait time
int white = 600;


void reads(){//Create a sub-routine to read the both of the sensor 
  int varleft = analogRead(lefts);
  int varright = analogRead(rights);
  Serial.print("LEFT is: "); 
  Serial.print(varleft);
  Serial.print("     ");
  Serial.print("RIGHT is: ");
  Serial.print(varright);
  Serial.print("         ");
}
void turnaround(){//Create a sub-routine to make the robot turn 180 degrees
  digitalWrite(mFR , HIGH);//Open the front right motor on
  delay(wait);//delay for a wait time
  Serial.println("         TURN AROUND");
}
void stopm(){//Create a sub-routine to basicly turn off everything
  digitalWrite(mFL, LOW);
  digitalWrite(mFR, LOW);
  digitalWrite(mBL, LOW);
  digitalWrite(mBR, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(redled, LOW);
  Serial.println("             ALL OFF");
}
  
void forward(){//Create a sub-routine to make the robot to go forward
  digitalWrite(mFR, HIGH);
  digitalWrite(mFL, HIGH);
  Serial.println("          FORWARD");
  delay(30);
}
void turnleft(){
  digitalWrite(mFL, HIGH);
  digitalWrite(mBR, HIGH);
  Serial.println("          TURNING LEFT");
  delay(30);
}
void turnright(){
  digitalWrite(mFR, HIGH);
  digitalWrite(mBL, HIGH);
  Serial.println("          TURNING RIGHT");
  delay(30);
}
void setup() {
  pinMode(redled,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}
void loop() {
do{
  a = 1;
  int var = digitalRead(button);
  Serial.print("button is: ");
  Serial.print(var);
  Serial.println("");
  digitalWrite(greenled, HIGH);
  var = digitalRead(button);
    if(var == LOW){
    a = 0;
 }
}while(a == 1);
while (a == 0){
  reads();
  Serial.print("a is: ");
  Serial.print(a);
  Serial.println("");
  if ((analogRead(lefts)<=white) and (!analogRead(rights)<=white)){ // right sensor detects black
      stopm();
      turnright();
  }
  if ((!analogRead(lefts)<=white) and (analogRead(rights)<=white)){ //left sensor detect black
      stopm();
      reads();
      turnleft();
  }
  if((!analogRead(lefts)<=white) and (!analogRead(rights)<=white)){ //double black line
      stopm();
      reads();
      delay(300);
      x++;
      digitalWrite(mFR, HIGH);
      digitalWrite(mFL, HIGH);
      delay(500);
      if (x == 4){
        stopm();
        turnaround();
        }
      if (x == num){
        stopm();
        Serial.println("STOP.....");
        delay(100000);
        }
   }
      if ((analogRead(lefts)<=white) and (analogRead(rights)<=white)){
        stopm();
        forward();
      }
   delay(500);
 }
}
