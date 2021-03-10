#include "robot.h"

int main() 
{
    SERIAL_SETUP(9600);
    
    PC_SEND("  \r\n");
    PC_SEND("CANnucleo board #1\r\n");
    SET_CANOpen_FREQ(1000000);
    wait(1.0);
    
    SDO_CW(2, CLEAR_FAULT);
    wait(0.5);
    
    SET_NMT(RESET_COMMU);
    wait(1.0);
    
    if(!PDO_INIT()){PC_SEND("PDO INITIALIZATION FAILURE\r\n");}  //PDO INITIALIZE FUNCTION SHOULD BE MODIFIED BY USER
    
    SDO_CW(2, SHUT_DOWN);
    SET_NMT(SET_OP);
    wait(0.5);
    //**********CONFIGURATION DONE! READY FOR MOTION**********
    
    //TEST P-VELOCITY MODE
    
    SET_OP_MODE(2, PVM);
    
    SET_MAX_P_VELOCITY(2, 5000);
    SET_P_ACCELERATION(2, 2000);
    SET_P_DECELERATION(2, 2000);
    SET_QUICK_STOP_DECELERATION(2, 10000);
    SET_MOTION_PROFILE_TYPE(2, SIN);
    //              **********WARNING: HERE THE VALUE FROM CURRENT MODE IS ALSO EFFECTIVE! RESET THEM TO DEFAULT IF YOU DON'T WANT A CURRENT LIMIT!!!**********
    SET_CONTINOUS_CURRENT_LIMIT(2, 10000);
    SET_MAX_CURRENT_MODE_SPEED(2, 25000);
    SET_THERMAL_TIME_CONSTANT_WINDING(2, 40);
    
    SDO_CW(2, SWITCH_ON_ENABLE_OP);

    SET_TARGET_VELOCITY(2, 500);
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    wait(5.0);
    STOP_P_VELOCITY(2);
    wait(1.0);
    
    SET_TARGET_VELOCITY(2, -1000);
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    wait(5.0);
    STOP_P_VELOCITY(2);
    wait(1.0);
    
    SET_TARGET_VELOCITY(2, 1500);
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    wait(5.0);
    STOP_P_VELOCITY(2);
    wait(1.0);
    
    SET_TARGET_VELOCITY(2, -2000);
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    wait(5.0);
    STOP_P_VELOCITY(2);
    wait(1.0);
    
    
    //TEST CURRENT MODE
    /*
    SET_OP_MODE(2, CM);
    
    SET_CONTINOUS_CURRENT_LIMIT(2, 9000);
    SET_MAX_CURRENT_MODE_SPEED(2, 500);
    SET_THERMAL_TIME_CONSTANT_WINDING(2, 20);
    
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    SET_CURRENT_VALUE(2, 1000);
    wait(20.0);
    STOP_CURRENT_VELOCITY(2);
    */
    
    
}