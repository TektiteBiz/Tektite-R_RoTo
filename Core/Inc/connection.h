/*
 * connection.h
 *
 *  Created on: Jul 19, 2024
 *      Author: nv
 */

#ifndef INC_CONNECTION_H_
#define INC_CONNECTION_H_

#include "peripheral.h"
#include <string.h>

extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);

enum CommandType {
	SELF_TEST,
	TRANSMIT,
	TURN_MOVE,
	READ_CONFIG
};

#pragma pack(1)
typedef struct {
	enum CommandType type;
	float turn;
	int ticks;
	float tw_off;
} Command;

#pragma pack(1)
typedef struct {
	float kp_turn;
	float kp_hold;
	float kp_straight;
	float kp_velocity;

	float turn_accel_time;
	float straight_accel_time;

	float velocity;
	float velocity_twoff;
	float time;
	float vtime;
} Config;


#pragma pack(1)
typedef struct {
	int ready;

	Config config;
	float track_width_ticks;

	int moveCount;
	float turn[256];
	int ticks[256];
	float tw_off[256];
} Data;
extern bool commandAvailable;
extern bool configCommandAvailable;
extern Config configCommand;
extern Command command;


void ConnectionUpdate();

extern Data data;
void ReadData();
void WriteData();




#endif /* INC_CONNECTION_H_ */