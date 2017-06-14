#include "Settings.h"

Settings::Settings()
{
    setPonctual(true);
    setNumberCounts(10);
    setAverageTime(10);
    setBornSup(500.0);
    setBornInf(400.0);
    setNO(false);
  
}

WeekPlanning Settings::getPlanning()
{
    return planning;
  
}

bool Settings::isPonctual()
{
    return ponctual;
  
}

int Settings::getNumberCounts()
{
    return numberCounts;
  
}

int Settings::getAverageTime()
{
    return averageTime;
  
}

double Settings::getBornSup()
{
    return bornSup;
  
}

double Settings::getBornInf()
{
    return bornInf;
  
}

bool Settings::getNO()
{
    return NO;
  
}

void Settings::setPonctual(bool newPonctual)
{
    ponctual = newPonctual;
  
}

void Settings::setNumberCounts(int newNumberCounts)
{
    numberCounts = newNumberCounts;
  
}

void Settings::setAverageTime(int newAverageTime)
{
    averageTime = newAverageTime;
  
}

void Settings::setBornSup(double newBornSup)
{
    bornSup = newBornSup;
  
}

void Settings::setBornInf(double newBornInf)
{
    bornInf = newBornInf;
  
}

void Settings::setNO(bool newNO)
{
    NO = newNO;

}

void Settings::setDayStartingTime(int dayTag, String startingTime)
{
    planning.setDayStartingTime(dayTag, startingTime);
  
}

void Settings::setDayEndingTime(int dayTag, String endingTime)
{
    planning.setDayEndingTime(dayTag, endingTime);
  
}

void Settings::setAllStartingTime(String startingTime)
{
    planning.setAllStartingTime(startingTime);

}

void Settings::setAllEndingTime(String endingTime)
{
    planning.setAllEndingTime(endingTime);
  
}

void Settings::setDay(int dayTag, String startingHour, String endingHour)
{
    planning.setDay(dayTag, startingHour, endingHour);
  
}

void Settings::setAll(String startingHour, String endingHour)
{
    planning.setAll(startingHour, endingHour);
  
}

void Settings::printDay(int dayTag)
{
    Printer::Write("S:");
    Printer::Write(getPlanning().getDay(MONDAY).getStartingTime());
    Printer::Write("  ");
    Printer::Write("E:");
    Printer::Write(getPlanning().getDay(MONDAY).getEndingTime());
    
}

void Settings::printCurrentDate()
{
    Printer::Write("Print current date");
    
}

void Settings::printPonctuality()
{
    Printer::Write("Print of continue or not");
  
}

void Settings::printFrequency()
{
    Printer::Write("Print frequency or not");
  
}

void Settings::printBorns()
{
    Printer::Write("Print borns");
  
}

void Settings::printNO()
{
    Printer::Write("Print if NO or not");
  
}

