void serial_print() {
  if (X < 0 && Y < 0) {
    Serial.print("M1=");
    Serial.print((-1)*M1);
    Serial.print(" ");
    Serial.print("M1_j=");
    Serial.print((-1)*M1_j);
    Serial.print(" ");

    Serial.print("M2=");
    Serial.print(M2);
    Serial.print(" ");
    Serial.print("M2_j=");
    Serial.print(M2_j);
    Serial.print(" ");

    Serial.print("M3=");
    Serial.print((-1)*M3);
    Serial.print(" ");
    Serial.print("M3_j=");
    Serial.print((-1)*M3_j);
    Serial.print(" ");

    Serial.print("M4=");
    Serial.println(M4);
    Serial.print(" ");
    Serial.print("M4_j=");
    Serial.println(M4_j);
    Serial.print(" ");
  }
  else {
    Serial.print("M1=");
    Serial.print(M1);
    Serial.print(" ");
    Serial.print("M1_j=");
    Serial.print(M1_j);
    Serial.print(" ");

    Serial.print("M2=");
    Serial.print(M2);
    Serial.print(" ");
    Serial.print("M2_j=");
    Serial.print(M2_j);
    Serial.print(" ");

    Serial.print("M3=");
    Serial.print(M3);
    Serial.print(" ");
    Serial.print("M3_j=");
    Serial.print(M3_j);
    Serial.print(" ");

    Serial.print("M4=");
    Serial.println(M4);
    Serial.print(" ");
    Serial.print("M4_j=");
    Serial.println(M4_j);
    Serial.print(" ");
  }
}
