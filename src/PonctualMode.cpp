#include "PonctualMode.h"


PonctualMode::PonctualMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest)
{
    sensors = newSensors;
    printer = newPrinter;
    button = newButton;
    isTest = newIsTest;

    off = false;
    sample_size = sensors->getSettings()->getSample_size();
    born_inf = sensors->getSettings()->getBornInf();
    born_sup = sensors->getSettings()->getBornSup();

    if(sensors->getSettings()->isNO())
        sensors->setRelais(true);
    else
        sensors->setRelais(false);

    printer->Clear();
    printer->WriteL1("Testing...");
    printer->WriteL2(sensors->getMesure());

    t1 = now();
    t2 = t1;

}

void PonctualMode::ponctualModeSimpleExec()
{
    if(second(t2 - t1) + 1 > sensors->getSettings()->getInterval())
    {
        average = 0;
        for(i = 0; i < sample_size; i++)
            average += sensors->getMesure();
        average /= sample_size;

        if(average < born_inf || average > born_sup)
        {
            sensors->setRelais(!sensors->getRelais());
            off = true;

        }

        printer->Clear();
        printer->WriteL1("Testing...");
        printer->WriteL2(average);

        t1 = t2;

    }

    t2 = now();
    button->checkButtonsUnblocking();

}

void PonctualMode::launch()
{
    int dayTag;
    int startingHour;
    int startingMinute;
    int endingHour;
    int endingMinute;

    while(!button->buttonOk() && !off)
    {
        dayTag = dayOfWeek(now()) - 2;
        startingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingHour();
        startingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getStartingMinute();
        endingHour = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingHour();
        endingMinute = sensors->getSettings()->getPlanning()->getDay(dayTag)->getEndingMinute();

        if(isTest)
            ponctualModeSimpleExec();
        else if((hour() > startingHour) || (hour() == startingHour) && (minute() > startingMinute))
        {
            if((hour() < endingHour) || ((hour() == endingHour) && (minute() < endingMinute)))
                ponctualModeSimpleExec();
            else
            {
                button->checkButtonsUnblocking();

                if(button->buttonOk())
                    break;

            }

        }
        else
        {
            button->checkButtonsUnblocking();

            if(button->buttonOk())
                break;

        }

    }

}
