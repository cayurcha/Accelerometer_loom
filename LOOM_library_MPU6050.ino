// ================================================================
// ===              INCLUDE CONFIGURATION FILE                  ===
// ===    INCLUDE DECLARATIONS, STRUCTS, AND FUNCTIONS FROM     ===
// ===            OTHER FILES AS SET IN CONFIG.H                ===
// ================================================================

// Config has to be first has it hold all user specified options
#include "config.h"



// Preamble includes any relevant subroutine files based 
// on options specified in the above config
#include "loom_preamble.h"


// ================================================================ 
// ===                           SETUP                          ===
// ================================================================ 
void setup() 
{

 
	// LOOM_begin calls any relevant (based on config) LOOM device setup functions
	Loom_begin();	

	// Any custom setup code
	//pinMode(5, INPUT_PULLUP);
	//pinMode(6, INPUT_PULLUP);
	// pinMode(7, INPUT_PULLUP);
	// pinMode(8, INPUT_PULLUP);
	// pinMode(9, INPUT_PULLUP);
	// pinMode(10, INPUT_PULLUP);
}

// ================================================================ 
// ===                        MAIN LOOP                         ===
// ================================================================ 
// we can change this depending on the sensor we are using or if we even want to look at voltage 
// delay time delays the reading of values for 30 seconds at normal power and sleep time will delay readings while power is low 
#define DELAY_TIME 30000 // 30 seconds 
#define SLEEP_TIME 30 
#define POWER_LEVEL 3.1 //depends on the battery we are using and the 
void loop() 
{
	//if(read_analog(A7)>= POWER_LEVEL) //the code is looking to see if the battery is at a higher percentage than the battery voltage curve  
  //{
  //  delay(DELAY_TIME);
 // }
 // else
// {
Serial.println("About to sleep"); 
    sleep_for(SLEEP_TIME, SECONDS, SLEEPYDOG); //This can be used without the if function so that we are taking data less frequently 
Serial.println("rise and shine"); 
 // }
	OSCBundle bndl;

	// --- Basic Example ---

	// receive_bundle(&bndl, WIFI);
	// process_bundle(&bndl);

	measure_sensors();				// Read sensors, store data in sensor state struct
	package_data(&bndl);			// Copy sensor data from state to provided bundle
  log_bundle(&bndl, SDCARD, "accedata.csv");
	//append_to_bundle_key_value(&bndl, "pin5", digitalRead(5));
	//append_to_bundle_key_value(&bndl, "pin6", digitalRead(6));
	// append_to_bundle_key_value(&bndl, "pin7", digitalRead(7));
	// append_to_bundle_key_value(&bndl, "pin8", digitalRead(8));	
	// append_to_bundle_key_value(&bndl, "pin9", digitalRead(9));
	// append_to_bundle_key_value(&bndl, "pin10", digitalRead(10));

	// append_to_bundle_key_value(&bndl, "pin10", digitalRead(10));


	print_bundle(&bndl);
	

	
	// send_bundle(&bndl, WIFI);
	//
   
    delay(1000); //holding for 1000 milliseconds or 10 seconds                    

	

additional_loop_checks();		// Miscellaneous checks

	// --- End Example ---



	// // --- OLED Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);
	// log_bundle(&bndl, OLED);

	// delay(1000);

	// additional_loop_checks();	// Miscellaneous checks

	// // --- End Example ---



	// // --- LoRa Hub Example ---

	// receive_bundle(&bndl, LORA);		// Read sensors, store data in sensor state struct
	// print_bundle(&bndl);
	// log_bundle(&bndl, PUSHINGBOX);

	// additional_loop_checks();		// Miscellaneous checks
	// // --- End Example ---



	// // --- LoRa Node Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);

	// log_bundle(&bndl, SDCARD, "savefile.csv");
	// send_bundle(&bndl, LORA);

	// delay(1000);

	// additional_loop_checks();	// Miscellaneous checks
	// // --- End Example ---



	// // --- LoRa Evaporometer Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);

	// log_bundle(&bndl, SDCARD, "savefile.csv");
	// send_bundle(&bndl, LORA);

	// sleep_for(5, MINUTES, STANDBY);

	// additional_loop_checks();	// Miscellaneous checks
	// // --- End Example ---



	// // --- Common Example ---

	// receive_bundle(&bndl, WIFI);	// Receive messages
	// if (bndl.size()) {
	// 	print_bundle(&bndl);		// Print bundle if LOOM_DEBUG enabled
	// }
	// process_bundle(&bndl);			// Dispatch message to correct handling functions

	// measure_sensors();				// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle

	// // print_bundle(&bndl);			// Print bundle if LOOM_DEBUG enabled

	// send_bundle(&bndl, WIFI);		// Send bundle of packaged data
	// // log_bundle(&bndl, PUSHINGBOX);	// Send bundle to Google Sheet
	// // log_bundle(&bndl, SDCARD, "Ishield.csv");	// Send bundle to Google Sheet

	// additional_loop_checks();			// Miscellaneous checks
	// // --- End Example ---




}


// ================================================================ 
// ===                 High-Level API Functions                 === 
// ================================================================ 

// void receive_bundle(OSCBundle *bndl, CommPlatform platform);
// void process_bundle(OSCBundle *bndl);
// void measure_sensors();
// void package_data(OSCBundle *bndl);
// void send_bundle(OSCBundle *bndl, CommPlatform platform, int port);
// void send_bundle(OSCBundle *bndl, CommPlatform platform);
// void log_bundle(OSCBundle *bndl, LogPlatform platform, char* file); // filename required for SD files
// void log_bundle(OSCBundle *bndl, LogPlatform platform);
// bool bundle_empty(OSCBundle *bndl);
// void additional_loop_checks();
// void sleep_for(int amount, TimeUnits units, SleepMode mode);
// void sleep_until_time(SleepMode mode, int hour, int min, int sec);
// void append_to_bundle_key_value(OSCBundle *bndl, char* key, T elem);

// CommPlatforms: WIFI, LORA, NRF
// LogPlatforms:  PUSHINGBOX, SDCARD, OLED
// TimeUnits: MINUTES, SECONDS
// SleepMode: STANDBY, SLEEPYDOG

// Print Macro
// LOOM_DEBUG_Println
