int PinOut[4] {5, 4, 3, 2}; // пины выходы
 
int PinIn[4] {9, 8, 7, 6}; // пины входа
int val = 0;
const char value[4][4]
  
{ {'1', '4', '7', '*'},
  {'2', '5', '8', '0' },
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
// двойной массив, обозначающий кнопку
 
int b = 0; // переменная, куда кладется число из массива(номер кнопки)
 
void setup()
{
  pinMode (2, OUTPUT); // инициализируем порты на выход (подают нули на столбцы)
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
 
  pinMode (6, INPUT); // инициализируем порты на вход с подтяжкой к плюсу (принимают нули на строках)
  digitalWrite(6, HIGH);
  pinMode (7, INPUT);
  digitalWrite(7, HIGH);
  pinMode (8, INPUT);
  digitalWrite(8, HIGH);
  pinMode (9, INPUT);
  digitalWrite(9, HIGH);
 
  Serial.begin(9600); // открываем Serial порт
}
 
void matrix () // создаем функцию для чтения кнопок
{
  for (int i = 1; i <= 4; i++) // цикл, передающий 0 по всем столбцам
  {
    digitalWrite(PinOut[i - 1], LOW); // если i меньше 4 , то отправляем 0 на ножку
    for (int j = 1; j <= 4; j++) // цикл, принимающих 0 по строкам
    {
      if (digitalRead(PinIn[j - 1]) == LOW) // если один из указанных портов входа равен 0, то..
      {
        Serial.println( value[i - 1][j - 1]); // то b равно значению из двойного массива
        delay(175);
      }
    }
    digitalWrite(PinOut[i - 1], HIGH); // подаём обратно высокий уровень
  }
}
 
void loop()
{
  matrix(); // используем функцию опроса матричной клавиатуры 
}