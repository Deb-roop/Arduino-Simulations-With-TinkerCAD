#define led 9

void setup(){
  
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
}
 void loop(){
 int sensorValue=0;
 sensorValue =analogRead(A0);
 Serial.println(sensorValue);
 analogWrite(led,map(sensorValue,0,1023,0,255));// 0,1023--> ldr value ; 0,255-->led's value will show in PWM 
 delay(100);
               
   }
