void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print("Podaj pierwszy argument: ");
  // while(Serial.available() == 0){};
  // int arg_A = Serial.parseInt();
  // Serial.println(arg_A);
  // Serial.print("Podaj operator: ");
  // while(Serial.available() == 0){};
  // char action = Serial.read();
  // Serial.println(action);
  // Serial.print("Podaj drugi argument: ");
  // while(Serial.available() == 0){};
  // int arg_B = Serial.parseInt();
  // Serial.println(arg_B);

  // switch(action) {
  //   case '+': {
  //    Serial.println(arg_A + arg_B);
  //     break;
  //   }
  //   case '-': {
  //      Serial.println(arg_A - arg_B);
  //     break;
  //   }
  //   case '*': {
  //     Serial.println(arg_A * arg_B);
  //     break;
  //   }
  //   case '/': {
  //     if(arg_B == 0) {
  //       Serial.println("Nie wolno dzielić przez 0");
  //     } else {
  //       Serial.println(arg_A / arg_B);
  //     }
  //   }
  //   default: {
  //     Serial.println("Niepoprawny operator");
  //     break;
  //   }
  // }

  while(Serial.available() == 0){};
  int arg_A = Serial.parseInt();
  char action = Serial.read();
  int arg_B = Serial.parseInt();
  switch(action) {
    case '+': {
     Serial.println(arg_A + arg_B);
      break;
    }
    case '-': {
       Serial.println(arg_A - arg_B);
      break;
    }
    case '*': {
      Serial.println(arg_A * arg_B);
      break;
    }
    case '/': {
      if(arg_B == 0) {
        Serial.println("Nie wolno dzielić przez 0");
      } else {
        Serial.println(arg_A / arg_B);
      }
    }
    default: {
      Serial.println("Niepoprawny operator");
      break;
    }
  }
}
