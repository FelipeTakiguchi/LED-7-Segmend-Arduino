int segPins[] = {4, 2, 7, 6, 9, 3, 5, 8 };   // { a b c d e f g . )
int n = 0;
int button = 10;
int reset = 0;

byte segCode[10][8] = {
  { 0, 0, 0, 0, 0, 0, 1, 1},  
  { 1, 0, 0, 1, 1, 1, 1, 1},  
  { 0, 0, 1, 0, 0, 1, 0, 1},  
  { 0, 0, 0, 0, 1, 1, 0, 1},  
  { 1, 0, 0, 1, 1, 0, 0, 1},  
  { 0, 1, 0, 0, 1, 0, 0, 1},  
  { 0, 1, 0, 0, 0, 0, 0, 1},  
  { 0, 0, 0, 1, 1, 1, 1, 1},  
  { 0, 0, 0, 0, 0, 0, 0, 1},  
  { 0, 0, 0, 0, 1, 0, 0, 1} 
  //{ 1, 1, 1, 1, 1, 1, 1, 0}   
};

void displayDigit(int digit)
{
  for (int i=0; i < 8; i++)
  {
    digitalWrite(segPins[i], segCode[digit][i]);
  }
}

void setup()
{
  for (int i=0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  displayDigit(n);
    
  Serial.println(digitalRead(button));
  
  if(digitalRead(button) == LOW and reset == 0){
    n++;
    if(n == 10){
      n = 0;
    }
    reset = 1;
  }
  if(digitalRead(button) == HIGH and reset == 1){
    reset = 0;
  }  
}
