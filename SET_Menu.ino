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
