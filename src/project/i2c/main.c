/*
 * Copyright (c) 2024 Open Pixel Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */

 
 #include <zephyr/kernel.h>
 #include <zephyr/sys/printk.h>
 #include <zephyr/drivers/i2c.h>
 #include <zephyr/drivers/i2c/target/eeprom.h>
 
 static const struct device *eeprom = DEVICE_DT_GET(DT_NODELABEL(i2c21));
 #define EEPROM_TEST_ADDRESS 0x0000  // Test address (16bit)
 
 int main(void)
 {
	 printk("i2c target sample\n");
 
	 if (!device_is_ready(eeprom)) {
		 printk("eeprom device not ready\n");
		 return 0;
	 }
 
	 if (i2c_target_driver_register(eeprom) < 0) {
		 printk("Failed to register i2c target driver\n");
		 return 0;
	 }
 
	 printk("i2c target driver registered\n");
 
	 // ---------------------- EEPROM Write/Read Test ----------------------
	 printk("Starting EEPROM Write/Read test...\n");
	 uint8_t write_data = 0b10101010; // Arbitrary 1-byte data
	 uint8_t read_data = 0;
	 int ret;
 
	 // Write data to EEPROM via I2C
	 struct i2c_msg msgs[1];
	 uint8_t write_buffer[3]; // Address (2bytes) + Data (1byte)
	 write_buffer[0] = (EEPROM_TEST_ADDRESS >> 8) & 0xFF; // Address upper 8bits
	 write_buffer[1] = EEPROM_TEST_ADDRESS & 0xFF;        // Address lower 8bits
	 write_buffer[2] = write_data;                        // Data to write
 
	 msgs[0].buf = write_buffer;
	 msgs[0].len = sizeof(write_buffer);
	 msgs[0].flags = I2C_MSG_WRITE;
 
	 ret = i2c_transfer(eeprom, &msgs[0], 1, 0x50); //eeprom->config->i2c_slv_addr
	 if (ret < 0) {
		 printk("Error writing to EEPROM: %d\n", ret);
	 } else {
		 printk("Wrote 0x%02X to EEPROM address 0x%04X\n", write_data, EEPROM_TEST_ADDRESS);
	 }
 
	 k_msleep(10); // Wait a short time for the write to complete
 
	 // Read data from EEPROM via I2C
	 struct i2c_msg msgs_read[2];
	 uint8_t read_address[2]; // Address (2bytes)
	 read_address[0] = (EEPROM_TEST_ADDRESS >> 8) & 0xFF; // Address upper 8bits
	 read_address[1] = EEPROM_TEST_ADDRESS & 0xFF;        // Address lower 8bits
 
	 // Message to write the address
	 msgs_read[0].buf = read_address;
	 msgs_read[0].len = sizeof(read_address);
	 msgs_read[0].flags = I2C_MSG_WRITE | I2C_MSG_STOP; // STOP condition required
 
	 // Message to read the data
	 uint8_t read_buf[1] = {0}; // Read buffer
	 msgs_read[1].buf = read_buf;
	 msgs_read[1].len = sizeof(read_buf);
	 msgs_read[1].flags = I2C_MSG_READ | I2C_MSG_STOP; // STOP condition required
 
	 ret = i2c_transfer(eeprom, msgs_read, 2, 0x50);
 
	 if (ret < 0) {
		 printk("Error reading from EEPROM: %d\n", ret);
	 } else {
		 read_data = read_buf[0];
		 printk("Read 0x%02X from EEPROM address 0x%04X\n", read_data, EEPROM_TEST_ADDRESS);
 
		 // Check if the read data matches the written data
		 if (read_data == write_data) {
			 printk("EEPROM Write/Read test PASSED!\n");
		 } else {
			 printk("EEPROM Write/Read test FAILED! (Expected 0x%02X, got 0x%02X)\n", write_data, read_data);
		 }
	 }
	 printk("EEPROM Write/Read test finished.\n");
	 // ---------------------- EEPROM Write/Read Test End ------------------
 
	 k_msleep(1000);
 
	 if (i2c_target_driver_unregister(eeprom) < 0) {
		 printk("Failed to unregister i2c target driver\n");
		 return 0;
	 }
 
	 printk("i2c target driver unregistered\n");
 
	 return 0;
 }