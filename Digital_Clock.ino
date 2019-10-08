/*====================================================
            Digital Clock with DotMatrix LED
  ===================================================== */

  
/*===================  Include Lib ====================*/
  #include "LedControl.h"
  #include "FontLEDClock.h"

/*=================  Define Varible ===================*/
  
  uint8_t btn[4] = {4,5,6,7}; 
  uint8_t intensity = 8;
  int8_t hour  = 20,
          minute = 45, 
          second = 0,
          second_set = 0;

  bool save = false ;        
  uint8_t conf_state = 1;
  
  unsigned long delaytime=50; 
  
  LedControl lc = LedControl(11,13,10,4);

/*=================  Setup Funcetion ===================*/
void setup() {
  Serial.begin(9600);
  for(int i=0;i<4;i++){
      pinMode(btn[i], INPUT_PULLUP);
  }
  
  noInterrupts();           /* disable all interrupts             */
  TCCR1A  = 0;
  TCCR1B  = 0;
  TCNT1   = 3036;           /* preload timer 65536-16MHz/256/1Hz  */
  TCCR1B |= (1 << CS12);    /* 256 prescaler                      */
  TIMSK1 |= (1 << TOIE1);   /* enable timer overflow interrupt    */
  interrupts();
  
  int devices=lc.getDeviceCount();  
  for(int address=0;address<devices;address++) {
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
  clocks();
}

ISR(TIMER1_OVF_vect){
  TCNT1 = 3036;
  second = 0;
  second++;          
  if(save == true){
    second_set += second;
    if (second_set > 59) {
      second_set = 0; minute++;    
    }
    if (minute > 59) {
      minute = 0; hour++;
    }
    if (hour > 23) {
      hour = 0;
    }
  }
}

void loop() {
  if(digitalRead(btn[3]) == LOW){
      delay(100);
        save = false;
        conf_state++;
        if(conf_state > 3) conf_state = 1;
  } 
  configure();
  if(save == true){
    clocks();
  }
  delay(100);
}


void plot (uint8_t x, uint8_t y, uint8_t value) {
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}

  if (value == 1) {
    lc.setLed(address, y, x, true);
  } else {
    lc.setLed(address, y, x, false);
  }
}


void clear_display() {
  for (uint8_t address = 0; address < 4; address++) {
    lc.clearDisplay(address);
  }
}

void print_tiny_char(uint8_t x, uint8_t y, char c)
{
  uint8_t dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') )  c &= 0x1F;              /* A-Z maps to 1-26  */
  else if (c >= '0' && c <= '9')                        c  = (c - '0') + 32;
  else if (c == ' ' )                                   c  =  0;                /* space             */
  else if (c == '.' )                                   c  = 27;                /* full stop         */
  else if (c == ':' )                                   c  = 28;                /* colon             */
  else if (c == '\'')                                   c  = 29;                /* single quote mark */
  else if (c == '!' )                                   c  = 30;                /* single quote mark */
  else if (c == '?' )                                   c  = 31;                /* question mark     */

  for (uint8_t col = 0; col < 3; col++)
  {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (uint8_t row = 0; row < 5; row++)
    {
      if (dots & (16 >> row))     plot(x + col, y + row, 1);
      else                      plot(x + col, y + row, 0);
    }
  }
}

void clocks()
{
  
  print_tiny_char( 2, 1,  hour / 10 + '0'); //print hour
  print_tiny_char( 6, 1,  hour % 10 + '0');
  print_tiny_char(12, 1, minute / 10 + '0'); //print minute
  print_tiny_char(16, 1, minute % 10 + '0');
  print_tiny_char(22, 1, second_set / 10 + '0'); //print second
  print_tiny_char(26, 1, second_set % 10 + '0');

  // blink : for each minute
  if (second == 0)
  {
    plot(10, 2, 0);
    plot(10, 4, 0);
    plot(20, 2, 0);
    plot(20, 4, 0);
  }
  else
  {
    plot(10, 2, 1);
    plot(10, 4, 1);
    plot(20, 2, 1);
    plot(20, 4, 1);
  }
}

void configure(){    
    if(conf_state == 1){
        if(digitalRead(btn[2]) == LOW) hour++;
        if(digitalRead(btn[0]) == LOW) hour--;
        if( hour > 23 ) hour = 0;
        if( hour <  0 ) hour = 23;
        print_tiny_char( 2, 1,  hour / 10 + '0');
        print_tiny_char( 6, 1,  hour % 10 + '0');
      }
    if(conf_state == 2){
        if(digitalRead(btn[2]) == LOW) minute++;
        if(digitalRead(btn[0]) == LOW) minute--;
        if( minute > 59 ) minute = 0;
        if( minute <  0 ) minute = 59;
        print_tiny_char(12, 1, minute / 10 + '0');
        print_tiny_char(16, 1, minute % 10 + '0');
      }
    if(conf_state == 3){
        if(digitalRead(btn[2]) == LOW) second_set++;
        if(digitalRead(btn[0]) == LOW) second_set--;
        if( second_set > 59 ) second_set = 0;
        if( second_set <  0 ) second_set = 59;
        print_tiny_char(22, 1, second_set / 10 + '0');
        print_tiny_char(26, 1, second_set % 10 + '0');
      }
    if(digitalRead(btn[1]) == LOW){
      delay(100);
        save = true;
      }
     Serial.print(hour);
     Serial.print(":");
     Serial.print(minute);
     Serial.print(":");
     Serial.print(second_set); 
     Serial.print("  msec:");
     Serial.println(millis());   
}
