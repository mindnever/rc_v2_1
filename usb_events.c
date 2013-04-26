#include <avr/io.h>    //This contains definitions for all the registers locations and some other things, must always be included
#include <avr/wdt.h>
#include <avr/power.h>
#include <util/delay.h>        //Contains some delay functions that will generate accurate delays of ms and us

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Platform/Platform.h>

#include "ra6963.h"

#include "led.h"

#include "usb_proto.h"
#include "main.h"

/** Event handler for the USB_Connect event. This indicates that the device is enumerating via the status LEDs. */
void EVENT_USB_Device_Connect(void)
{
	/* Indicate USB enumerating */
	LED_ON( LED_A );
}

/** Event handler for the USB_Disconnect event. This indicates that the device is no longer connected to a host via
 *  the status LEDs.
 */
void EVENT_USB_Device_Disconnect(void)
{
	/* Indicate USB not ready */
	LED_OFF( LED_A );
}

/** Event handler for the USB_ConfigurationChanged event. This is fired when the host set the current configuration
 *  of the USB device after enumeration - the device endpoints are configured.
 */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;

	/* Setup Vendor Data Endpoints */
//	ConfigSuccess &= Endpoint_ConfigureEndpoint(VENDOR_IN_EPADDR,  EP_TYPE_BULK, VENDOR_IO_EPSIZE, 1);
//	ConfigSuccess &= Endpoint_ConfigureEndpoint(VENDOR_OUT_EPADDR, EP_TYPE_BULK, VENDOR_IO_EPSIZE, 1);

	/* Indicate endpoint configuration success or failure */
//	LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
        LED_ON( LED_B );
}

/** Event handler for the USB_ControlRequest event. This is used to catch and process control requests sent to
 *  the device from the USB host before passing along unhandled control requests to the library for processing
 *  internally.
 */

void EVENT_USB_Device_ControlRequest(void)
{
    
//	DEBUGF("EVENT_USB_Device_ControlRequest called!\n");
	// Process vendor specific control requests here

	if(((USB_ControlRequest.bmRequestType & CONTROL_REQTYPE_TYPE) == REQTYPE_CLASS)
		&& ((USB_ControlRequest.bmRequestType & CONTROL_REQTYPE_RECIPIENT) == REQREC_DEVICE))
	{
//DEBUGF("EVENT_USB_Device_ControlRequest bRequest = %d\n", USB_ControlRequest.bRequest );

                switch( USB_ControlRequest.bRequest )
                {
#if 0
                        case GEN1_USBREQ_TRANSFER:
                                Endpoint_ClearSETUP();

                                genLen = MIN( GEN_BUFFER_SIZE, USB_ControlRequest.wLength);
                                
                                if( (USB_ControlRequest.bmRequestType & CONTROL_REQTYPE_DIRECTION) == REQDIR_HOSTTODEVICE )
                                {
                                        uint8_t buf [ genLen ];
                                        
                                        Endpoint_Read_Control_Stream_LE( buf, genLen );
                                        
                                        genRate = USB_ControlRequest.wValue;
                                        
                                        Endpoint_ClearIN();
                                }
                                else // not really supported??
                                {
//                                        Endpoint_Write_Control_Stream_LE( genInput, genLen );
                                        
                                        Endpoint_ClearOUT();
                                }

                                break;
#endif
                                
                        case USBREQ_RCV21_SYS_RESET:
                                wdt_enable(WDTO_250MS);
                                for(;;) { }
                                break;
                        case USBREQ_RCV21_SYS_HALT:
                                Endpoint_ClearSETUP();
                                sys_halt();
                                Endpoint_ClearStatusStage();
                                break;
                        case USBREQ_RCV21_SYS_RESUME:
                                Endpoint_ClearSETUP();
                                sys_resume();
                                Endpoint_ClearStatusStage();
                                break;
                        case USBREQ_RCV21_LCD_COMMAND:
                                {
                                        Endpoint_ClearSETUP();
                                        
//                                        uint8_t ret = lc7981Cmd( USB_ControlRequest.wIndex, USB_ControlRequest.wValue );
                                        uint8_t ret = 0;
                                        
                                        Endpoint_Write_Control_Stream_LE( &ret, 1 );
                                        
                                        Endpoint_ClearOUT();
                                }
                                break;
                        default:;
//                                DEBUGF( "Unhandled bRequest\n" );
                }
        

//		Endpoint_ClearStatusStage(); // mark the whole request as successful
	}
}
