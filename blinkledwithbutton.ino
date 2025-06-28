void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT);
pinMode(16,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(4);
if(val==1)
{
  digitalWrite(16,HIGH);
}
else
{
  digitalWrite(16,LOW);
}
}
