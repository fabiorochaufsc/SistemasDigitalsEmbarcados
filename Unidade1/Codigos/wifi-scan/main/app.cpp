#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"


void scanCB(void *arg, STATUS status) {
struct bss_info *bssInfo;
bssInfo = (struct bss_info *)arg;
// skip the first in the chain … it is invalid
bssInfo = STAILQ_NEXT(bssInfo, next);
while(bssInfo != NULL) {
os_printf("ssid: %s\n", bssInfo->ssid);
bssInfo = STAILQ_NEXT(bssInfo, next);
}
}

void app_main(void)
{
// Ensure we are in station mode
wifi_set_opmode_current(STATION_MODE);

// Request a scan of the network calling "scanCB" on completion
wifi_station_scan(NULL, scanCB);
}
