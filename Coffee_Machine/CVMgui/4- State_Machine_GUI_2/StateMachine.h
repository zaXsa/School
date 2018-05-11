#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <string>
#include <iostream>

typedef enum {S_NO, S_START, S_INIT, S_ChooseType, S_WAIT_FOR_COINS, S_CHECK_AMOUNT, S_Dispence, S_COLA, S_CHANGE}
             state_e;
typedef enum {E_NO, E_SEQ, E_INIT, E_IN5C, E_IN10C, E_IN20C, E_IN50C, E_Drink1, E_Drink2, E_Drink3, E_Cancel, E_MONEY_NOTENOUGH, E_MONEY_ENOUGH}
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
    int DrinkPrice;

    state_e ae_start();
    state_e ae_init();
    state_e ae_Drink1();
    state_e ae_Drink2();
    state_e ae_Drink3();
    state_e ae_Cancel();
    state_e ae_5_cents();
    state_e ae_10_cents();
    state_e ae_20_cents();
    state_e ae_50_cents();
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
};

#endif
