void SET_Menu() {
  if (Lock_sub_menu_btn != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[1] = true;
      Lock_menu_btn = true;
    }
  }

  if (st_state[1] == true) {
    Lock_sub_menu_btn = true;
    if (digitalRead(btn[3]) == LOW) {
      beep();
      delay(120);
      if (SUB_MENU == 6) SUB_MENU = 0;
      if (SUB_MENU > 4) SUB_MENU = 0;
      SUB_MENU++;
      clear_display();
    }
  }

  if (SUB_MENU == 1) {
    SetTime();
  }

  if (SUB_MENU == 2) {
    if (st_state[6] != true) {
      if (digitalRead(btn[1]) == LOW) {
        beep();
        delay(120);
        st_state[1] = false;
        st_state[6] = true;
        clear_display();
      }
    }
    if (st_state[6] == true) {
      if (digitalRead(btn[3]) == LOW) {
        beep();
        delay(120);
        if (DATE_SUB_MENU > 3) DATE_SUB_MENU = 0;
        DATE_SUB_MENU++;
        clear_display();
      }

      if (DATE_SUB_MENU == 1) {
        if (digitalRead(btn[2]) == LOW) {
          beep();
          day++;
        }
        if (digitalRead(btn[0]) == LOW) {
          beep();
          day--;
        }
        if ( day > 31 ) day = 1;
        if ( day <  1 ) day = 31;
      }

      if (DATE_SUB_MENU == 2) {
        if (digitalRead(btn[2]) == LOW) {
          beep();
          mon++;
        }
        if (digitalRead(btn[0]) == LOW) {
          beep();
          mon--;
        }
        if ( mon > 12 ) day = 1;
        if ( mon <  1 ) day = 12;
      }

      if (DATE_SUB_MENU == 3) {
        if (digitalRead(btn[2]) == LOW) {
          beep();
          year++;
        }
        if (digitalRead(btn[0]) == LOW) {
          beep();
          year--;
        }
        if ( year > 9999 ) year = 1;
        if ( year <  1 ) day = 9999;
      }

      if (DATE_SUB_MENU == 4) {
        if (digitalRead(btn[1]) == LOW) {
        beep();
        delay(120);
        st_state[6] = false;
        st_state[1] = true;
        DATE_SUB_MENU = 1;
        clear_display();
      }
      }

    }
  }

  if (SUB_MENU == 3) {
    SetLed();
  }

  if (SUB_MENU == 4) {
    SetBuzzer();
  }

  if (SUB_MENU == 5) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      st_state[1] == false;
      Lock_menu_btn = false;
      Lock_sub_menu_btn = false;
      MENU = 1;
      SUB_MENU = 1;
      clear_display();
    }
  }
}
