# Bus Passenger Allocation

This project contains a program that manages the seating arrangement of passengers for a tour organized by a travel company. Passengers are seated in each bus starting from the front row to the back row. A new bus is allocated once the current bus is full. A maximum of 8 buses can be allocated, and each bus has 8 seats.

## Features

- Passengers are seated in order from the front row to the back row in each bus.
- A new bus is allocated once the current bus is full.
- A maximum of 8 buses can be allocated.
- Each seat holds the passenger's first name, last name, and seat number.

## Data Structures Used

- **Stack**: Used for managing the allocation of new buses and handling full buses.
- **List**: Used for managing the seats and passengers within each bus.

## Usage

By running this program, you can manage the seating of passengers on buses and view the list of passengers for each bus.

### Compilation and Execution

To compile and run the program, follow these steps:

```sh
gcc main.c -o bus_allocation
./bus_allocation
