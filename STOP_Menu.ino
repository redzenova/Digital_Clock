void STOP_Menu() {
  if (Lock_menu_btn != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      clear_display();
      st_state[5] = true;
      Lock_menu_btn = true;
    }
  }


  if (st_state[5] == true) {
    if (digitalRead(btn[3]) == LOW) {
      beep();
      delay(120);
      StopStart = true;
      millis_msec = millis();
    }

    if (digitalRead(btn[2]) == LOW) {
      beep();
      delay(120);
      StopStart = false;
    }

    if (digitalRead(btn[0]) == LOW) {
      beep();
      delay(120);
      S_msec = 0;
      S_sec = 0;
      S_minute = 0;
      clear_display();
    }

    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      clear_display();
      st_state[5] = false;
      Lock_menu_btn = false;
    }

    if (StopStart != false) {
      if (millis() - millis_msec > 1) {
        millis_msec = millis();
        S_msec += 128;
        tone(buzzer, 2300, 20);
        if (S_msec > 1000) {
          beep();
          S_sec++;
          S_msec = 0;
        }
        if (S_sec > 59) {
          tone(buzzer, 1300, 20);
          S_minute++;
          S_sec = 0;
        }
      }
    }
  }
}
