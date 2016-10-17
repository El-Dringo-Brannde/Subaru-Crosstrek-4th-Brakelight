  const int fourth_left_brake = 13; //led_fouth_left_brake
  const int fourth_right_brake = 12; //led_fouth_right_brake
 	const int fourth_left_turn = 11; //led_fouth_left_turn
	const int fourth_right_turn = 10; //led_fouth_right_turn 

	const int Left_turn = A0;//input from left turn signal
	const int Right_turn = A1;//input from Right turn signal
	const int Brake_light = A2;//input from brake signal


void setup(){
  Serial.begin(9600);
  pinMode(Brake_light,INPUT);
  pinMode(Left_turn, INPUT);
  pinMode(Right_turn, INPUT);
  pinMode(fourth_left_brake, OUTPUT);
  pinMode(fourth_left_turn, OUTPUT);
  pinMode(fourth_right_brake,OUTPUT);
  pinMode(fourth_right_turn, OUTPUT);

}

  int count = 0;
 // Loop for brake lights
void loop() {
  int Brake_Value = 0, Right_turn_val = 0, Left_turn_val = 0; 
//  Brake_Value = digitalRead(Brake_light);
  Right_turn_val = digitalRead(Right_turn);
  Left_turn_val = digitalRead(Left_turn);
  if (Right_turn_val == HIGH && Left_turn_val == HIGH){
    while (Right_turn_val == HIGH && Left_turn_val == HIGH){
        Right_turn_val = digitalRead(Right_turn);
		Left_turn_val = digitalRead(Left_turn);
      if (Right_turn_val != HIGH && Left_turn_val != HIGH)
        break; 
      	digitalWrite(fourth_left_brake, HIGH);
      	digitalWrite(fourth_right_brake, HIGH);
      	delay(500);
      	digitalWrite(fourth_left_brake, LOW);
      	digitalWrite(fourth_right_brake, LOW);
      	digitalWrite(fourth_left_turn, HIGH);
      	digitalWrite(fourth_right_turn, HIGH);
      	delay(500);
      	digitalWrite(fourth_left_turn, LOW);
      	digitalWrite(fourth_right_turn, LOW);
    }
  }
  if (Left_turn_val == HIGH){
    while (Left_turn_val == HIGH){
      Left_turn_val = digitalRead(Left_turn);
      if (Left_turn_val != HIGH) 
        break; 	
 	 	digitalWrite(fourth_left_brake, HIGH);
	 	delay(250);	
      	digitalWrite(fourth_left_turn, HIGH);
     	delay(250);
 		digitalWrite(fourth_left_turn, LOW);
      	digitalWrite(fourth_left_brake, LOW);
      	delay(500);
    }
  }
  
  if (Right_turn_val == HIGH){	
    while (Right_turn_val == HIGH){
      Right_turn_val = digitalRead(Right_turn);
      if (Right_turn_val != HIGH) 
        break; 	
 	 	digitalWrite(fourth_right_brake, HIGH);
	 	delay(250);	
      	digitalWrite(fourth_right_turn, HIGH);
     	delay(250);
 		digitalWrite(fourth_right_turn, LOW);
      	digitalWrite(fourth_right_brake, LOW);
      	delay(500);
    }
  }

  if (Brake_Value == HIGH){
   	if (count < 3){ 
  	digitalWrite(fourth_left_brake, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(fourth_left_turn,HIGH); 
    digitalWrite(fourth_right_turn,HIGH);
    digitalWrite(fourth_right_brake,HIGH);
  	delay(150);               // wait for a second
  	digitalWrite(fourth_left_brake, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(fourth_left_turn,LOW);
    digitalWrite(fourth_right_turn,LOW);
    digitalWrite(fourth_right_brake,LOW);
  	delay(200); // wait for a second
  	count++;
  	}
	digitalWrite(fourth_left_brake, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(fourth_left_turn,HIGH); 
    digitalWrite(fourth_right_turn,HIGH);
    digitalWrite(fourth_right_brake,HIGH);
  }
  else {
    count = 0;
    digitalWrite(fourth_left_brake, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(fourth_left_turn,LOW);
    digitalWrite(fourth_right_turn,LOW);
    digitalWrite(fourth_right_brake,LOW); 
  }

}
