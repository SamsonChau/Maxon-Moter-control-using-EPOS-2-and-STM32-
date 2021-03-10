/*
README
*/

//**DEFINE MOTION FUNCTIONS
//*SET OP-MODE
bool SET_OP_MODE(uint8_t node_num, OP_MODE mode);

//*FUNCTIONS USED IN P-VELOCITY MODE
bool SET_MAX_P_VELOCITY(uint8_t node_num, uint32_t data);
bool SET_P_ACCELERATION(uint8_t node_num, uint32_t data);
bool SET_P_DECELERATION(uint8_t node_num, uint32_t data);
bool SET_QUICK_STOP_DECELERATION(uint8_t node_num, uint32_t data);
bool SET_MOTION_PROFILE_TYPE(uint8_t node_num, MOTION_PROFILE_TYPE type);
bool SET_TARGET_VELOCITY(uint8_t node_num, int32_t data);
bool STOP_P_VELOCITY(uint8_t node_num);
bool QUICK_STOP_P_VELOCITY(uint8_t node_num);

//*FUNCTIONS USED IN CURRENT MODE
bool SET_CONTINOUS_CURRENT_LIMIT(uint8_t node_num, uint16_t data);
bool SET_MAX_CURRENT_MODE_SPEED(uint8_t node_num, uint32_t data);
bool SET_THERMAL_TIME_CONSTANT_WINDING(uint8_t node_num, uint16_t data);
bool SET_CURRENT_VALUE(uint8_t node_num, int16_t data);
bool STOP_CURRENT_VELOCITY(uint8_t node_num);
bool QUICK_STOP_CURRENT_VELOCITY(uint8_t node_num);



