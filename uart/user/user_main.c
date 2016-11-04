#include <stdio.h>
#include "osapi.h"
#include "user_interface.h"

void app_init()
{

}

void user_init(void)
{
    system_init_done_cb(app_init);
}