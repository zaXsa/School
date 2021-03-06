#include "MainWindow.h"
#include "StateMachine.h"

#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
//********************* Mealy Actions

state_e StateMachine::ae_start(){
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
    pDialog->setDisplay("Enter Drink choice");
    pDialog->enableCentButtons(true);
    return E_SEQ;
}

event_e StateMachine::as_wait_for_coins(){
    return E_NO;
}

event_e StateMachine::as_check_amount(){
    pDialog->setLogger("\nAmount:\t"+QString::number(money)+"\nNeed:\t"+QString::number(DrinkPrice));
    pDialog->setDisplay("Amount:\t"+QString::number(money)+"\nNeed:\t"+QString::number(DrinkPrice));

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
            //pDialog->setLogger("-state (with event): Start");
            nextState = ae_start();
            break;

        case S_INIT:
            //pDialog->setLogger("-state (with event): Init");
            nextState = ae_init();
            break;

        case S_ChooseType:
            //pDialog->setLogger("-state (with event): Wait for drink choice");
            switch(eventIn) {
            case E_Drink1:
            //    pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink1();
                break;
            case E_Drink2:
            //    pDialog->setLogger("\t Choice 2 selected");
                nextState = ae_Drink2();
                break;
            case E_Drink3:
            //    pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink3();
                break;
            default:
            //    pDialog->setLogger("S_ChooseType System ERROR: Unknown event");
                nextState = ae_start();
                break;
            }

        case S_WAIT_FOR_COINS:
            //pDialog->setLogger("-state (with event): Wait for coins");
            pDialog->setDisplay("Enter your coins please");
            switch(eventIn) {
            case E_IN0C:
            //    pDialog->setLogger("\t 5 Cents inserted");
                nextState = ae_0_cents();
                break;
            case E_IN5C:
            //    pDialog->setLogger("\t 5 Cents inserted");
                nextState = ae_5_cents();
                break;
            case E_IN10C:
            //    pDialog->setLogger("\t 10 Cents inserted");
                nextState = ae_10_cents();
                break;
            case E_IN20C:
            //    pDialog->setLogger("\t 20 Cents inserted");
                nextState = ae_20_cents();
                break;
            case E_IN50C:
            //    pDialog->setLogger("\t 50 Cents inserted");
                nextState = ae_50_cents();
                break;
            case E_IN100C:
            //    pDialog->setLogger("\t 50 Cents inserted");
                nextState = ae_100_cents();
                break;
            case E_Drink1:
            //    pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink1();
                break;
            case E_Drink2:
            //    pDialog->setLogger("\t Choice 2 selected");
                nextState = ae_Drink2();
                break;
            case E_Drink3:
            //    pDialog->setLogger("\t Choice 1 selected");
                nextState = ae_Drink3();
                break;
            case E_Cancel:
            //    pDialog->setLogger("\t Choice 2 selected");
                nextState = ae_Cancel();
                break;
            case E_coinWrong:
            //    pDialog->setLogger("\t Unkown coin inserted");
                nextState = ae_coinWrong();
                break;
            default:
            //    pDialog->setLogger("S_WAIT_FOR_COINS System ERROR: Unknown event");
                break;
            }

            break; //outer

        case S_CHECK_AMOUNT:
        //    pDialog->setLogger("-state (with event): Check amount");

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
        //    pDialog->setLogger("-state (with event): COLA");
            nextState = S_CHANGE;
            break;

        case S_CHANGE:
        //    pDialog->setLogger("-state (with event): CHANGE");
            nextState = S_INIT;
            break;
        }


        //***************************************************************** next state

        switch(nextState){
        case S_START:
        //    pDialog->setLogger("-state: Start");
            eventOut = as_start();
            break;

        case S_INIT:
        //    pDialog->setLogger("-state: Init");
            eventOut = as_init();
            break;

        case S_ChooseType:
        //    pDialog->setLogger("-state: Wait for drink");
            eventOut = as_wait_for_coins(); // Go waiting for external events: event driven
            break;

        case S_WAIT_FOR_COINS:
        //    pDialog->setLogger("-state: Wait for coins");
            eventOut = as_wait_for_coins(); // Go waiting for external events: event driven
            break;

        case S_CHECK_AMOUNT:
        //    pDialog->setLogger("-state: Check amount");
            eventOut = as_check_amount();
            break;

        case S_COLA:
        //    pDialog->setLogger("-state: COLA");
            eventOut = as_cola();
            break;

        case S_Dispence:
        //    pDialog->setLogger("-state: Wait for drink");
            eventOut = as_change(); // Go waiting for external events: event driven
            break;

        case S_CHANGE:
        //    pDialog->setLogger("-state: CHANGE");
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




