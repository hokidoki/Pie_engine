//디지털 핀
int ENV = 9;
int DIR = 8;
int speaker = 3;


//아날로그 핀
int US = A0;
int PS = A1;

//변수
int ultra_sonic;//초음파
int pressure_sensor;//압력
int i;
void setup()
{
  Serial.begin(9600); 
  ultra_sonic = analogRead(US);
  pressure_sensor= analogRead(PS);
  
  pinMode(speaker, OUTPUT);
  pinMode(ENV, OUTPUT);
  pinMode(DIR, OUTPUT);
  
  //작동여부 확인  
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, HIGH);  // CW 들어감
  delay(1000);
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, LOW);  // CCW 나옴
  
  //스피커 작동여부 확인 
  for(i=33;i<968;i+=3)
  {
    tone(speaker, i);
    delay(50);
    noTone(speaker);
  }
                       
}

void loop()
{
  ultra_sonic = analogRead(US);//초음파 센서 입력받음
  pressure_sensor= analogRead(PS);//압력 센서 입력받음
  Serial.println(ultra_sonic);
  Serial.println(pressure_sensor);
  int second=0;//횟수
  //모든 센서값 수정 필요
  //거리측정결과 쓰레기가 쌓여서 압축해야할 경우
  if(ultra_sonic <64 && pressure_sensor < 300){
    digitalWrite(ENV, LOW);  // RUN
    digitalWrite(DIR, LOW);  // 나옴
  }else if(( ultra_sonic = analogRead(US))> 74 ){
     digitalWrite(ENV, LOW);  // RUN
      digitalWrite(DIR, HIGH);  //
  }
  if((pressure_sensor= analogRead(PS)) >350){
    digitalWrite(ENV, LOW);  // RUN
      digitalWrite(DIR, HIGH);  //
      while((ultra_sonic = analogRead(US)) < 90){
      for(i=33;i<968;i+=3)
      {
         tone(speaker, i);
         delay(50);
         noTone(speaker);
      }
      delay(1000);
      }
    }
}
