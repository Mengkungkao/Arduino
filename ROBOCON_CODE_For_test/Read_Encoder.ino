void readEncoder(){
    if ( millis() - encoder.last_time_1>1000){
    encoder.encoder_counter_1 = encoder.count_1 - encoder.last_count_1;
    rpm.motor_1 = encoder.encoder_counter_1/540;
    encoder.last_count_1 = encoder.count_1;
    encoder.last_time_1= millis();
  }
    if ( millis() - encoder.last_time_2>1000){
    encoder.encoder_counter_2 = encoder.count_2 - encoder.last_count_2;
    rpm.motor_2 = encoder.encoder_counter_2/540;
    encoder.last_count_2 = encoder.count_2;
    encoder.last_time_2= millis();
  }
    if ( millis() - encoder.last_time_3>1000){
    encoder.encoder_counter_3 = encoder.count_3 - encoder.last_count_3;
    rpm.motor_3 = encoder.encoder_counter_3/540;
    encoder.last_count_3 = encoder.count_3;
    encoder.last_time_3= millis();
  }
    if ( millis() - encoder.last_time_4>1000){
    encoder.encoder_counter_4 = encoder.count_4 - encoder.last_count_4;
    rpm.motor_4 = encoder.encoder_counter_4/540;
    encoder.last_count_4 = encoder.count_4;
    encoder.last_time_4= millis();
  }
}
