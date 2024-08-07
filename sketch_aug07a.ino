
const int trigger1 = 2;
const int echo1 = 3;
const int trigger2 = 4;
const int echo2 = 5;
const int trigger3 = 6;
const int echo3 = 7;
const int trigger4 = 8;
const int echo4 = 9;
const int buzz = 11;

int getio,setd=100;
int ON_TIME=1000;
long duration;
int distance,TEMP_DIST;

void setup() {
  Serial.begin(9600);
  pinMode(trigger1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trigger2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trigger3,OUTPUT);
  pinMode(echo3,INPUT);
  pinMode(trigger4,OUTPUT);
  pinMode(echo4,INPUT);
  
  pinMode(buzz,OUTPUT);
  Serial.println( "WELCOME " );
  digitalWrite(buzz, LOW);
  getio=1;

}
void loop() {
  dist();
  if(distance<setd)
  {
    Serial.println( distance );
    Serial.println( "Object Detected" );
    digitalWrite(buzz, HIGH);
    getio=0;
  } 
   while(distance<setd)
   {
      dist();
  }
  
  if(getio==0){
    delay(ON_TIME);
    digitalWrite(buzz, LOW);
    getio=1;
  }
  Serial.println( "No Object Detected" );
 

}

int dist(){
// Clears the trigPin
digitalWrite(trigger1, LOW);
 delayMicroseconds(2);           
 digitalWrite(trigger1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger1, LOW);   
 duration = pulseIn(echo1, HIGH);
 distance= duration;    
delay(100);
 digitalWrite(trigger2, LOW);
 delayMicroseconds(2);            
 digitalWrite(trigger2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger2, LOW);    
 duration = pulseIn(echo2, HIGH);
 TEMP_DIST= duration;   
 if(distance > TEMP_DIST)distance = TEMP_DIST;
delay(100);
 digitalWrite(trigger3, LOW);
 delayMicroseconds(2);            
 digitalWrite(trigger3, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger3, LOW);    
 duration = pulseIn(echo3, HIGH);
 TEMP_DIST= duration;    
 if(distance > TEMP_DIST)distance = TEMP_DIST;
 delay(100);

 digitalWrite(trigger4, LOW);
 delayMicroseconds(2);            // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigger4, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger4, LOW);    // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echo4, HIGH);// Calculating the distance
 TEMP_DIST= duration;            // Prints the distance on the Serial Monitor
 if(distance > TEMP_DIST)distance = TEMP_DIST;

 distance = distance*0.01724;   //1km in 2.9s=2900ms so 1m=2.9ms and 1cm=29ms 
                                //true and for so devd by 2
                                //distanc=(duration/29)/2=duration x 0.01724
 Serial.print("Distance: ");
 Serial.println(distance);


}
