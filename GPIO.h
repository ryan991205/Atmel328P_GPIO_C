#ifndef GPIO_H
#define GPIO_H

/*! \file GPIO.h
	\brief GPIO Control for the Atmel328P microcontroller
	Can control all IO using standard read/write function.

	AUTHOR		: Ryan Vrosch
	DATE		: 01-04-2020
	VER			: V1.0.1
*/

#ifdef Arduino_h
	#include <Arduino.h>
#endif

#ifndef Arduino_h
	#include <inttypes.h>

	// Logic levels
	#define	LOW					0x00
	#define HIGH				0x01

	// Port Directions
	#define INPUT				0x00
	#define OUTPUT				0x01
	#define INPUT_PULLUP		0x02
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {		/* GPIO Structure */
	uint8_t DIR;		// 
	uint8_t PORT;		//
	uint8_t PIN;		//  
} GPIO;


// Ports 
#define PORT_B				0x00	// Port B is an 8-bit bi-directional I/O port with internal pull-up resistors.		Port B has better driving capabilities than the other ports. */
#define PORT_C				0x01	// Port C is an 8-bit bi-directional I/O port with internal pull-up resistors.		Only bits 6 and 7 are present on the product pinout.
#define PORT_D				0x02	// Port D is an 8-bit bi-directional I/O port with internal pull-up resistors.

// GPIO EXTERNAL_INT_MASK_R
#define GPIO_INT1_REQ_ENABLE_M	(1UL << 1)
#define GPIO_INT0_REQ_ENABLE_M	(1UL << 0)

// Interrupt types on INT0 and INT1
#define LOWLEVEL			0x00
#define ANY_CHANGE			0x01
#define FALLING_EDGE		0x02
#define RISING_EDGE			0x03

// Initialisation GPIO
void	GPIO_InitPin(GPIO *data, uint8_t _dataDirection, uint8_t _port, uint8_t _pin);
void	GPIO_InitPinFromStruct(const GPIO *data);
void	GPIO_InitPort(uint8_t _port, uint8_t _portVal, uint8_t _directionVal, uint8_t _pinVal);

// Standard GPIO functions
inline uint8_t	GPIO_PinRead(const GPIO *data);
inline void	GPIO_PinWrite(const GPIO *data, uint8_t level);
inline void GPIO_PinToggle(const GPIO *data);
inline uint8_t GPIO_PortRead(uint8_t _port);
inline void	GPIO_PortWrite(uint8_t portValue, uint8_t _port);
uint8_t GPIO_getArduinoPin(const GPIO* data); // V1.0.1_HMV only


// Interrupt control for level INT pins
void	GPIO_InitInterrupt(GPIO *data, uint8_t _triggerType);
void	GPIO_EnableInterrupt(GPIO *data);
void	GPIO_DisableInterrupt(GPIO *data);

 
#ifdef __cplusplus
} // extern "C"
#endif
#endif