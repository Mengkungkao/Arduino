// from distance X Y to Vx Vy

void adjust_position_base() {
  X = X_base - X_from_Rotary;
  Y = Y_base - Y_from_Rotary ;
}

void position_base() {
  if (X > 0) {
    if (X_from_Rotary >= X_base) {
      X = 0;
    }
  }

  if (X < 0) {
    if (X_from_Rotary <= X_base) {
      X = 0;
    }
  }

  if (Y > 0) {
    if (Y_from_Rotary >= Y_base) {
      Y = 0;
    }
  }

  if (Y < 0) {
    if (Y_from_Rotary <= Y_base) {
      Y = 0;
    }
  }
}


void quadrant_base() {
  if (X == Y && X != 0 && Y != 0) {
    Vx = 100;
    Vy = 100;
  }

  if (X > Y) {
    if (Y < 0 && X == 0) {
      Vx = 0;
      Vy = -100;
    }
    else {
      Vx = 100;
      Vy = Y * 100 / X;
    }
  }
  if (X < Y) {
    if (X < 0 && Y == 0) {
      Vy = 0;
      Vx = -100;
    }
    else {
      Vy = 100;
      Vx = X * 100 / Y;
    }
  }


  if (X == 0 && Y == 0) {
    Vx = 0;
    Vy = 0;
  }
}
