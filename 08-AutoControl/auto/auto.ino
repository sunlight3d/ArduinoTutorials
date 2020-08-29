void setupMotors(int input1, int input2,int input3, int input4) {
	pinMode(input1, OUTPUT);
	pinMode(input2, OUTPUT);
	pinMode(input3, OUTPUT);
	pinMode(input4, OUTPUT);
}
void goForward(
	int input1, 
	int input2,
	int enableA,
	int speedA,
	
	int input3, 
	int input4,
	int enableB,
	int speedB		
	) {
	digitalWrite(input1, LOW);
	digitalWrite(input2, HIGH);

	digitalWrite(input3, LOW);
	digitalWrite(input4, HIGH);	

	analogWrite(enableA, speedA);
	analogWrite(enableB, speedB);
}
void stop() {
	digitalWrite(input1, LOW);
	digitalWrite(input2, LOW);
	digitalWrite(input3, LOW);
	digitalWrite(input4, LOW);
}
void goForward(
	int input1, 
	int input2,
	int enableA,
	int speedA,
	
	int input3, 
	int input4,
	int enableB,
	int speedB //0->255		
	) {
	digitalWrite(input1, HIGH);
	digitalWrite(input2, LOW);

	digitalWrite(input3, HIGH);
	digitalWrite(input4, LOW);	

	analogWrite(enableA, speedA);
	analogWrite(enableB, speedB);
}
#define enableA 9
#define in1 4
#define in2 5

#define enableB 10
#define in3 6
#define in4 7

void setup() {
  setupMotors()

}

void loop() {
  goForward(in1, in2, enableA, 255, in3, in4,enableB, 255);
  //Re trai
  goForward(in1, in2, enableA, 255, in3, in4,enableB, 200);
}
