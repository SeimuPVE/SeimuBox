#ifndef CONTINUEMODE_H
#define CONTINUEMODE_H

#include "ModeCreator.h"


/**
 * Continue mode. Get sensor information in continue and use the result to turn on or off the relay.
 */
class ContinueMode : public ModeCreator
{
    public:
        /**
         * Constructor.
         * @param newSensors : sensor to get the information.
         * @param newPrinter : way to print information.
         * @param newButton : button to used to move in the menu.
         * @param newIsTest : boolean to tell if it's for tests or a normal mode.
         */
        ContinueMode(Sensors *newSensors, Printer *newPrinter, Button *newButton, bool newIsTest);

        /**
         * Get a simple execution with only one measure.
         * @return true if everything went well, false if an error occurred.
         */
        bool simpleExec();

};

#endif
