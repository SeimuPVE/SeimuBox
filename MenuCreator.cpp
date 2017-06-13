#include "MenuCreator.h"


MenuCreator::MenuCreator()
{
    currentChoice = 0;

    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;

}

void MenuCreator::setTitles(String newTitleList[], int newTitleSize)
{
    if((titleList = (char **) malloc(newTitleSize * sizeof(char *))) == NULL)
        Serial.println("Malloc error");
    
    for(int i = 0; i < newTitleSize; i++)
    {
        if((titleList[i] = (char *) malloc((newTitleList[i].length() + 1 ) * sizeof(char))) == NULL)
            Serial.println("Malloc error");
        
        newTitleList[i].toCharArray(titleList[i], newTitleList[i].length() + 1);

    }

    titleSize = newTitleSize;
  
}

void MenuCreator::setLabels(String newLabelList[], int newLabelSize)
{
    if((labelList = (char **) malloc(newLabelSize * sizeof(char *))) == NULL)
        Serial.println("Malloc error");
    
    for(int i = 0; i < newLabelSize; i++)
    {
        if((labelList[i] = (char *) malloc((newLabelList[i].length() + 1 ) * sizeof(char))) == NULL)
            Serial.println("Malloc error");
        
        newLabelList[i].toCharArray(labelList[i], newLabelList[i].length() + 1);
      
    }

    labelSize = newLabelSize;
  
}

void MenuCreator::execute()
{
    while(1)
    {        
        checkButtons();
      
        if(buttonUp())
            currentChoice = (currentChoice + 1) % titleSize;
        else if(buttonDown())
        {
            currentChoice--;

            if(currentChoice < 0)
                currentChoice = titleSize - 1;
          
        }
        else if(buttonOk())
            menuFunctions(currentChoice);
    
        printChoice();
      
    }
  
}

// TODO : for tests, please change it.
void MenuCreator::checkButtons()
{
    char input;

    Serial.print("> ");
    while(Serial.available() <= 0);

    input = Serial.read();
    Serial.println(input);

    buttonUpState = false;
    buttonDownState = false;
    buttonOkState = false;

    switch(input)
    {
      case 'U': buttonUpState = true; break;
      case 'D': buttonDownState = true;  break;
      case 'O': buttonOkState = true;  break;
    
    }

}

bool MenuCreator::buttonUp()
{
    return buttonUpState;
  
}

bool MenuCreator::buttonDown()
{
    return buttonDownState;
        
}

bool MenuCreator::buttonOk()
{
    return buttonOkState;

}

void MenuCreator::printLaunchMode()
{
    Serial.println("Launch mode");
  
}

void MenuCreator::printChoice()
{
    Serial.print(titleList[currentChoice]);
    Serial.print(" - ");
    Serial.println(labelList[currentChoice]);
  
}

