/*
 * Copyright (c) 2002-3 Patrick Mochel
 * Copyright (c) 2002-3 Open Source Development Labs
 *
 * This file is released under the GPLv2
 */

#include <linux/device.h>
#include <linux/init.h>
#include <linux/memory.h>

#include "base.h"

/**
 * driver_init - initialize driver model.
 *
 * Call the driver model init functions to initialize their
 * subsystems. Called early from init/main.c.
 */
void __init driver_init(void)
{
        /* These are the core pieces */
        devtmpfs_init();
        devices_init();//创建内核全局变量devices_kset(即/sys/devices目录);创建内核全局变量dev_kobj,sysfs_dev_block_kobj,
//sysfs_dev_char_kobj(即/sys/dev目录及其目录中的/block和/char目录)
        
        buses_init();//创建内核全局变量bus_kset和system_kset（即/sys/bus目录和/sys/devices/system目录）
        classes_init();//创建内核全局变量class_kset(即/sys/class目录).
        firmware_init();
        hypervisor_init();

        /* These are also core pieces, but must come after the
         * core core pieces.
         */
        platform_bus_init();//初始化platform总线:实例化创建一名称为platform的总线(i2c等其他总线在其他地方初始化)
	cpu_dev_init();
	memory_dev_init();
}
