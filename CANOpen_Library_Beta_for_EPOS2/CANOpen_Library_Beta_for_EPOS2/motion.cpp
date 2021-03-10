#include "robot.h"

//**DEFINE MOTION FUNCTIONS
bool SET_OP_MODE(uint8_t node_num, OP_MODE mode)
{
    char opmode = mode;
    switch(mode)
    {
        case 0x07:
        {
            PC_SEND("    OP-MODE = IPM\r\n");
            break;
        }
        case 0x06:
        {
            PC_SEND("    OP-MODE = HM\r\n");
            break;
        }
        case 0x03:
        {
            PC_SEND("    OP-MODE = PVM\r\n");
            break;
        }
        case 0x01:
        {
            PC_SEND("    OP-MODE = PPM\r\n");
            break;
        }
        case 0xFF:
        {
            PC_SEND("    OP-MODE = PM\r\n");
            break;
        }
        case 0xFE:
        {
            PC_SEND("    OP-MODE = VM\r\n");
            break;
        }
        case 0xFD:
        {
            PC_SEND("    OP-MODE = CM\r\n");
            break;
        }
        case 0xFC:
        {
            PC_SEND("    OP-MODE = DM\r\n");
            break;
        }
        case 0xFB:
        {
            PC_SEND("    OP-MODE = MEM\r\n");
            break;
        }
        case 0xFA:
        {
            PC_SEND("    OP-MODE = SDM\r\n");
            break;
        }
        default:
        {
            PC_SEND("    ERROR: UNDEFINED MODE\r\n");
            return 0;
        }
    }
    
    if(!SDO_EXE(node_num,0x60,0x60,0x00,opmode,1)){PC_SEND("    MOTION ERROR: FAIL TO SET OP-MODE\r\n"); return 0;}
    
    return 1;
}

