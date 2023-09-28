/***********************************************************/
/*Author      : Mostafa Ayman                              */
/*Date        : 10 SEP 2023                                */
/*Version     : V1.0                                       */
/*MC          : STM32Fxxx                                  */
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GENRERALTIMERS_interface.h"
#include "GENRERALTIMERS_private.h"
#include "GENRERALTIMERS_config.h"

void MTimer_voidInitMode(uint8 Copy_uint8TimerNo,uint8 Copy_uint8Mode){
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
        switch (Copy_uint8Mode)
        {
        case UP_DOWN_TIMER:
            #if TIMER2_DIRECTION == UP
            CLR_BIT(TIMER2->CR1,4);
            #elif TIMER2_DIRECTION == DOWN
            SET_BIT(TIMER2->CR1,4);
            #endif
            //Update Enable to rise UIF
            CLR_BIT(TIMER2->CR1,1); 
            TIMER2->PSC = TIMER2_PRESCALER;
            break;
        case UP_DOWN_COUNTER:
        /*
        COUNTER CODE  
         */
        break;
        case PWM:
            //SET Direction to down
            CLR_BIT(TIMER2->CR1,4);
            //enable autoreload
            SET_BIT(TIMER2->CR1,7);
            //Set Prescaller
            TIMER2->PSC = TIMER2_PRESCALER;
            //set PWM Frequency
            TIMER2->ARR = PWM2_WIDTH;
            break;
        }
        break;
    case TIMER_3:
    switch (Copy_uint8Mode)
        {
        case UP_DOWN_TIMER:
            #if TIMER3_DIRECTION == UP
            CLR_BIT(TIMER3->CR1,4);
            #elif TIMER3_DIRECTION == DOWN
            SET_BIT(TIMER3->CR1,4);
            #endif
            //Update Enable to rise UIF
            CLR_BIT(TIMER3->CR1,1); 
            TIMER3->PSC = TIMER3_PRESCALER;
            break;
        case UP_DOWN_COUNTER:
        /*
        COUNTER CODE  
         */
        break;
        case PWM:
            //SET Direction to down
            CLR_BIT(TIMER3->CR1,4);
            //enable autoreload
            SET_BIT(TIMER3->CR1,7);
            //Set Prescaller
            TIMER3->PSC = TIMER3_PRESCALER;
            //set PWM Frequency
            TIMER3->ARR = PWM3_WIDTH;
            break;
        }
        break;
    case TIMER_4:
    switch (Copy_uint8Mode)
        {
        case UP_DOWN_TIMER:
            #if TIMER4_DIRECTION == UP
            CLR_BIT(TIMER4->CR1,4);
            #elif TIMER4_DIRECTION == DOWN
            SET_BIT(TIMER4->CR1,4);
            #endif
            //Update Enable to rise UIF
            CLR_BIT(TIMER4->CR1,1); 
            TIMER4->PSC = TIMER4_PRESCALER;
            break;
        case UP_DOWN_COUNTER:
        /*
        COUNTER CODE   
        */
        break;
        case PWM:
            //SET Direction to down
            CLR_BIT(TIMER4->CR1,4);
            //enable autoreload
            SET_BIT(TIMER4->CR1,7);
            //Set Prescaller
            TIMER4->PSC = TIMER4_PRESCALER;
            //set PWM Frequency
            TIMER4->ARR = PWM4_WIDTH;
            break;
        }
        break;
    }
}
void MTimer_voidIntiateuSDelayHold(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    //local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000000;
    local_uint32DelayBufferValue =copy_uint32DelayValue;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //disable autoreload
    CLR_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
    //wait to end waiting
    CLR_BIT(TIMER2->SR,0);
    while(GET_BIT(TIMER2->SR,0) == 0);
    //disable timer
    CLR_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    CLR_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
    while(GET_BIT(TIMER3->SR,0) == 0);
    CLR_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    CLR_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
    while(GET_BIT(TIMER4->SR,0) == 0);
    CLR_BIT(TIMER4->CR1,0);
        break;
    }
}
void MTimer_voidIntiatemSDelayHold(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //disable autoreload
    CLR_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
    //wait to end waiting
    while(GET_BIT(TIMER2->SR,0) == 0);
    //disable timer
    CLR_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    CLR_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
    while(GET_BIT(TIMER3->SR,0) == 0);
    CLR_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    CLR_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
    while(GET_BIT(TIMER4->SR,0) == 0);
    CLR_BIT(TIMER4->CR1,0);
        break;
    }
    
}
void MTimer_voidEnableuSDelayInterrupt_once(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000000;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //enable interrupt
    SET_BIT(TIMER2->DIER,0);
    //disable autoreload
    CLR_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    SET_BIT(TIMER3->DIER,0);
    CLR_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    SET_BIT(TIMER4->DIER,0);
    CLR_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
        break;
    }
}
void MTimer_voidmSEnableDelayInterrupt_once(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //enable interrupt
    SET_BIT(TIMER2->DIER,0);
    //disable autoreload
    CLR_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    SET_BIT(TIMER3->DIER,0);
    CLR_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    SET_BIT(TIMER4->DIER,0);
    CLR_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
        break;
    }
}
void MTimer_voidEnableuSDelayInterrupt_repeat(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000000;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //enable interrupt
    SET_BIT(TIMER2->DIER,0);
    //disable autoreload
    SET_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    SET_BIT(TIMER3->DIER,0);
    SET_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    SET_BIT(TIMER4->DIER,0);
    SET_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
        break;
    }
}
void MTimer_voidmSEnableDelayInterrupt_repeat(uint8 Copy_uint8TimerNo,uint32 copy_uint32DelayValue){
    uint32 local_uint32DelayBufferValue=0;
    local_uint32DelayBufferValue = (copy_uint32DelayValue*GENERAL_TIMRS_FREQUENCY)/1000;
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
    //enable interrupt
    SET_BIT(TIMER2->DIER,0);
    //disable autoreload
    SET_BIT(TIMER2->CR1,7);
    //load autoreload register
    TIMER2->ARR=local_uint32DelayBufferValue;
    //enable timer
    SET_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
    SET_BIT(TIMER3->DIER,0);
    SET_BIT(TIMER3->CR1,7);
    TIMER3->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
    SET_BIT(TIMER4->DIER,0);
    SET_BIT(TIMER4->CR1,7);
    TIMER4->ARR=local_uint32DelayBufferValue;
    SET_BIT(TIMER4->CR1,0);
        break;
    }
}
void MTimer_voidEnable(uint8 Copy_uint8TimerNo){
    switch(Copy_uint8TimerNo)
        {
    case TIMER_2:
        SET_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
        SET_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
        SET_BIT(TIMER3->CR1,0);
        break;    
    }
    
}
void MTimer_voidDisable(uint8 Copy_uint8TimerNo){
    switch(Copy_uint8TimerNo)
        {
    case TIMER_2:
        CLR_BIT(TIMER2->CR1,0);
        break;
    case TIMER_3:
        CLR_BIT(TIMER3->CR1,0);
        break;
    case TIMER_4:
        CLR_BIT(TIMER3->CR1,0);
        break;    
    }
}
void MTIMER_SetPwm_CH_DutyCycle(uint32 Copy_uint32DutyCycle,uint8 Copy_uint8TimerNo,uint8 Copy_uint8TimerChannel){
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2 :
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
        //set the PWM mode to mode 1
        CLR_BIT(TIMER2->CCMR1,4);
        SET_BIT(TIMER2->CCMR1,5);
        SET_BIT(TIMER2->CCMR1,6);
        //enable output pin
			SET_BIT(TIMER2->CCER,CC1E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER2->CCMR1,OC1PE);
        //set duty cycle
            TIMER2->CCR1=Copy_uint32DutyCycle;
            break;
        case CHANNEL_2:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER2->CCMR1,12);
    		SET_BIT(TIMER2->CCMR1,13);
        	SET_BIT(TIMER2->CCMR1,14);
         //enable output pin
			SET_BIT(TIMER2->CCER,CC2E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER2->CCMR1,OC2PE);
        //set duty cycle
            TIMER2->CCR2=Copy_uint32DutyCycle;
            break;
        case CHANNEL_3:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER2->CCMR2,4);
    		SET_BIT(TIMER2->CCMR2,5);
        	SET_BIT(TIMER2->CCMR2,6);
         //enable output pin
			SET_BIT(TIMER2->CCER,CC3E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER2->CCMR2,OC3PE);
        //set duty cycle
            TIMER2->CCR3=Copy_uint32DutyCycle;
            break;
        case CHANNEL_4:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER2->CCMR2,12);
    		SET_BIT(TIMER2->CCMR2,13);
        	SET_BIT(TIMER2->CCMR2,14);
         //enable output pin
			SET_BIT(TIMER2->CCER,CC4E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER2->CCMR2,OC4PE);
        //set duty cycle
            TIMER2->CCR4=Copy_uint32DutyCycle;
        break;
        }
        //set update generation to make sure that the timer work imediatly without any delay
           SET_BIT(TIMER2->EGR,UG);
        //enable timer
	    SET_BIT(TIMER2->CR1,CEN);
        break;
    case TIMER_3 :
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
            //set the PWM mode to mode 1
            CLR_BIT(TIMER3->CCMR1,4);
            SET_BIT(TIMER3->CCMR1,5);
            SET_BIT(TIMER3->CCMR1,6);
        //enable output pin
			SET_BIT(TIMER3->CCER,CC1E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER3->CCMR1,OC1PE);
        //set duty cycle
            TIMER3->CCR1=Copy_uint32DutyCycle;
            break;
        case CHANNEL_2:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER3->CCMR1,12);
    		SET_BIT(TIMER3->CCMR1,13);
        	SET_BIT(TIMER3->CCMR1,14);
         //enable output pin
			SET_BIT(TIMER3->CCER,CC2E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER3->CCMR1,OC2PE);
        //set duty cycle
            TIMER3->CCR2=Copy_uint32DutyCycle;
            break;
        case CHANNEL_3:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER3->CCMR2,4);
    		SET_BIT(TIMER3->CCMR2,5);
        	SET_BIT(TIMER3->CCMR2,6);
         //enable output pin
			SET_BIT(TIMER3->CCER,CC3E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER3->CCMR2,OC3PE);
        //set duty cycle
            TIMER3->CCR3=Copy_uint32DutyCycle;
            break;
        case CHANNEL_4:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER3->CCMR2,12);
    		SET_BIT(TIMER3->CCMR2,13);
        	SET_BIT(TIMER3->CCMR2,14);
         //enable output pin
			SET_BIT(TIMER3->CCER,CC4E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER3->CCMR2,OC4PE);
        //set duty cycle
            TIMER3->CCR4=Copy_uint32DutyCycle;
        break;
        }
        //set update generation to make sure that the timer work imediatly without any delay
         SET_BIT(TIMER3->EGR,UG);
        //enable timer
	    SET_BIT(TIMER3->CR1,CEN);
        break;
    case TIMER_4 :
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
            //set the PWM mode to mode 1
            CLR_BIT(TIMER4->CCMR1,4);
            SET_BIT(TIMER4->CCMR1,5);
            SET_BIT(TIMER4->CCMR1,6);
        //enable output pin
			SET_BIT(TIMER4->CCER,CC1E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER4->CCMR1,OC1PE);
        //set duty cycle
            TIMER4->CCR1=Copy_uint32DutyCycle;
            break;
        case CHANNEL_2:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER4->CCMR1,12);
    		SET_BIT(TIMER4->CCMR1,13);
        	SET_BIT(TIMER4->CCMR1,14);
         //enable output pin
			SET_BIT(TIMER4->CCER,CC2E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER4->CCMR1,OC2PE);
        //set duty cycle
            TIMER4->CCR2=Copy_uint32DutyCycle;
            break;
        case CHANNEL_3:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER4->CCMR2,4);
    		SET_BIT(TIMER4->CCMR2,5);
        	SET_BIT(TIMER4->CCMR2,6);
         //enable output pin
			SET_BIT(TIMER4->CCER,CC3E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER4->CCMR2,OC3PE);
        //set duty cycle
            TIMER4->CCR3=Copy_uint32DutyCycle;
            break;
        case CHANNEL_4:
        	//set the PWM mode to mode 1
        	CLR_BIT(TIMER4->CCMR2,12);
    		SET_BIT(TIMER4->CCMR2,13);
        	SET_BIT(TIMER4->CCMR2,14);
         //enable output pin
			SET_BIT(TIMER4->CCER,CC4E);
		//Output compare 1 preload enable
		    SET_BIT(TIMER4->CCMR2,OC4PE);
        //set duty cycle
            TIMER4->CCR4=Copy_uint32DutyCycle;
        break;
        }
        //set update generation to make sure that the timer work imediatly without any delay
        SET_BIT(TIMER4->EGR,UG);
        //enable timer
	    SET_BIT(TIMER4->CR1,CEN);
        break;
    }
        /*configure GPIO
*/
}
void MTIMER_DISABLEPwm_CH_DutyCycle(uint8 Copy_uint8TimerNo,uint8 Copy_uint8TimerChannel){
    switch (Copy_uint8TimerNo)
    {
    case TIMER_2:
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
             //enable output pin
			CLR_BIT(TIMER2->CCER,CC1E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER2->CCR1,OC1PE);
            break;
        case CHANNEL_2:
             //enable output pin
			CLR_BIT(TIMER2->CCER,CC2E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER2->CCR1,OC2PE);
            break;
        case CHANNEL_3:
             //enable output pin
			CLR_BIT(TIMER2->CCER,CC3E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER2->CCR2,OC3PE);
            break;
        case CHANNEL_4:
             //enable output pin
			CLR_BIT(TIMER2->CCER,CC4E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER2->CCR2,OC4PE);
            break;
        }
        break;
    case TIMER_3:
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
             //enable output pin
			CLR_BIT(TIMER3->CCER,CC1E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER3->CCR1,OC1PE);
            break;
        case CHANNEL_2:
             //enable output pin
			CLR_BIT(TIMER3->CCER,CC2E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER3->CCR1,OC2PE);
            break;
        case CHANNEL_3:
             //enable output pin
			CLR_BIT(TIMER3->CCER,CC3E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER3->CCR2,OC3PE);
            break;
        case CHANNEL_4:
             //enable output pin
			CLR_BIT(TIMER3->CCER,CC4E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER3->CCR2,OC4PE);
            break;
        }
        break;
    case TIMER_4:
        switch (Copy_uint8TimerChannel)
        {
        case CHANNEL_1:
             //enable output pin
			CLR_BIT(TIMER4->CCER,CC1E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER4->CCR1,OC1PE);
            break;
        case CHANNEL_2:
             //enable output pin
			CLR_BIT(TIMER4->CCER,CC2E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER4->CCR1,OC2PE);
            break;
        case CHANNEL_3:
             //enable output pin
			CLR_BIT(TIMER4->CCER,CC3E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER4->CCR2,OC3PE);
            break;
        case CHANNEL_4:
             //enable output pin
			CLR_BIT(TIMER4->CCER,CC4E);
	    	//Output compare 1 preload enable
		    CLR_BIT(TIMER4->CCR2,OC4PE);
            break;
        }
        break;

    }
}
/***Finished***
 * 			*Timers counting up-down Mode
 * 			*PWM Mode
 ***Remains***
 	 	 	 *Pulse measure
 * if u have any comment Please روح ل امك تعمله
 * */

