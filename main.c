#include <DAVE.h>           // Include DAVE App library
#include "FREERTOS/task.h"         // Include task management functions
#include<stdio.h>


uint8_t can_data_arr;
uint8_t *array_data;

uint8_t uart_data;


uint8_t spi_data;

void vTask1(void *pvParameters) {
    while(1) {
        // Toggle the LED
    	array_data = can_data_arr;
    	UART_Receive(&UART_0, &uart_data, sizeof(uart_data));
    	XMC_CAN_MO_t* lmsgobjct_ptr_0 = CAN_NODE_0.lmobj_ptr[0]->mo_ptr;
    	CAN_NODE_STATUS_t status_1; // variable for struct
    	    const CAN_NODE_t *HandlePtr1 = &CAN_NODE_0;
    	    (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(HandlePtr1->lmobj_ptr[0],array_data);
    	    memcpy(&lmsgobjct_ptr_0->can_data_byte, &uart_data,1);
    	    CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);
        DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
       // can_data_arr[1]=1;
        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1000 milliseconds

    }
}


// Task function for Task 2
void vTask2(void *pvParameters) {
    while(1) {


    	UART_Receive(&UART_0, &uart_data, sizeof(uart_data));
    	memcpy(&spi_data, &uart_data,8);

    	SPI_MASTER_Transmit(&SPI_MASTER_0,&spi_data, sizeof(spi_data));

        // Turn on the LED
        DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_2);

        vTaskDelay(pdMS_TO_TICKS(250));   // Delay for 250 milliseconds

        // Turn off the LED
        DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);

        vTaskDelay(pdMS_TO_TICKS(250));   // Delay for 250 milliseconds
    }
}

int main(void) {
    // Initialize the DAVE Apps
    DAVE_STATUS_t status;

     status = DAVE_Init();    // Initialize DAVE Apps

    // Check for initialization errors
    if(status != DAVE_STATUS_SUCCESS) {
        // Initialization failed
        while(1) {}
    }

    // Create Task 1
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);



    // Create Task 3
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);


    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    while(1) {
    }
}
