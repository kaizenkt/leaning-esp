
#include "osapi.h"
#include "user_interface.h"

void ICACHE_FLASH_ATTR  user_esp_plartform_check_ip(void)
{

}
void ICACHE_FLASH_ATTR user_set_station_config()
{
  //Wifi configuration
  char ssid[32] = SSID;
  char password[64] = PASSWORD;
  struct station_config stationCof; //Station relate struct
  //set value of memory: 1.pointer of memory 2.set value 3. size
  os_memset(stationCof.ssid,  0,  32);
  os_memset(stationCof.password,  0,  64);
  //need not mac address
  stationCof.bssid_set  = 0;

  //Set ap settings
  os_memcpy(&stationCof.ssid, ssid, 32);
  os_memcpy(&stationCof.password, password, 64);
  wifi_station_set_config(&stationCof);
  

}
void ICACHE_FLASH_ATTR user_init(void)
{
  uart_div_modify(0, UART_CLK_FREQ  / 115200);
  os_printf("SDK version:%s\n", system_get_sdk_version());
  //set sofrAP + station mode
  wifi_set_opmode(STATION_MODE);
  //ESP8266 connect to router
  user_set_station_config();

}
