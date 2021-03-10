CANOpen Library v0.0.1_beta for EPOS2
First created by Jim 2018.9.19

####Introduction####

robot.h: A header file to include all other header files, for easier use.

CANOpen.cpp%h: Basic CANOpen communication functions
               Provides user-friendly functions to 
               config CANOpen settings and send CANOpen messages.
//set canopen frequency
  void SET_CANOpen_FREQ(int freq);
//set nmt state, useful when config or use PDO
  bool SET_NMT(NMT_COMMAND cmd);
//transform data value into structure of CANOpen data frame
  void DATA2ARRAY(uint32_t data);
  void DATA2ARRAY(int32_t data);
//send synchronize message, useful in synchronized PDO
  bool SYNC_SEND();
//basic function to send SDO frame
  bool SDO_SEND(uint8_t node_num, const char* msg);
//advanced function to send SDO frame, easier to use
  bool SDO_EXE(uint8_t node_num, char index_lower, char index_higher, char subindex, uint32_t data, char valid_data_length_in_byte);
  bool SDO_EXE(uint8_t node_num, char index_lower, char index_higher, char subindex, int32_t data, char valid_data_length_in_byte);
//send frequently used controlword, useful when clear faults, switch on/off, enable/disable, etc
  bool SDO_CW(uint8_t node_num, CW_COMMAND cmd);
//PDO initialize function, should be modified by yourself to adapt to your situation
  bool PDO_INIT();
//basic function to config RPDO settings, called by PDO_INIT();
  bool RPDO_CONFIG(uint8_t node_num, PDO_SEQUENCE seq, PDO_TRANSTYPE type);
//basic function to config TPDO settings, not finished yet...
  $$$bool TPDO_CONFIG(uint8_t node_num, PDO_TRANSTYPE type);
//basic function to send PDO data frame
  bool PDO_SEND(uint8_t node_num, PDO_SEQUENCE seq, const char* msg, char length);
//functions to use different RPDO frames, should be modified by yourself to adapt to your situation
  bool RPDO1_EXE(uint8_t node_num, CW_COMMAND cmd);
  bool RPDO2_EXE(uint8_t node_num, CW_COMMAND cmd, OP_MODE mode);
  bool RPDO4_EXE(uint8_t node_num, CW_COMMAND cmd, uint32_t p_velocity);

motion.cpp&h: Advanced functions to set parameters or start motion
              in different operation modes using CANOpen protocol.
//set operation mode
  bool SET_OP_MODE(uint8_t node_num, OP_MODE mode);
//functions used in profiled velocity mode
  bool SET_MAX_P_VELOCITY(uint8_t node_num, uint32_t data);
  bool SET_P_ACCELERATION(uint8_t node_num, uint32_t data);
  bool SET_P_DECELERATION(uint8_t node_num, uint32_t data);
  bool SET_QUICK_STOP_DECELERATION(uint8_t node_num, uint32_t data);
  bool SET_MOTION_PROFILE_TYPE(uint8_t node_num, MOTION_PROFILE_TYPE type);
  bool SET_TARGET_VELOCITY(uint8_t node_num, int32_t data);
  bool STOP_P_VELOCITY(uint8_t node_num);
  bool QUICK_STOP_P_VELOCITY(uint8_t node_num);
//functions used in current mode, not supporting analog setpoint at present
  bool SET_CONTINOUS_CURRENT_LIMIT(uint8_t node_num, uint16_t data);
  bool SET_MAX_CURRENT_MODE_SPEED(uint8_t node_num, uint32_t data);
  bool SET_THERMAL_TIME_CONSTANT_WINDING(uint8_t node_num, uint16_t data);
  bool SET_CURRENT_VALUE(uint8_t node_num, int16_t data);
  bool STOP_CURRENT_VELOCITY(uint8_t node_num);
  bool QUICK_STOP_CURRENT_VELOCITY(uint8_t node_num);
//functions used in homing mode/profiled position mode/other modes: not finished yet

####MODIFY HISTORY####

Need your help to build this lib together!




####GOAL FOR NEXT VERSION####
modify more operation modes;
use interrupt to receive CANOpen frames and process them;
add serial interrupt?
use ps4 gamepad to control motors?




END OF FILE

