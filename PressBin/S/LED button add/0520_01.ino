//디지털 핀
int ENV = 9;
int DIR = 8;
int speaker = 3;
int sw = 10;       // 스위치(SW) 핀 설정
int led = 6;       // LED 핀 설정


//아날로그 핀
int US = A0;
int PS = A1;

//변수
int ultra_sonic;//초음파
int pressure_sensor;//압력
int i;
int state = LOW;      // LED 상태
int reading;          // SW 상태
int previous = LOW;   // SW 이전 상태

long time = 0;        // LED가 ON/OFF 토글된 마지막 시간
long debounce = 100;  // Debounce 타임 설정

void setup()
{
  Serial.begin(9600); 
  ultra_sonic = analogRead(US);
  pressure_sensor= analogRead(PS);
  pinMode(sw, INPUT_PULLUP); // SW 를 설정, 아두이노 풀업저항 사용
  pinMode(led, OUTPUT);      // LED 설정
  pinMode(speaker, OUTPUT);
  pinMode(ENV, OUTPUT);
  pinMode(DIR, OUTPUT);
  /*
  //작동여부 확인  
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, HIGH);  // CW 들어감
  delay(1000);
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, LOW);  // CCW 나옴
  digitalWrite(sw, HIGH);  // CCW 나옴
  //스피커 작동여부 확인 
  for(i=33;i<968;i+=3)
  {
    tone(speaker, i);
    delay(50);
    noTone(speaker);
  }
  */
  Serial.println("start");
}

void loop()
{
  int timer = 0;
  bool full_been = false;
  int push_button= digitalRead(sw);
  ultra_sonic = analogRead(US);//초음파 센서 입력받음
  pressure_sensor= analogRead(PS);//압력 센서 입력받음
  Serial.println(ultra_sonic);
  Serial.println(pressure_sensor);
   Serial.println(push_button);
  
  int second=0;//횟수
  if (ultra_sonic < 64){
    digitalWrite(ENV, LOW);  // RUN
    digitalWrite(DIR, LOW);  // 나옴
  }

  while(timer < 5 && full_been == false){
    Serial.println(ultra_sonic);
    Serial.println(pressure_sensor);
    if((pressure_sensor= analogRead(PS)) > 300){
       full_been = true;
    }
      delay(4000);
      timer++;
    }
   digitalWrite(ENV, LOW);  // RUN
   digitalWrite(DIR, HIGH);  //
   delay(2000);
  if(full_been == true){
    while((push_button= digitalRead(sw)) != false){
      for(i=33;i<968;i+=3)
      {
         tone(speaker, i);
         delay(50);
         noTone(speaker);
      }
      delay(3000);
   }
  }
}
