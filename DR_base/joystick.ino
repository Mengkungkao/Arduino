void joystick() {


  if (type == 2) {
    ps2x.read_gamepad();
  }
  else { //DualShock Controller
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed
    byte RY_J = ps2x.Analog(PSS_RY);
    byte RX_J = ps2x.Analog(PSS_RX);
    byte LY_J = ps2x.Analog(PSS_LY);
    byte LX_J = ps2x.Analog(PSS_LX);

    if (RY_J < 126 ) {
      Vy_j = map(RY_J , 127, 0, 0, 150);///182 maximum
    }
    if (RY_J > 128) {
      Vy_j = -map(RY_J, 127, 255, 0, 150);
    }
    if ( RY_J == 127 || RY_J == 126 || RY_J == 128 ) {
      Vy_j = 0;
    }
    if (RX_J < 126 ) {
      Vx_j = -map(RX_J , 127, 0, 0, 150);
    }
    if (RX_J > 129) {
      Vx_j = map(RX_J, 127, 255, 0, 150);
    }
    if ( RX_J == 128 || RX_J == 127 || RX_J == 129 ) {
      Vx_j = 0;
    }

    if (LX_J < 126 ) {
      Omega_j = -map(LX_J , 127, 0, 0, 60);
    }
    if (LX_J > 129) {
      Omega_j = map(LX_J, 127, 255, 0, 60);
    }
    if ( LX_J == 128 || LX_J == 127 || LX_J == 129) { // just between 127 and 129
      Omega_j = 0;
    }


    if (RY_J == 127 && RX_J == 128 && LX_J == 128) {
      Vy_j = 0;
      Vx_j = 0;
      Omega_j = 0;
    }

  }

}