void MTimer_voidInitInputCapture(uint8 Copy_uint8TimerNo,uint8 Copy_uint8ChannelNo){
    switch (Copy_uint8TimerNo)
{
    case TIMER_2:
        switch (Copy_uint8ChannelNo)
        {
        case CHANNEL_1:
            //set the capture to input capture
            TIMER2->CCMR1 |= (0b01);
            //set the capture duration
            TIMER2->CCMR1 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            #if  TIMER2_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER2->CCER,1);
            #elif TIMER2_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER2->CCER,1);
            #endif
            //set the input prescaller
            TIMER2->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            SET_BIT(TIMER2->CCER,0);
            
            break;
        case CHANNEL_2:
            //set the capture to input capture
            //CC2S
            TIMER2->CCMR1 |= (0b01<<8);
            //set the capture duration
            //IC2F
            TIMER2->CCMR1 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC2P
            #if  TIMER2_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER2->CCER,5);
            #elif TIMER2_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER2->CCER,5);
            #endif
            //set the input prescaller
            //IC2PSC
            TIMER2->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC2E
            SET_BIT(TIMER2->CCER,4);

            
            break;
        case CHANNEL_3:
            //set the capture to input capture
            //CC3S
            TIMER2->CCMR2 |= (0b01);
            //set the capture duration
            //IC3F
            TIMER2->CCMR2 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            //CC3P
            #if  TIMER2_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER2->CCER,9);
            #elif TIMER2_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER2->CCER,9);
            #endif
            //set the input prescaller
            //IC3PSC
            TIMER2->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            //CC3E
            SET_BIT(TIMER2->CCER,8);
            break;
        case CHANNEL_4:
            //set the capture to input capture
            //CC4S
            TIMER2->CCMR2 |= (0b01<<8);
            //set the capture duration
            //IC4F
            TIMER2->CCMR2 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC4P
            #if  TIMER2_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER2->CCER,13);
            #elif TIMER2_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER2->CCER,13);
            #endif
            //set the input prescaller
            //IC4PSC
            TIMER2->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC4E
            SET_BIT(TIMER2->CCER,12);
            break;
        }
        #if TIMER2_DIRECTION == UP
            CLR_BIT(TIMER2->CR1,4);
            #elif TIMER2_DIRECTION == DOWN
            SET_BIT(TIMER2->CR1,4);
            #endif

            TIMER2->PSC = TIMER2_PRESCALER;
            //enable autoreload
            SET_BIT(TIMER2->CR1,7);
    break;
    case TIMER_3:
    switch (Copy_uint8ChannelNo)
        {
        case CHANNEL_1:
            //set the capture to input capture
            TIMER3->CCMR1 |= (0b01);
            //set the capture duration
            TIMER3->CCMR1 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            #if  TIMER3_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER3->CCER,1);
            #elif TIMER3_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER3->CCER,1);
            #endif
            //set the input prescaller
            TIMER3->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            SET_BIT(TIMER3->CCER,0);
            
            break;
        case CHANNEL_2:
            //set the capture to input capture
            //CC2S
            TIMER3->CCMR1 |= (0b01<<8);
            //set the capture duration
            //IC2F
            TIMER3->CCMR1 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC2P
            #if  TIMER3_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER3->CCER,5);
            #elif TIMER3_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER3->CCER,5);
            #endif
            //set the input prescaller
            //IC2PSC
            TIMER3->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC2E
            SET_BIT(TIMER3->CCER,4);

            
            break;
        case CHANNEL_3:
            //set the capture to input capture
            //CC3S
            TIMER3->CCMR2 |= (0b01);
            //set the capture duration
            //IC3F
            TIMER3->CCMR2 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            //CC3P
            #if  TIMER3_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER3->CCER,9);
            #elif TIMER3_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER3->CCER,9);
            #endif
            //set the input prescaller
            //IC3PSC
            TIMER3->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            //CC3E
            SET_BIT(TIMER3->CCER,8);
            break;
        case CHANNEL_4:
            //set the capture to input capture
            //CC4S
            TIMER3->CCMR2 |= (0b01<<8);
            //set the capture duration
            //IC4F
            TIMER3->CCMR2 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC4P
            #if  TIMER3_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER3->CCER,13);
            #elif TIMER3_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER3->CCER,13);
            #endif
            //set the input prescaller
            //IC4PSC
            TIMER3->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC4E
            SET_BIT(TIMER3->CCER,12);
            break;
        }
        #if TIMER3_DIRECTION == UP
            CLR_BIT(TIMER3->CR1,4);
            #elif TIMER3_DIRECTION == DOWN
            SET_BIT(TIMER3->CR1,4);
            #endif

            TIMER3->PSC = TIMER3_PRESCALER;
            //enable autoreload
            SET_BIT(TIMER3->CR1,7);

    break;
    case TIMER_4:
        switch (Copy_uint8ChannelNo)
        {
        case CHANNEL_1:
            //set the capture to input capture
            TIMER4->CCMR1 |= (0b01);
            //set the capture duration
            TIMER4->CCMR1 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            #if  TIMER4_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER4->CCER,1);
            #elif TIMER4_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER4->CCER,1);
            #endif
            //set the input prescaller
            TIMER4->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            SET_BIT(TIMER4->CCER,0);
            
            break;
        case CHANNEL_2:
            //set the capture to input capture
            //CC2S
            TIMER4->CCMR1 |= (0b01<<8);
            //set the capture duration
            //IC2F
            TIMER4->CCMR1 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC2P
            #if  TIMER4_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER4->CCER,5);
            #elif TIMER4_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER4->CCER,5);
            #endif
            //set the input prescaller
            //IC2PSC
            TIMER4->CCMR1 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC2E
            SET_BIT(TIMER4->CCER,4);

            
            break;
        case CHANNEL_3:
            //set the capture to input capture
            //CC3S
            TIMER4->CCMR2 |= (0b01);
            //set the capture duration
            //IC3F
            TIMER4->CCMR2 |= (INPUT_CHECK_DURATION<<4);
            //select the capture edge rising/falling
            //CC3P
            #if  TIMER4_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER4->CCER,9);
            #elif TIMER4_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER4->CCER,9);
            #endif
            //set the input prescaller
            //IC3PSC
            TIMER4->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<2);
            //enable capture from the counter
            //CC3E
            SET_BIT(TIMER4->CCER,8);
            break;
        case CHANNEL_4:
            //set the capture to input capture
            //CC4S
            TIMER4->CCMR2 |= (0b01<<8);
            //set the capture duration
            //IC4F
            TIMER4->CCMR2 |= (INPUT_CHECK_DURATION<<12);
            //select the capture edge rising/falling
            //CC4P
            #if  TIMER4_CHANNEL_1_CAPTURE_EDGE == RISING
            CLR_BIT(TIMER4->CCER,13);
            #elif TIMER4_CHANNEL_1_CAPTURE_EDGE == FALLING
            SET_BIT(TIMER4->CCER,13);
            #endif
            //set the input prescaller
            //IC4PSC
            TIMER4->CCMR2 |= (INPUT_CAPTURE_CHANNEL_1_PRESCALLER<<10);
            //enable capture from the counter
            //CC4E
            SET_BIT(TIMER4->CCER,12);
            break;
        }
        #if TIMER4_DIRECTION == UP
            CLR_BIT(TIMER4->CR1,4);
            #elif TIMER4_DIRECTION == DOWN
            SET_BIT(TIMER4->CR1,4);
            #endif

            TIMER4->PSC = TIMER4_PRESCALER;
            //enable autoreload
            SET_BIT(TIMER4->CR1,7);
    break;
}
}

