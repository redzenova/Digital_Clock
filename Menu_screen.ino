void arrow() {
  plot(1, 1, 1);
  plot(1, 2, 1);
  plot(1, 3, 1);
  plot(1, 4, 1);
  plot(1, 5, 1);
  plot(2, 2, 1);
  plot(2, 3, 1);
  plot(2, 4, 1);
  plot(3, 3, 1);
}

void score_bar() {
  plot(30, 0, 1);
  plot(30, 1, 1);
  plot(30, 2, 1);
  plot(30, 3, 1);
  plot(30, 4, 1);
  plot(30, 5, 1);
  plot(30, 6, 1);
  plot(30, 7, 1);
}

void screen(String mode) {

  if (mode == "SET") {
    /*=== Set Time Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'S');
    print_tiny_char( 9, 1, 'E');
    print_tiny_char( 13, 1, 'T');
    print_tiny_char( 17, 1, ' ');
    score_bar();
    plot(31, 0, 1);
    plot(31, 1, 1);
  }

  if (mode == "STOP") {
    /*=== Stop Watch Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'S');
    print_tiny_char( 9, 1, 'T');
    print_tiny_char( 13, 1, 'O');
    print_tiny_char( 17, 1, 'P');
    score_bar();
    plot(31, 2, 1);
    plot(31, 3, 1);
  }

  if (mode == "COUNT") {
    /*=== Countdown Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'C');
    print_tiny_char( 9, 1, 'O');
    print_tiny_char( 13, 1, 'U');
    print_tiny_char( 17, 1, 'N');
    print_tiny_char( 21, 1, 'T');
    score_bar();
    plot(31, 4, 1);
    plot(31, 5, 1);
  }

  if (mode == "ALARM") {
    /*=== Alarm Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'A');
    print_tiny_char( 9, 1, 'L');
    print_tiny_char( 13, 1, 'A');
    print_tiny_char( 17, 1, 'R');
    print_tiny_char( 21, 1, 'M');
    score_bar();
    plot(31, 6, 1);
    plot(31, 7, 1);
  }

  if (mode == "EXIT") {
    /*=== EXIT Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'E');
    print_tiny_char( 9, 1, 'X');
    print_tiny_char( 13, 1, 'I');
    print_tiny_char( 17, 1, 'T');
    score_bar();
    plot(31, 0, 1);
    plot(31, 1, 1);
  }

  /*================= Sub Menu Screen =================*/
  if (mode == "SET_Time") {
    /*=== Set->Time Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'T');
    print_tiny_char( 9, 1, 'i');
    print_tiny_char( 13, 1, 'm');
    print_tiny_char( 17, 1, 'e');
    score_bar();
    plot(31, 0, 1);
    plot(31, 1, 1);
  }

  if (mode == "SET_Date") {
    /*=== Set->Date Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'D');
    print_tiny_char( 9, 1, 'a');
    print_tiny_char( 13, 1, 't');
    print_tiny_char( 17, 1, 'e');
    score_bar();
    plot(31, 2, 1);
    plot(31, 3, 1);
  }

  if (mode == "SET_Led") {
    /*=== Set->Led Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'L');
    print_tiny_char( 9, 1, 'e');
    print_tiny_char( 13, 1, 'd');
    score_bar();
    plot(31, 4, 1);
    plot(31, 5, 1);
  }

  if (mode == "SET_Buzz") {
    /*=== Set->Buzzer Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'B');
    print_tiny_char( 9, 1, 'u');
    print_tiny_char( 13, 1, 'z');
    print_tiny_char( 17, 1, 'z');
    print_tiny_char( 21, 1, 'e');
    print_tiny_char( 25, 1, 'r');
    score_bar();
    plot(31, 5, 1);
    plot(31, 6, 1);
  }

  if (mode == "SET_EXIT") {
    /*=== SET_EXIT Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'E');
    print_tiny_char( 9, 1, 'X');
    print_tiny_char( 13, 1, 'I');
    print_tiny_char( 17, 1, 'T');
    score_bar();
    plot(31, 0, 1);
    plot(31, 1, 1);
  }

  if (mode == "SET_Time_HR") {
    /*=== Set->Time->HR Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'H');
    print_tiny_char( 9, 1, 'R');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, hour / 10 + '0' );
    print_tiny_char( 25, 1, hour % 10 + '0');
  }

  if (mode == "SET_Time_MN") {
    /*=== Set->Time->MN Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'M');
    print_tiny_char( 9, 1, 'N');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, minute / 10 + '0');
    print_tiny_char( 25, 1, minute % 10 + '0');
  }

  if (mode == "SET_Time_SEC") {
    /*=== Set->Time->SEC Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'S');
    print_tiny_char( 9, 1, 'E');
    print_tiny_char( 13, 1, 'C');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, second_set / 10 + '0');
    print_tiny_char( 25, 1, second_set % 10 + '0');
  }

  if (mode == "SET_Time_EXIT") {
    /*=== SET_EXIT Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'E');
    print_tiny_char( 9, 1, 'X');
    print_tiny_char( 13, 1, 'I');
    print_tiny_char( 17, 1, 'T');
  }

  if (mode == "SET_LED_VAL") {
    /*=== SET_LED_VAL Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'B');
    print_tiny_char( 9, 1, 'N');
    print_tiny_char( 21, 1, brightness / 10 + '0');
    print_tiny_char( 25, 1, brightness % 10 + '0');
  }

  if (mode == "SET_BUZZER_YES") {
    /*=== SET_BUZZER_YES Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'B');
    print_tiny_char( 9, 1, 'Z');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, 'Y');
    print_tiny_char( 25, 1, 'E');
    print_tiny_char( 29, 1, 'S');
  }

  if (mode == "SET_BUZZER_NO") {
    /*=== SET_BUZZER_NO Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'B');
    print_tiny_char( 9, 1, 'Z');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, ' ');
    print_tiny_char( 25, 1, 'N');
    print_tiny_char( 29, 1, 'O');
  }

  if (mode == "STOPWACTCH") {
    /*=== STOPWACTCH Screen ===*/
    print_tiny_char( 2, 1,  S_minute /10 + '0');
    print_tiny_char( 6, 1,  S_minute %10 + '0');
    plot(10, 5, 1);
    print_tiny_char( 12, 1, S_sec /10 + '0');
    print_tiny_char( 16, 1, S_sec %10 + '0');
    
    print_tiny_char( 21, 3, S_msec /100 + '0');
    print_tiny_char( 25, 3, (S_msec/10) %10 + '0');
    print_tiny_char( 29, 3, S_msec %10 + '0');
  }

  if (mode == "SET_Date_DAY") {
    /*=== Set->Date->DAY Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'D');
    print_tiny_char( 9, 1, 'A');
    print_tiny_char( 13, 1, 'Y');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, day /10 + '0');
    print_tiny_char( 25, 1, day %10 + '0');
  }

  if (mode == "SET_Date_MON") {
    /*=== Set->Date->MON Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'M');
    print_tiny_char( 9, 1, 'O');
    print_tiny_char( 13, 1, 'N');
    print_tiny_char( 17, 1, ':');
    print_tiny_char( 21, 1, mon /10 + '0');
    print_tiny_char( 25, 1, mon %10 + '0');
  }

  if (mode == "SET_Date_YEAR") {
    /*=== Set->Date->YEAR Screen ===*/
    print_tiny_char( 2, 1, 'Y');
    print_tiny_char( 6, 1, 'A');
    print_tiny_char( 10, 1, 'R');
    print_tiny_char( 17, 1, year/1000 +'0');
    print_tiny_char( 21, 1,(year/100)%10 + '0');
    print_tiny_char( 25, 1,(year/10) %10 + '0');
    print_tiny_char( 29, 1, year %10 + '0');
  }

  if (mode == "SET_Date_EXIT") {
    /*=== SET_Date_EXIT Screen ===*/
    arrow();
    print_tiny_char( 5, 1, 'E');
    print_tiny_char( 9, 1, 'X');
    print_tiny_char( 13, 1, 'I');
    print_tiny_char( 17, 1, 'T');
  }
}
