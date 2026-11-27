
#ifndef dio_interface_c_h
#define dio_interface_c_h

#define dio_portA            0u
#define dio_portB            1u
#define dio_portC            2u
#define dio_portD            3u

#define dio_pin0             0u
#define dio_pin1             1u
#define dio_pin2             2u
#define dio_pin3             3u
#define dio_pin4             4u
#define dio_pin5             5u
#define dio_pin6             6u
#define dio_pin7             7u

#define dio_input            0u
#define dio_output           1u
#define dio_port_input       0x00
#define dio_port_output      0xFF

#define dio_high             1u      
#define dio_low              0u      
#define dio_port_high        0xff              
#define dio_port_low         0x00      
    

typedef enum
{
    dio_invalid_pin,
    dio_invalid_port,
    dio_invalid_dir,
    dio_invalid_value,
    dio_ok,
    dio_nok
}dio_errors;


dio_errors dio_enum_set_pin_direction(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_direction);
dio_errors dio_enum_set_pin_value(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_value);
dio_errors dio_enum_get_pin_value(u8 copy_u8_port, u8 copy_u8_pin, u8 *copy_ptr_pin_direction);

#endif 