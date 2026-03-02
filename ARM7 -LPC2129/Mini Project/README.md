# 📌 NEXT GEN – ARM Based RFID Voting System

## 1️⃣ Project Overview

This project implements a **Next Generation Voting** using **ARM7 (LPC2129)** microcontroller with **RFID-based voter authentication**.

The system ensures:

* Secure voter verification
* Prevention of duplicate voting
* Double authentication before vote confirmation
* Interrupt-based party selection
* Real-time result display

---

## 2️⃣ Hardware Requirements

* ARM7 Microcontroller (e.g., LPC2129 – NXP LPC21xx family)
* RFID Reader (UART based, 9600 baud) - EM18 
* 16x2 LCD (4-bit mode)
* Push Buttons (Connected to EINT0–EINT3)
* Power Supply (5V regulated)
* Connecting wires & PCB

---

## 3️⃣ Pin Configuration

### 📟 LCD Connections (4-bit mode)

| LCD Pin | LPC21xx Pin   |
| ------- | ------------- |
| D4–D7   | P0.14 – P0.17 |
| RS      | P0.12         |
| E       | P0.13         |

### 📡 RFID (UART1)

| RFID | LPC21xx     |
| ---- | ----------- |
| TX   | P0.9 (RXD1) |
| RX   | P0.8 (TXD1) |

Baud Rate: **9600**

---

### 🔘 Push Buttons (External Interrupts)

| Button   | Interrupt | Function              |
| -------- | --------- | --------------------- |
| Button 1 | EINT1     | Select Party 1 (DDD)  |
| Button 2 | EINT2     | Select Party 2 (AAAA) |
| Button 3 | EINT3     | Select Party 3 (TTT)  |
| Button 4 | EINT0     | Show Results          |

All interrupts are configured in **Falling Edge mode**.

---

## 4️⃣ Software Architecture

The system works using a **state machine**:

```c
#define VERIFY_MODE   0
#define VOTE_MODE     1
#define CONFIRM_MODE  2
#define RESULT_MODE   3
```

### 🔄 System Flow

### 1. VERIFY_MODE

* LCD shows: "SCAN FOR VERIFY"
* RFID card is scanned
* ID is validated

  * If valid → Move to VOTE_MODE
  * If already voted → Show message
  * If invalid → Reject

---

### 2. VOTE_MODE

* LCD displays party list:

  * 1. DDD
  * 2. AAAA
  * 3. TTT
  * 4. RESULTS
* User selects party via interrupt button

---

### 3. CONFIRM_MODE

* System asks user to scan RFID again
* If ID matches:

  * Vote is counted
  * Voter marked as voted
* If mismatch:

  * Vote rejected

---

### 4. RESULT_MODE

* Triggered by EINT0
* Displays:

  * Winning party
  * Or "DRAW"
* System halts after displaying result

---

## 5️⃣ Predefined Voter Database

```c
char Voter_ID[5][14] = {
    "123456780",
    "123456781",
    "123456782",
    "123456783",
    "123456784"
};
```

* Only these IDs are valid
* Each voter can vote only once

---

## 6️⃣ Vote Counting Variables

```c
static int DDD= 0;
static int AAAA = 0;
static int TTT= 0;
```

Votes increment only after:

* Successful verification
* Successful confirmation scan

---

## 7️⃣ Key Functional Modules

### 📡 RFID Module

* Uses UART1
* Reads 13-character ID
* Non-blocking read

### 📟 LCD Module

* 4-bit communication
* Command and Data modes
* Uses delay functions for timing

### ⏱ Delay Module

* Timer0 based delays:

  * Microseconds
  * Milliseconds
  * Seconds

### ⚡ Interrupt Module

* Uses VIC (Vectored Interrupt Controller)
* Edge triggered external interrupts
* Fast party selection

---

## 8️⃣ Security Features

✔ Double RFID scan before vote confirmation
✔ Duplicate vote prevention
✔ Interrupt-driven selection
✔ Result mode accessible only via dedicated button

---

## 9️⃣ How to Run

1. Compile using Keil uVision (ARM7)
2. Flash code into LPC21xx board
3. Power ON system
4. Scan RFID
5. Select party
6. Scan again to confirm
7. Press RESULT button to view winner

---

## 🔟 Expected Output Flow

1. System boot message
2. Scan for verification
3. Verified / Invalid / Already voted
4. Party selection screen
5. Confirmation scan
6. Vote success
7. Result display

---

## 📌 Possible Improvements

* Add EEPROM for permanent vote storage
* Add buzzer for feedback
* Add password-protected result mode
* Add real-time clock (RTC)
* Increase voter database dynamically
* Add candidate display with symbols

---

## 📚 Technologies Used

* Embedded C
* ARM7 Architecture
* UART Communication
* External Interrupt Handling
* Timer-based Delays
* LCD 4-bit Interface

---

# ✅ Conclusion

This project demonstrates a secure and efficient **RFID-based voting system** using ARM7.
It integrates authentication, interrupt handling, real-time vote counting, and result computation in a structured state-machine architecture.
