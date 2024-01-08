#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int gameButton = 13;
int resetButton = 2;
long randNumber;
bool gameOver = false;


void setup() {
  pinMode(gameButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Game is in play!");
}


void loop() {
  determineRestart();
  if (gameOver == false) {
    randNumber = random(3, 13);
    Serial.println(randNumber);
    switch (randNumber) {
      case 3:
        {
          ledControl(500);
          determineStop("Rochambeau", "1");
          determineRestart();
          break;
        }
      case 4:
        {
          ledControl(450);
          determineStop("Pembroke Campus", "2");
          determineRestart();
          break;
        }
      case 5:
        {
          ledControl(400);
          determineStop("Hillel", "3");
          determineRestart();
          break;
        }
      case 6:
        {
          ledControl(350);
          determineStop("the Rock", "4");
          determineRestart();
          break;
        }
      case 7:
        {
          ledControl(300);
          determineStop("Keeney/Wayland", "5");
          determineRestart();
          break;
        }
      case 8:
        {
          ledControl(250);
          determineStop("Jo's", "6");
          determineRestart();
          break;
        }
      case 9:
        {
          ledControl(200);
          determineStop("Perkins/Young-O", "7");
          determineRestart();
          break;
        }
      case 10:
        {
          ledControl(100);
          determineStop("the ERC", "8");
          determineRestart();
          break;
        }
      case 11:
        {
          ledControl(80);
          determineStop("Minden     ", "9");
          determineRestart();
          break;
        }
      case 12:
        {
          ledControl(50);
          determineStop("Athletics.   ", "10");
          determineRestart();
          break;
        }
      default:
        {
          break;
        }
    }
  }
}

void ledControl(int timeDelay) {
  digitalWrite(randNumber, LOW);
  delay(timeDelay);
  digitalWrite(randNumber, HIGH);
  delay(timeDelay);
  digitalWrite(randNumber, LOW);
  delay(timeDelay);
}

void determineStop(String textLineOne, String textLineTwo) {
  if (digitalRead(gameButton) == HIGH) {
    Serial.println("you got off at: " + textLineOne);
    Serial.println("difficulty: " + textLineTwo + "/10");


    digitalWrite(randNumber, HIGH);
    for (int i = 0; i < 4; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You got off at: ");
      lcd.setCursor(0, 1);
      lcd.print(textLineOne);
      delay(900);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("difficulty: ");
      lcd.setCursor(0, 1);
      lcd.print(textLineTwo + "/10");
      delay(900);
    }

    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("press the blue");
      lcd.setCursor(0, 1);
      lcd.print("button to play");
      delay(1000);

    gameOver = true;
  }
}

void determineRestart() {
  Serial.println("inside the restart function");
  if (digitalRead(resetButton) == HIGH && gameOver == true) {
    Serial.println("reset button pressed");
    for (int i = 3; i < 14; i++) {
      digitalWrite(i, LOW);
    }
    gameOver = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game is in play!");

  }
}
