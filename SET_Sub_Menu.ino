void SetTime() {
  if (st_state[2] != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[1] = false;
      st_state[2] = true;
      clear_display();
    }
  }

  if (st_state[2] == true) {
    save = false;
    if (digitalRead(btn[3]) == LOW) {
      beep();
      delay(120);
      if (SET_SUB_MENU > 3) SET_SUB_MENU = 0;
      SET_SUB_MENU++;
      clear_display();
    }

    if (SET_SUB_MENU == 1) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        hour++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        hour--;
      }
      if ( hour > 23 ) hour = 0;
      if ( hour <  0 ) hour = 23;
    }

    if (SET_SUB_MENU == 2) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        minute++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        minute--;
      }
      if ( minute > 59 ) minute = 0;
      if ( minute <  0 ) minute = 59;
    }

    if (SET_SUB_MENU == 3) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        second_set++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        second_set--;
      }
      if ( second_set > 59 ) second_set = 0;
      if ( second_set <  0 ) second_set = 59;
    }

    if (SET_SUB_MENU == 4) {
      if (digitalRead(btn[1]) == LOW) {
        beep();
        delay(120);
        save = true;
        st_state[2] = false;
        st_state[1] = true;
        SET_SUB_MENU = 1;
        clear_display();
      }
    }
  }
}


void SetLed() {
  if (st_state[3] != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[1] = false;
      st_state[3] = true;
      clear_display();
    }
  }
  if (st_state[3] == true) {
    if (digitalRead(btn[2]) == LOW) {
      beep();
      brightness++;
    }
    if (digitalRead(btn[0]) == LOW) {
      beep();
      brightness--;
    }
    if ( brightness > 16 ) brightness = 0;
    if ( brightness <  0 ) brightness = 16;
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[3] = false;
      st_state[1] = true;
      SUB_MENU = 3;
      clear_display();
    }
  }
}

void SetBuzzer() {
  if (st_state[4] != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[1] = false;
      st_state[4] = true;
      clear_display();
    }
  }
  if (st_state[4] == true) {

    if (digitalRead(btn[2]) == LOW) {
      clear_display();
      beep();
      no_beep = false;
    }

    if (digitalRead(btn[0]) == LOW) {
      clear_display();
      beep();
      no_beep = true;
    }

    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[4] = false;
      st_state[1] = true;
      SUB_MENU = 4;
      clear_display();
    }
  }
}
