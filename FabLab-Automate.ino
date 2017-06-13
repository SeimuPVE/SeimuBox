#include "MainMenu.h"
#include "Sensors.h"
#include "WeekPlanning.h"
#include "Settings.h"
#include "SettingsMenu.h"


void setup()
{
    Serial.begin(9600);
    pinMode(PORT_SENSOR, INPUT);
    pinMode(PORT_RELAIS, OUTPUT);
    
}

void loop()
{
    SettingsMenu menu;
    menu.execute();

/*    DayPlanning monday("Monday", "10h10", "10h10");
    Serial.println("Starting time : " + monday.getStartingTime());
    Serial.println("Ending time : " + monday.getEndingTime());
    delay(1000);*/

/*    Settings settings;
    settings.setDay(MONDAY, "10h00", "18h00");
    settings.getPlanning().printPlanning();
    delay(10000);*/
    
/*    if(Sensors::getMesure() < 500)
        Sensors::setRelais(false);
    else
        Sensors::setRelais(true);*/

}

