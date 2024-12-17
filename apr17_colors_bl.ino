

#define RLED 6 
#define GLED 5
#define BLED 3 

void setup() {
  Serial2.begin(9600); 
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  if (Serial2.available() > 0) {
    char inChar = Serial2.read();
    handleCommand(inChar);
  }
}

void handleCommand(char command) {
  switch (command) {
    case 'C': 
      setColor(255, 0, 0);//cyan 
      break;
    case 'M': 
      setColor(0, 255, 0);//magenta
      break;
    case 'Y': 
      setColor(0, 0, 255); // yellow
      break;
    case 'R': 
      setColor(0, 255, 255); //red
      break;
    case 'B': 
      setColor(255, 255, 0); // blue
      break;
    case 'G': 
      setColor(255, 0, 255);// green
      break;
    case 'W': 
      setColor(0, 0, 0); //white - when low its on
      break;
    default:
      setColor(255, 255, 255);// off 
      break;
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(RLED, red);
  analogWrite(GLED, green);
  analogWrite(BLED, blue);
}
