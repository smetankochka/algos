const int NUM_EEG = 8;          // Количество каналов ЭЭГ
const int PHOTO_PIN = A8;       // Пин фотодиода
const int COUNTER_PIN = A9;     // Пин счетчика

void setup() {
  Serial.begin(115200);
}

void loop() {
  String dataStr = "";
  
  for(int i = 0; i < NUM_EEG; i++) {
    dataStr += String(analogRead(i)) + ",";
  }
  

  dataStr += String(analogRead(PHOTO_PIN)) + ",";
  dataStr += String(analogRead(COUNTER_PIN));
  
  Serial.println(dataStr);
  delay(1);
}