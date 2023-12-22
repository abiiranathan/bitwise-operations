// Bitwise operators (5)

/**
 Bitwise AND (&)
 Bitwise OR  (|)
 Bitwise Complement/Negation Operator (~)
 Bitwise Left shift(<<) and right shift(>>) operators
 Bitwise XOR(^)
 */
#include <stdint.h>
#include <stdio.h>
void efficientMemoryAlloc();

unsigned char A, B, C;  // 8-bit number(1 byte)

int main() {
  // Bitwise AND
  A = 0x66;   // 01100110;
  B = 0xB3;   // 10110011;
  C = A & B;  // 00100010(0x22)

  // Bitwise OR
  A = 0x64;   // 01100100
  B = 0x10;   // 00010000
  C = A | B;  // 01110100 (0x74)

  // Bitwise XOR (If same, its 0 otherwise its a 1)
  A = 0x64;   // 01100100
  B = 0xB3;   // 10110011
  C = A ^ B;  // 11010111

  // Bitwise Complement (Negate bits)
  A = 0x64;  // 01100100 (0x64)
  B = ~A;    // 10011011 (0x9B)

  // Shift operators
  // A >> B (Right shift A by B bit positions)
  // A << B (Left shift A by B bit positions)
  // Vacated bit are filled by zeros
  // Fast way to multiply/devide any number by power of 2.

  A = 0x3B;    // 00111011
  B = A << 2;  // 11101100 (0xEC) (Same as B=A*4)

  A = 0x96;    // 10010110
  B = A >> 4;  // 00001001 (0x9) (Same as B=A/4)

  // Bit masking
  // Avoid direct assignment of values to registers that would otherwise
  // override all bits.
  // Consider an 8-bit register REGT_8b (11100000) (0xE0)
  // if each bit represents an LED, to turn on LED 2 (Bit 2)
  unsigned char REGT_8b = 0xE0;

  REGT_8b |= 1 << 2;  // turns on LED2

  // To turn off LED6
  REGT_8b &= ~(1 << 6);


  // Turn off LED 0 and 5
  // Assuming current register bits: 11100011
  REGT_8b &= ~((1 << 2) | (1 << 5));

  // Turn on LED 3 and 4
  REGT_8b |= ((1 << 3) | (1 << 4));

  // Turn on LED 3 and off LED 7
  REGT_8b = (REGT_8b | (1 << 3)) & (~(1 << 7));

  // ======================= Bit extraction ========================
  // Assume REGHL_16 is a 16 bit register.
  // Assume the current value is:
  // 1000000110101011
  // We can extract the lower 8 bits and upper 8 bits into REGH_8
  uint16_t REGHL_16;
  REGHL_16 = 0b1000000110101011;

  // Extract upper 8 bits by AND operation and left shift by 8
  REGT_8b = (REGHL_16 & 0xFF00) >> 8;  // 10000001

  // Extract lower 8 bits
  REGT_8b = (REGHL_16 & 0xFF00);  // 10101011

  // More advanced and real world examples
  // Bit Manipulation for GPIO Handling:
  // In embedded systems, GPIO (General Purpose Input/Output) pins
  // are often controlled using bitwise operations.
  // You can set, clear, toggle, or read individual bits to control
  // various peripherals or interact with external devices.

// Assuming GPIO_PORT is the register representing the GPIO port
#define GPIO_PIN_2 (1 << 2)

  volatile uint32_t GPIO_PORT = 0x40020000;

  // Set Pin 2 to HIGH
  GPIO_PORT |= GPIO_PIN_2;

  // Clear Pin 2
  GPIO_PORT &= ~GPIO_PIN_2;

  // Toggle Pin 2
  GPIO_PORT ^= GPIO_PIN_2;

  // Read the state of Pin 2
  if (GPIO_PORT & GPIO_PIN_2) {
    // Pin 2 is HIGH
  } else {
    // Pin 2 is LOW
  }


  // Bitwise Operations for Device Configuration:
  // Bitwise operations are frequently used for configuring device registers.
  // Many embedded peripherals are controlled by setting or clearing specific
  // bits in configuration registers.

  // Assume a configuration register for a Timer/Counter
  volatile uint32_t TIMER_CONFIG_REG = 0x40001000;

  // Enable Timer with Prescaler 64
  TIMER_CONFIG_REG |= (1 << 0) | (1 << 3) | (1 << 4);

  // Disable Timer
  TIMER_CONFIG_REG &= ~(1 << 0);

  // Bitwise Operations for Efficient Data Storage
  // In resource-constrained embedded systems, memory efficiency is crucial.
  // Bitwise operations can be used for compact data storage and retrieval.

  // Assume a data structure representing flags with limited memory
  struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
  };

  struct Flags myFlags;
  myFlags.flag1 = 1;
  myFlags.flag2 = 0;
  myFlags.flag3 = 0;
  myFlags.flag4 = 1;

  //   Bitwise Operations for Protocol Implementation:
  // When working with communication protocols like I2C or SPI,
  // bitwise operations are often used to encode and decode protocol-specific data.

  // Assume a byte representing data to be sent over SPI
  uint8_t spiData = 0b11011010;

  // Extract specific bits for configuration
  uint8_t configBits = (spiData >> 3) & 0x0F;

  // Modify specific bits for transmission
  spiData |= (1 << 1);  // Set a flag in the data byte

  efficientMemoryAlloc();
}

void efficientMemoryAlloc() {
// Define flags using bitwise operations
#define FLAG_READ  (1 << 0)
#define FLAG_WRITE (1 << 1)
#define FLAG_EXEC  (1 << 2)

  // Assume a memory pool represented by an array of bytes
  uint8_t memoryPool[256];


  // Allocate 4 bytes in the memory pool
  uint8_t* allocatedMemory = &memoryPool[0];

  // Set flags using bitwise OR
  uint8_t permissions = FLAG_READ | FLAG_WRITE;

  // Apply permissions to the allocated memory
  *allocatedMemory |= permissions;

  // Check if READ permission is set
  if (*allocatedMemory & FLAG_READ) {
    printf("Read permission is granted.\n");
  }

  // Check if WRITE permission is set
  if (*allocatedMemory & FLAG_WRITE) {
    printf("Write permission is granted.\n");
  }

  // Check if EXECUTE permission is set
  if (*allocatedMemory & FLAG_EXEC) {
    printf("Execute permission is granted.\n");
  } else {
    printf("Execute permission is not granted.\n");
  }
}