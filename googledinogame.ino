int life=3;
int score=0;
int count;
float l;
float t;
boolean previousstate=LOW;
boolean currentstate=LOW;
boolean flag=0;
boolean cross;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode( 3,OUTPUT);
  pinMode( 4,OUTPUT);
  pinMode( 5,OUTPUT);
  pinMode( 6,OUTPUT);
  pinMode( 7,OUTPUT);
  pinMode( 8,OUTPUT);
pinMode( 9,OUTPUT);
pinMode( 10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);


  digitalWrite(3 ,HIGH);
digitalWrite( 4,LOW);
digitalWrite(5 ,LOW);
digitalWrite( 6,LOW);
digitalWrite( 7,LOW);
digitalWrite( 8,LOW);
digitalWrite( 9,LOW);
digitalWrite( 10,LOW);
  digitalWrite(11,HIGH);

count=3;
}

void loop() {
  // put your main code here, to run repeatedly:
     t=millis();
  

  while(count<=9){
   
 if(( millis()-t)>=500) {
  digitalWrite(count,LOW);
  digitalWrite(count+1,HIGH);
  ++count;
    t=millis();
 }
    currentstate=debounce(previousstate);
if(currentstate==HIGH&&previousstate==LOW){
  l=millis();
    digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
flag=1;}
    if((millis()-l)>=1000&&flag==1){  
  digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      flag=0;
      
    }
    if(count==8&&flag==0){
      life--;
      break;}
    else if(count==8&&flag==1&&cross==0) {score++;cross=1;}
    
    
    
  
  previousstate=currentstate;//update previous state of button.
    
  
    

    
    
  
  }delay(100);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
    digitalWrite(3,HIGH);
  count=3;
  cross=0;
  if(life==0){Serial.println("game over");
              Serial.println("your total score is");
              Serial.println(score);
            }
  while(life==0);
  
}
boolean debounce( boolean prevstate){
  boolean statenow=digitalRead(2);
  if(prevstate!=statenow){
    delay(5);
    statenow=digitalRead(2);
  }
  return statenow;
}
