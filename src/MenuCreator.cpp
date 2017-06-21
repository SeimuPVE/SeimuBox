#include "MenuCreator.h"


MenuCreator::MenuCreator(Printer *newPrinter, Button *newButton)
{
    printer = newPrinter;
    button = newButton;
    
    currentChoice = 0;

}

void MenuCreator::setExitFlag(bool newExitFlag)
{
    exitFlag = newExitFlag;
  
}

void MenuCreator::setTitles(String newTitleList[], int newTitleSize)
{
    if((titleList = (char **) malloc(newTitleSize * sizeof(char *))) == NULL)
        Serial.println("Malloc error : can't create title list in the menu creator.");
    
    for(int i = 0; i < newTitleSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1) * sizeof(char))) == NULL)
            Serial.println("Malloc error : can't add title to the list in the menu creator.");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

    }

    titleSize = newTitleSize;
  
}

void MenuCreator::execute()
{
    currentChoice = 0;
    exitFlag = false;

    printChoice();
    if(titleSize != 4)
        printLabel();

    while(!exitFlag)
    {
        currentChoice = 0;
        button->checkButtons();
      
        if(button->buttonUp())
        {
            currentChoice++;

            currentChoice = currentChoice%titleSize;

/*            if(currentChoice >= titleSize - 1)
                currentChoice = titleSize - 1;*/

        }
        else if(button->buttonDown())
        {
            currentChoice--;

            if(currentChoice < 0)
                currentChoice = 0;
          
        }
        else if(button->buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
        if(titleSize != 4)
            printLabel();
      
    }

    currentChoice = 0;

}

void MenuCreator::printChoice()
{
    printer->Clear();

    if(titleSize == 4)
    {
        if(currentChoice == 0)
            printer->WriteL1(">", 0);
        printer->WriteL1(titleList[0], 1);

        if(currentChoice == 1)
            printer->WriteL1(">", 7);
        printer->WriteL1(titleList[1], 8);

        if(currentChoice == 2)
            printer->WriteL2(">", 0);
        printer->WriteL2(titleList[2], 1);

        if(currentChoice == 3)
            printer->WriteL2(">", 7);
        printer->WriteL2(titleList[3], 8);

    }
    else
    {
        printer->WriteL1("-> ");
        printer->WriteL1(titleList[currentChoice], 3);

    }

}

