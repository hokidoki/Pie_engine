#define C 262 // �� 
#define C2 131
#define D 147 // �� 
#define D# 311
#define E 330 // �� 
#define E2 165
#define G# 196 // �� 
#define A 220 // �� 
#define B 247 // �� 

int speaker = 9;
int tempo=200;
int notes[18]={E,D#,E,D#,E,B,D,E,A,C2,E2,A,B,E2,G#,B,C,E2};

void setup(){
	pinMode(speaker,OUTPUT);
}

void loop(){
	for(int i=0;i<9;i++){
		tone(speaker,notes[i],tempo);
		delay(300);
	}
	delay(300);
	
	for(int i=9;i<13;i++){
		tone(speaker,notes[i],tempo);
		delay(300;)
	}
	delay(300);
	
	for(int i=13;i<18;i++){
		tone(speaker,notes[i],tempo);
		delay(300;)
	}
	delay(300);
}
