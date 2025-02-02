char time_arr[3600];

char rand_turn_arr[] = {2, 1, 3, 3, 1, 2, 1, 3, 1, 2, 3, 2, 3, 1, 2, 1, 3, 2, 1, 3, 2, 3, 1, 3, 2, 1, 1, 3, 2, 1, 3, 2, 3, 1, 2, 1, 3, 2, 3, 1, 1, 2, 3, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 1, 2, 3, 1, 2, 3, 1, 2, 1, 3, 1, 3, 2, 3, 1, 2, 3, 1, 2, 1, 3, 3, 1, 2, 3, 1, 3, 1, 2, 2, 1, 3, 1, 3, 2, 1, 3, 2, 3, 1, 2, 3, 1, 3, 2, 1, 2, 1, 3, 2, 1};

char add_colour(char frame, color colour) {
  if (colour == red) { //red stored as 11
    frame += 192;
  }
  else if (colour == blue) {
    frame += 128;
  }
  else if (colour == green) {
    frame += 64;
  }
  return frame;
}

color get_colour(char frame) {
  if (frame / 128) {
    if (frame /64 % 2) return red;
    else return blue;
  }
  if (frame /64 % 2) return green;
  else return error;
}

turn turn_type(char frame) {
  if (frame /32 %2) {
    if (frame /16 %2)return oneeighty;
    return left;
  }
  if (frame /16 %2) return right;
  return straight;
}

char add_turn_type(char frame, turn turn) {
  if (turn == left) { //red stored as 11
    frame += 32;
  }
  else if (turn == right) {
    frame += 16;
  }
  else if (turn == oneeighty) {
    frame += 48;
  }
  //straight remains 0
  return frame;
}

int ret_drive_time(char frame) {
  int sections = frame % 16;
  return sections * 50;
}

char add_drive_time(char frame, int time) {
  int pixelized = time + 50;
  frame += pixelized / 50;
  return frame;
}

// drive();
// unsigned long init_time = millis();
// while(getDistance() < MIN_SONIC_DISTANCE || millis() - init_time < 750);
// stop();
// unsigned long fin_time = millis();
// color cur_col= getColor();
// float distance = getDistance();
// char node = 0;
// if (distance < MIN_SONIC_DISTANCE) {

// }