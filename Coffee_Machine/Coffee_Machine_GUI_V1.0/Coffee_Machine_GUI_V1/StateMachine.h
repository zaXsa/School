#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

typedef enum {S_NO, S_START, S_INIT, S_ChooseType, S_WAIT_FOR_COINS, S_CHECK_AMOUNT, S_Dispence, S_COLA, S_CHANGE, S_CHANGEWRONG}
             state_e;
typedef enum {E_NO, E_SEQ, E_INIT, E_NODRINKS ,E_IN0C, E_IN5C, E_IN10C, E_IN20C, E_IN50C, E_IN100C, E_Drink1, E_Drink2, E_Drink3, E_coinWrong, E_Cancel, E_MONEY_NOTENOUGH, E_MONEY_ENOUGH}
             event_e;

class MainWindow;

class StateMachine {
public:
    StateMachine(MainWindow* pDialo):
        pDialog(pDialo),currentState(S_START){}

    void handleEvent(event_e eventIn);

private:
    MainWindow *pDialog;
    state_e currentState;

    int money;

    std::string DrinkType;
    string DrinkAvailable1 = "Drink 1 is available";
    string DrinkAvailable2 = "Drink 2 is available";
    string DrinkAvailable3 = "Drink 3 is available";
    int DrinkPrice;

    state_e ae_start();
    state_e ae_init();
    state_e ae_Drink1();
    state_e ae_Drink2();
    state_e ae_Drink3();
    state_e ae_Cancel();
    state_e ae_coinWrong();
    state_e ae_0_cents();
    state_e ae_5_cents();
    state_e ae_10_cents();
    state_e ae_20_cents();
    state_e ae_50_cents();
    state_e ae_100_cents();
    state_e ae_money_enough();
    state_e ae_money_notenough();
    state_e ae_cola();
    state_e ae_change();

    event_e as_start();
    event_e as_init();
    event_e as_wait_for_coins();
    event_e as_check_amount();
    event_e as_cola();
    event_e as_change();
    event_e as_changeWrong();
};

#endif
