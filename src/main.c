// hackrf lib
#include <libhackrf/hackrf.h>

// std
#include <stdio.h>
#include <stdlib.h>

// Device object
static hackrf_device* device = NULL; 

void rx_cb(hackrf_transfer* transfer) { 
    // receiving function to be implemented
}

int main(int argc, char ** argv) { 
    int result = 0;

    // Init hackrf
    printf("Connecting to hackrf device\n");
    result = hackrf_init();
    if (result != HACKRF_SUCCESS) { 
        fprintf(stderr, "hackrf_init failed %s %d\n", hackrf_error_name(result), result);
        return EXIT_FAILURE;
    }

    // Get device serial number and open
    const char* serial_number = NULL; // TODO Will find a way to do grab device 0 (hackrf_device_list)
    result = hackrf_open_by_serial(serial_number, &device);

    if ((result != HACKRF_SUCCESS) | (serial_number == NULL)) { 
        fprintf(stderr, "hackrf_open failed %s %d\n", hackrf_error_name(result), result);
        return EXIT_FAILURE;
    }
    printf("Successfully opened device\n");

    // Start receiving on hackrf      cb function
    result |= hackrf_start_rx(device, NULL, NULL);
    if (result != HACKRF_SUCCESS) { 
        fprintf(stderr, "hackrf_start_rx() failed %s %d\n", hackrf_error_name(result), result);
        return EXIT_FAILURE;
    }

    // loop for receiving and other functions here

    // Stop hackrf and clean up
    if (device != NULL) { 
        result = hackrf_stop_rx(device);
        if (result != HACKRF_SUCCESS) { 
            fprintf(stderr, "hackrf_stop_rx() failed: %s %d\n", hackrf_error_name(result), result);
        }
        printf("Successfully stopped hackrf device\n");

        hackrf_exit();
    }    

    return 0;
}

