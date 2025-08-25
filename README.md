# Signal Handlers Project

## Overview

This project consists of three C programs that demonstrate signal handling in Unix/Linux systems:

1. **my_c_signal_handler.c** - A program that handles SIGALRM signals to print periodic status updates
2. **my_div0_handler.c** - A program to handle division by zero signals (SIGFPE)
3. **send_signal.c** - A utility program to send signals to other processes

## Files

### my_c_signal_handler.c

A signal handler program that:
- Sets up a SIGALRM handler to print the current process ID and time every 5 seconds
- Runs in an infinite loop until terminated with Ctrl-C
- Demonstrates proper signal handling using `sigaction()`

**Key Features:**
- Uses `alarm()` to schedule periodic signals
- Implements a clean SIGALRM handler with time display
- Properly initializes the `sigaction` structure

### my_div0_handler.c

**Note:** This file is currently a stub implementation. The division by zero signal handler functionality needs to be implemented.

Planned functionality:
- Handle SIGFPE signals caused by division by zero operations
- Provide informative error messages when division errors occur
- Demonstrate exception handling through signals

### send_signal.c

A utility program to send signals to other processes:
- Provides a command-line interface for sending specific signals to target processes
- Displays usage instructions for proper command syntax
- Intended for testing signal handlers in other programs

**Usage:**
```bash
./send_signal <signal_type> <pid>
```

## Building the Project

Compile each program separately:

```bash
gcc -o my_c_signal_handler my_c_signal_handler.c
gcc -o my_div0_handler my_div0_handler.c
gcc -o send_signal send_signal.c
```

## Usage Examples

1. **Run the alarm signal handler:**
   ```bash
   ./my_c_signal_handler
   ```

2. **Send a signal to a process (replace <pid> with actual process ID):**
   ```bash
   ./send_signal SIGALRM <pid>
   ```

## Signal Types Supported

The programs are designed to handle:
- `SIGALRM` - Alarm clock signal (used for periodic tasks)
- `SIGFPE` - Floating-point exception (division by zero)
- `SIGINT` - Interrupt signal (Ctrl-C termination)

## Implementation Details

### Signal Handling Approach
- Uses the modern `sigaction()` system call instead of the older `signal()` function
- Properly initializes signal handler structures with `memset()`
- Includes error checking for signal binding operations

### Time Handling
- Uses `time()` and `ctime()` functions for timestamp generation
- Maintains a 5-second interval between signal generations

## Error Handling

All programs include basic error checking for:
- Signal handler registration failures
- Invalid command-line arguments (in send_signal)
- System call failures

## Development Notes

- **my_div0_handler.c** requires implementation of division by zero handling
- **send_signal.c** needs to be expanded to parse command-line arguments and actually send signals
- Consider adding more robust error handling and user feedback
