# RFID-GATE
Simple RFID tag used door opening project 

The project described in the provided code is an RFID-based door security system that integrates a servo motor to control the door lock mechanism, a Liquid Crystal Display (LCD) to show messages, and a Microcontroller (like an Arduino) to process RFID tags and control the servo motor. Here is a detailed description of the project:
Components Used:

    Arduino Microcontroller: Manages all operations.
    MFRC522 RFID Reader: Reads RFID tags/cards.
    Servo Motor: Controls the door lock mechanism.
    Liquid Crystal Display (LCD): Displays messages to the user.
    SPI Communication Protocol: Used for communication between the Arduino and RFID reader.

Circuit Connections:

    RFID Reader (MFRC522):
        SS_PIN: 10
        RST_PIN: 9
    Servo Motor: Connected to pin 8.
    LCD: Connected to pins 2, 3, 4, 5, 6, and 7.

Functionality:

    Setup Phase:
        Initializes serial communication at a baud rate of 9600.
        Initializes the SPI bus for RFID communication.
        Initializes the RFID reader.
        Sets up the servo motor.
        Initializes the LCD and prints a welcome message "Door Security".

    Loop Phase:
        Continuously checks for the presence of a new RFID card.
        If a new card is detected, reads the card's UID (Unique Identifier) and prints it in the serial monitor.
        Constructs a string from the card's UID to compare with the predefined authorized card ID ("7347132f").
        If the card is authorized:
            Displays "Access Granted" on the LCD.
            Prints "Access Granted" and "Opened" in the serial monitor.
            Rotates the servo motor to 180 degrees to unlock the door.
            Waits for 5 seconds, then rotates the servo motor back to 0 degrees to lock the door again.
            Clears the card ID string for the next iteration.
        If the card is not authorized:
            Prints "Access Denied" in the serial monitor.

Code Explanation:

    setup() Function:
        Initializes all the components.
        Sets up serial communication, SPI, RFID reader, servo motor, and LCD.

    loop() Function:
        Continuously monitors for new RFID cards.
        Reads the UID of the card and compares it to the authorized UID.
        Controls the servo motor and LCD based on the UID match.

Overall Working:

The system provides a secure way to control access to a door using RFID technology. When an RFID card is presented to the reader, the system checks if the card is authorized. If it is, the door unlocks for 5 seconds, allowing access, and then relocks. If the card is not authorized, access is denied, and the door remains locked.

This project can be expanded by adding more authorized card IDs, integrating with a database for dynamic access control, or adding additional security features such as logging access attempts or sending notifications.
