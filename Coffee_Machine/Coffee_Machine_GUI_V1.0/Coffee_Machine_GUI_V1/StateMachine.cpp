#include "MainWindow.h"
#include "StateMachine.h"

#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

extern int AvailableAmount1;
extern int AvailableAmount2;
extern int AvailableAmount3;

extern int AvailableChange1;
extern int AvailableChange2;
extern int AvailableChange3;
extern int AvailableChange4;
extern int AvailableChange5;
//********************* Mealy Actions

void StateMachine::ReadFile(){
    pDialog->LogInWindow.SetAdmin();
    string Word;
    int i = 0;
    string fileName;
    fileName = "Admin.txt";
    AdminFile.open(fileName.c_str());
    while(AdminFile >> Word){
        switch(i){
        case 2:
           AvailableAmount1 = std::stoi(Word);
            break;
        case 3:
           AvailableAmount2 = std::stoi(Word);
            break;
        case 4:
           AvailableAmount3 = std::stoi(Word);
            break;
        case 5:
           AvailableChange1 = std::stoi(Word);
            break;
        case 6:
           AvailableChange2 = std::stoi(Word);
            break;
        case 7:
           AvailableChange3 = std::stoi(Word);
            break;
        case 8:
           AvailableChange4 = std::stoi(Word);
            break;
        default:
            break;
        }
        i++;
    }
    AdminFile.close();
}

state_e StateMachine::ae_start(){
    ReadFile();
    return S_INIT;
}

state_e StateMachine::ae_init(){
    return S_ChooseType;
}

