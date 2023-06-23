long time_of_reset;
long time_of_rele;
#define rele_pin 2
#define sveto_pin 3
#define ti_of_reset 42000
#define ti_reset_rel 6000
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
rele_active();
}

void loop() {
  if (millis() - time_of_reset >= ti_of_reset) asm volatile("jmp 0x00");
  // put your main code here, to run repeatedly:

}
void rele_reset(){
  if (millis()- time_of_rele >= ti_reset_rel){
    digitalWrite(rele_pin,LOW);
    Serial.println("off");
    return;
  }
  else{
    digitalWrite(rele_pin,HIGH);
    Serial.println("on");
    return rele_reset();
  }
}
void rele_active(){
  time_of_rele = millis();
  rele_reset();
}