//*FUNCTIONS USED IN P-VELOCITY MODE
bool SET_MAX_P_VELOCITY(uint8_t node_num, uint32_t data)
{
    if(!SDO_EXE(node_num,0x7F,0x60,0x00,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET MAX PROFILE VELOCITY\r\n"); return 0;}
    PC_SEND("SET MAX PROFILE VELOCITY: %d\n", data);
    return 1;
}

bool SET_P_ACCELERATION(uint8_t node_num, uint32_t data)
{
    if(!SDO_EXE(node_num,0x83,0x60,0x00,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET PROFILE ACCELERATION\r\n"); return 0;}
    PC_SEND("SET PROFILE ACCELERATION: %d\n", data);
    return 1;
}

bool SET_P_DECELERATION(uint8_t node_num, uint32_t data)
{
    if(!SDO_EXE(node_num,0x84,0x60,0x00,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET PROFILE DECELERATION\r\n"); return 0;}
    PC_SEND("SET PROFILE DECELERATION: %d\n", data);
    return 1;
}

bool SET_QUICK_STOP_DECELERATION(uint8_t node_num, uint32_t data)
{
    if(!SDO_EXE(node_num,0x85,0x60,0x00,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET QUICK STOP DECELERATION\r\n"); return 0;}
    PC_SEND("SET QUICK STOP DECELERATION: %d\n", data);
    return 1;
}

bool SET_MOTION_PROFILE_TYPE(uint8_t node_num, MOTION_PROFILE_TYPE type)
{
    int mpt = type;
    if(!SDO_EXE(node_num,0x86,0x60,0x00,mpt,2)){PC_SEND("    MOTION ERROR: FAIL TO SET MOTION PROFILE TYPE\r\n"); return 0;}
    if(mpt == 0){PC_SEND("SET MOTION PROFILE TYPE: LINEAR\r\n");}
    else {PC_SEND("SET MOTION PROFILE TYPE: SIN\r\n");}
    return 1;
}

bool SET_TARGET_VELOCITY(uint8_t node_num, int32_t data)
{   
    if(!SDO_EXE(node_num,0xFF,0x60,0x00,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET TARGET VELOCITY\r\n"); return 0;}
    PC_SEND("SET TARGET VELOCITY: %d\n", data);
    return 1;
}

bool STOP_P_VELOCITY(uint8_t node_num)
{
    if(!SDO_EXE(node_num,0x40,0x60,0x00,0x010F,2)){PC_SEND("    MOTION ERROR: FAIL TO STOP PROFILE VELOCITY\r\n"); return 0;}
    PC_SEND("STOP PROFILE VELOCITY\r\n");
    return 1;
}

bool QUICK_STOP_P_VELOCITY(uint8_t node_num)
{
    if(!SDO_EXE(node_num,0x40,0x60,0x00,0x000B,2)){PC_SEND("    MOTION ERROR: FAIL TO QUICK STOP PROFILE VELOCITY\r\n"); return 0;}
    PC_SEND("QUICK STOP PROFILE VELOCITY\r\n");
    return 1;
}

//*FUNCTIONS USED IN CURRENT MODE
bool SET_CONTINOUS_CURRENT_LIMIT(uint8_t node_num, uint16_t data)
{
    if(!SDO_EXE(node_num,0x10,0x64,0x01,data,2)){PC_SEND("    MOTION ERROR: FAIL TO SET CONTINOUS CURRENT LIMIT\r\n"); return 0;}
    if(!SDO_EXE(node_num,0x10,0x64,0x02,(2*data),2)){PC_SEND("    MOTION ERROR: FAIL TO SET OUTPUT CURRENT LIMIT\r\n"); return 0;}
    PC_SEND("SET CONTINOUS CURRENT LIMIT: %d\n", data);
    PC_SEND("SET OUTPUT CURRENT LIMIT: %d\n", 2*data);   
    return 1;
}

bool SET_MAX_CURRENT_MODE_SPEED(uint8_t node_num, uint32_t data)
{
    if(!SDO_EXE(node_num,0x10,0x64,0x04,data,4)){PC_SEND("    MOTION ERROR: FAIL TO SET MAX CURRENT MODE SPEED\r\n"); return 0;}
    PC_SEND("SET MAX CURRENT MODE SPEED: %d\n", data);    
    return 1;
}

bool SET_THERMAL_TIME_CONSTANT_WINDING(uint8_t node_num, uint16_t data)
{
    if(!SDO_EXE(node_num,0x10,0x64,0x05,data,2)){PC_SEND("    MOTION ERROR: FAIL TO SET THERMAL TIME CONSTANT WINDING\r\n"); return 0;}
    PC_SEND("SET THERMAL TIME CONSTANT WINDING: %d\n", data);    
    return 1;
}

bool SET_CURRENT_VALUE(uint8_t node_num, int16_t data)
{
    if(!SDO_EXE(node_num,0x30,0x20,0x00,data,2)){PC_SEND("    MOTION ERROR: FAIL TO SET CURRENT VALUE\r\n"); return 0;}
    PC_SEND("SET CURRENT VALUE: %d\n", data);
    return 1;
}

bool STOP_CURRENT_VELOCITY(uint8_t node_num)
{
    if(!SDO_EXE(node_num,0x30,0x20,0x00,0x0000,2)){PC_SEND("    MOTION ERROR: FAIL TO STOP CURRENT MODE VELOCITY\r\n"); return 0;}
    PC_SEND("STOP CURRENT MODE VELOCITY\r\n");
    return 1;
}

bool QUICK_STOP_CURRENT_VELOCITY(uint8_t node_num)
{
    if(!SDO_EXE(node_num,0x40,0x60,0x00,0x0002,2)){PC_SEND("    MOTION ERROR: FAIL TO QUICK STOP CURRENT MODE VELOCITY\r\n"); return 0;}
    PC_SEND("QUICK STOP CURRENT MODE VELOCITY\r\n");
    return 1;
}