state_e StateMachine::ae_Drink1(){
    DrinkPrice = 100;
    DrinkType = "Drink1";
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_Drink2(){
    DrinkPrice = 200;
    DrinkType = "Drink2";
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_Drink3(){
    DrinkPrice = 120;
    DrinkType = "Drink3";
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_Cancel(){
    DrinkPrice = 0;
    return S_CHANGE;
}
state_e StateMachine::ae_coinWrong(){
    pDialog->setLogger("\nwrong coin inserted, Dispencing wrong coin");
    pDialog->setDisplay("\nwrong coin inserted, Dispencing wrong coin");

    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_0_cents(){
    money += 0;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_5_cents(){
    money += 5;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_10_cents(){
    money += 10;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_20_cents(){
    money += 20;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_50_cents(){
    money += 50;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_100_cents(){
    money += 100;
    return S_CHECK_AMOUNT;
}

state_e StateMachine::ae_money_enough(){
    return S_COLA;
}

state_e StateMachine::ae_money_notenough(){
    return S_WAIT_FOR_COINS;
}

// ********************* Moore Actions

event_e StateMachine::as_start(){
    return E_SEQ;
}

event_e StateMachine::as_init(){
    money = 0.0;
    DrinkType = "Nothing";
    DrinkPrice = 0;

    if (AvailableAmount1 <= 0){
        pDialog->setLogger("No more drink 1");
        DrinkAvailable1 = "Drink 1 is not available";
        pDialog->setbuttons1(false);
    }else {
        DrinkAvailable1 = "Drink 1 is available";
        pDialog->setbuttons1(true);
    }
    if (AvailableAmount2 <= 0){
        DrinkAvailable2 = "Drink 2 is not available";
        pDialog->setLogger("No more drink 2");
        pDialog->setbuttons2(false);
    }else {
        DrinkAvailable2 = "Drink 2 is available";
        pDialog->setbuttons2(true);
    }
    if (AvailableAmount3 <= 0){
        DrinkAvailable3 = "Drink 3 is not available";
        pDialog->setLogger("No more drink 3");
        pDialog->setbuttons3(false);
    }else {
        DrinkAvailable3 = "Drink 3 is available";
        pDialog->setbuttons3(true);
    }

        pDialog->setDisplay("Enter Drink choice\n--------------------------------------------------------------\n"
                            +QString::fromStdString(DrinkAvailable1)
                            +"\n"+QString::fromStdString(DrinkAvailable2)
                            +"\n"+QString::fromStdString(DrinkAvailable3));
        pDialog->enableCentButtons(true);
        return E_SEQ;
}

event_e StateMachine::as_wait_for_coins(){
    return E_NO;
}

event_e StateMachine::as_check_amount(){
    pDialog->setLogger("\nThe Drink you have selected is "+QString::fromStdString(DrinkType)
                       +"\nAmount:\t"+QString::number(money)
                       +"\nNeed:\t"+QString::number(DrinkPrice));
    pDialog->setDisplay("The Drink you have selected is "+QString::fromStdString(DrinkType)
                        +"\n---------------------------------------------------------\nAmount:\t"+QString::number(money)
                        +"\nNeed:\t"+QString::number(DrinkPrice));

    if (money >= DrinkPrice) {
        return E_MONEY_ENOUGH;
    }
    else {
        return E_MONEY_NOTENOUGH;
    }
}

event_e StateMachine::as_cola(){
    pDialog->setLogger("\n" + QString::fromStdString(DrinkType) + " is delivered");
    pDialog->setDisplay(QString::fromStdString(DrinkType) + " is delivered");

    if(DrinkType.compare("Drink1") == 0){
        AvailableAmount1--;
    }else if(DrinkType.compare("Drink2") == 0){
        AvailableAmount2--;
    }else if(DrinkType.compare("Drink3") == 0){
        AvailableAmount3--;
    }else if(DrinkType.compare("Nothing") == 0){

    }

    return E_SEQ;
}

event_e StateMachine::as_change(){
    pDialog->setDisplay("change is: " +  QString::number(money - DrinkPrice)+" cents");
    pDialog->setLogger("\nchange is: " +  QString::number(money - DrinkPrice)+" cents");
    return E_SEQ;
}

event_e StateMachine::as_changeWrong(){
    pDialog->setLogger("\nchange (cents): wrong coin");
    return E_IN0C;
}

void StateMachine::handleEvent(event_e eventIn) {
    while (eventIn != E_NO){
        state_e nextState = S_NO; // temproray variable used by this function
        event_e eventOut = E_NO;  // temproray variable used by this function

        // Sequential states must sent E_SEQ .
        // Sequential stepping ends with sending E_NO (= eventOut).

        //***************************************************************** current state

        switch(currentState) {
        case S_START:
            pDialog->setLogger("-state (with event): Start");
            nextState = ae_start();
            break;

        case S_INIT:
            pDialog->setLogger("\n-state (with event): Init");
            nextState = ae_init();
            break;

        case S_ChooseType:
            pDialog->setLogger("\n-state (with event): Wait for drink choice");
            switch(eventIn) {
            case E_Drink1:
                pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink1();
                break;
            case E_Drink2:
                pDialog->setLogger("\t Choice 2 selected");
                nextState = ae_Drink2();
                break;
            case E_Drink3:
                pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink3();
                break;
            default:
                pDialog->setLogger("\nS_ChooseType System ERROR: Unknown event");
                nextState = ae_start();
                break;
            }

        case S_WAIT_FOR_COINS:
            pDialog->setLogger("\n-state (with event): Wait for coins");
            pDialog->setDisplay("Enter your coins please");
            switch(eventIn) {
            case E_IN0C:
                pDialog->setLogger("\n\t 0 Cents inserted");
                nextState = ae_0_cents();
                break;
            case E_IN5C:
                pDialog->setLogger("\n\t 5 Cents inserted");
                nextState = ae_5_cents();
                break;
            case E_IN10C:
                pDialog->setLogger("\n\t 10 Cents inserted");
                nextState = ae_10_cents();
                break;
            case E_IN20C:
                pDialog->setLogger("\n\t 20 Cents inserted");
                nextState = ae_20_cents();
                break;
            case E_IN50C:
                pDialog->setLogger("\n\t 50 Cents inserted");
                nextState = ae_50_cents();
                break;
            case E_IN100C:
                pDialog->setLogger("\n\t 100 Cents inserted");
                nextState = ae_100_cents();
                break;
            case E_Drink1:
                pDialog->setLogger("\n\t Choice 1 selected");
                nextState = ae_Drink1();
                break;
            case E_Drink2:
                pDialog->setLogger("\n\t Choice 2 selected");
                nextState = ae_Drink2();
                break;
            case E_Drink3:
                pDialog->setLogger("\n\t Choice 1 selected");
                nextState = ae_Drink3();
                break;
            case E_Cancel:
                pDialog->setLogger("\n\t Choice 2 selected");
                nextState = ae_Cancel();
                break;
            case E_coinWrong:
                pDialog->setLogger("\n\t Unkown coin inserted");
                nextState = ae_coinWrong();
                break;
            default:
                pDialog->setLogger("\nS_WAIT_FOR_COINS System ERROR: Unknown event");
                break;
            }

            break; //outer

        case S_CHECK_AMOUNT:
            pDialog->setLogger("\n-state (with event): Check amount");

            switch(eventIn){
            case E_MONEY_ENOUGH:
                pDialog->setLogger("\n-----------------------------------------------------");
                nextState = ae_money_enough();
                break;
            case E_MONEY_NOTENOUGH:
                pDialog->setLogger("\n-----------------------------------------------------");
                nextState = ae_money_notenough();
                break;
            default:
                pDialog->setLogger("\nS_CHECK_AMOUNT System ERROR: Unknown event");
                break;
            }
            break; //outer

        case S_COLA:
            pDialog->setLogger("\n-state (with event): COLA");
            nextState = S_CHANGE;
            break;

        case S_CHANGE:
            pDialog->setLogger("\n-state (with event): CHANGE");
            nextState = S_INIT;
            break;
        }


        //***************************************************************** next state

        switch(nextState){
        case S_START:
            pDialog->setLogger("\n-state: Start");
            eventOut = as_start();
            break;

        case S_INIT:
            pDialog->setLogger("\n-state: Init");
            eventOut = as_init();
            break;

        case S_ChooseType:
            pDialog->setLogger("\n-state: Wait for drink");
            eventOut = as_wait_for_coins(); // Go waiting for external events: event driven
            break;

        case S_WAIT_FOR_COINS:
            pDialog->setLogger("\n-state: Wait for coins");
            eventOut = as_wait_for_coins(); // Go waiting for external events: event driven
            break;

        case S_CHECK_AMOUNT:
            pDialog->setLogger("\n-state: Check amount");
            eventOut = as_check_amount();
            break;

        case S_COLA:
            pDialog->setLogger("\n-state: COLA");
            eventOut = as_cola();
            break;

        case S_Dispence:
            pDialog->setLogger("\n-state: Wait for drink");
            eventOut = as_change(); // Go waiting for external events: event driven
            break;

        case S_CHANGE:
            pDialog->setLogger("\n-state: CHANGE");
            eventOut = as_change();
            break;

        default:
            pDialog->setLogger("\nStatemachine System ERROR: Unknown state");
            eventOut = E_NO;
            break;
        }

        currentState = nextState;
        eventIn = eventOut;
    }
    return;
}




