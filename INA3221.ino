//================================================================================================================================
void Init_INA3221()                                         // 
{
  ina3221.begin();                                          // 
  ina3221.reset();                                          // 

  ina3221.setShuntRes(10, 10, 10);                          // 
}
//================================================================================================================================
void Print_INA3221(uint16_t x, uint16_t y)                  // Вывести на дисплей значение тока и напряжения
{
  if (millis() > timeINA + 200)                             // 
  {
    float current[3];                                       // 
    float voltage[3];                                       // 

    current[0] = ina3221.getCurrent(INA3221_CH1);           // Прочитать ток
    voltage[0] = ina3221.getVoltage(INA3221_CH1);           // Прочитать напряжение 

    current[1] = ina3221.getCurrent(INA3221_CH2);           // Прочитать ток
    voltage[1] = ina3221.getVoltage(INA3221_CH2);           // Прочитать напряжение 

    current[2] = ina3221.getCurrent(INA3221_CH3);           // Прочитать ток
    voltage[2] = ina3221.getVoltage(INA3221_CH3);           // Прочитать напряжение 
    //----------------------------------------------------------------------------------------------------------------------------
    tft.setTextColor(TFT_WHITE, TFT_BLACK);					        // Установить цвет текста
    tft.setTextSize(1);									                    // Установить размер символов
    //----------------------------------------------------------------------------------------------------------------------------
    tft.setCursor(x, y);								                    // Установить координату
    tft.print("Channel 1: ");                               // 
    tft.print(current[0], PRINT_DEC_POINTS);                // Вывести значение тока
    tft.print("A, ");                                       // 
    tft.print(voltage[0], PRINT_DEC_POINTS);                // Вывести значение напряжения
    tft.print(' ');                                         // 
    tft.println("V");                                       // 
    //----------------------------------------------------------------------------------------------------------------------------
    tft.setCursor(x, y + 10);								                // Установить координату
    tft.print("Channel 2: ");                               // 
    tft.print(current[1], PRINT_DEC_POINTS);                // Вывести значение тока
    tft.print("A, ");                                       // 
    tft.print(voltage[1], PRINT_DEC_POINTS);                // Вывести значение напряжения
    tft.print(' ');                                         // 
    tft.println("V");                                       // 
    //----------------------------------------------------------------------------------------------------------------------------
    tft.setCursor(x, y + 20);								                // Установить координату
    tft.print("Channel 3: ");                               // 
    tft.print(current[2], PRINT_DEC_POINTS);                // Вывести значение тока
    tft.print("A, ");                                       // 
    tft.print(voltage[2], PRINT_DEC_POINTS);                // Вывести значение напряжения
    tft.print(' ');                                         // 
    tft.println("V");                                       // 
    //----------------------------------------------------------------------------------------------------------------------------
    timeINA = millis();                                     // Сбросить таймер
  }
}
//================================================================================================================================