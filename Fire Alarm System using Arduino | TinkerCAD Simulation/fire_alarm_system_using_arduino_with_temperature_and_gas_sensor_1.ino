#define led 8
#define buz 4

void setup(){
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  float vout;
  vout=analogRead(A1);
  float vout1;
  float temp;
  vout1=(vout/1023)*5000;
  temp=(vout1-500)/10;
 int gasSensor=analogRead(A0);
  if(temp>=80){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  if(temp>=100){
    digitalWrite(buz,HIGH);
  }
  else{
    digitalWrite(buz,LOW);
  }
  Serial.print("in DegreeC=");
   
  Serial.println(temp);
  Serial.print("\t");
  Serial.print("GasSensor=");
  
  Serial.println(gasSensor);
  Serial.println();
  delay(1000);
}
  