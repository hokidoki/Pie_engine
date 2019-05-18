//디지털 핀
int ENV = 9;
int DIR = 8;
int speaker = 3;


//아날로그 핀
int US = A0;
int PS = A1;

//거리계산 변수

int tm ; // three meter

void pop_strok(){
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, HIGH);  // CW 
}

void push_strok(){
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, LOW);  // CCW 
}


void alert(i){
    tone(speaker,i);
}

void setup()
{
  Serial.begin(9600); 
  
  int i;
  int ultra_sonic = analogRead(US);
  int pressure_sensor = analogRead(PS);
  
  pinMode(speaker, OUTPUT);
  pinMode(ENV, OUTPUT);
  pinMode(DIR, OUTPUT);
 
  //작동여부 확인  
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, HIGH);  // CW 
  
  digitalWrite(ENV, LOW);  // RUN
  digitalWrite(DIR, LOW);  // CCW 

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
  int second=0;
  int speaker_torn=0;
  //모든 센서값 수정 필요
  //거리측정결과 쓰레기가 쌓여서 압축해야할 경우
  if(ultra_sonic > 550){
    //다져주기위해서 앞 뒤로 와야할 필요성 있는것 같다. 추후 확인하자. 
    while(ultra_sonic < 600 || !(pressure_sensor > 60  ) || second > 20 ){
      pop_stroke();
      //실험 후 함수로 만들어도 괜찮을 듯 
      delay(100);
      second = second +1;
    };
    //압축이 충분히 되어 더 이상 압축이 되지 않는 경우 
    if(pressure_sensor >58){
      push_strok();
      while(!(ultra_sonic >600)){
        for(i=33;i<484;i+=3)
        alert(i);
        delay(50);
      }
    }
  }
}
