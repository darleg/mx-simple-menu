#include "mbed.h"
#include "simpleMenu.h"


static BufferedSerial az(TX, RX);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &az;
}

void systemMenu(); 

void Tabholeline(){
    Tab;
    halfline;
    halfline;
    printf("*");
}
void header(){
    Tabholeline();
    printf("\n\t*\t\t MXChip AZ3166 \t\t\t*\n");
    Tabholeline();
}
void helpMe(){
	systemMenu();	 
}
void getVersion() {
    systemMenu();	
}
void reBoot() {
	printf("\n Shutting down under 30 seconds... ");
	systemMenu();	
}
void systemInfo(){ 
	systemMenu();	
}
void wifiScan() {
	systemMenu();
}
void wifiSsid(){ 
	systemMenu();
}
void wifiPassword(){
	systemMenu();
}
void mqttServer(){ 
	systemMenu();
}

// Function to take user choices and perform 
// the appropriate operation 
void selectMenu() 
{ 
	int choice; 
	printf("\n Enter your choice : "); 
	scanf("%d", &choice); 

	switch (choice) { 
    case 1: 
		helpMe(); 
		break; 
	case 2: 
		getVersion(); 
		break; 
	case 3: 
		reBoot(); 
		break; 
	case 4: 
		systemInfo(); 
		break; 
	case 5: 
		wifiScan(); 
		break; 
	case 6: 
		wifiSsid(); 
		break; 
	case 7: 
        wifiPassword();
    case 8:
        mqttServer();
	default: 
		printf("\ninvalid choice Try again \n"); 
		systemMenu(); 
	} 
} 

// Function to print all the menus 
void systemMenu() 
{ 
	setfgbb;
    clrscn;

	// Create Menu 
	header();
	blankLine;
    blankLine;
    printf("\n\t*\t\t 1. Help \t\t\t*");
    printf("\n\t*\t\t 2. Version \t\t\t*");
	printf("\n\t*\t\t 3. Reboot  \t\t\t*"); 
	printf("\n\t*\t\t 4. System \t\t\t*"); 
	printf("\n\t*\t\t 5. WiFi Scan \t\t\t*"); 
	printf("\n\t*\t\t 6. WiFi SSID \t\t\t*"); 
	printf("\n\t*\t\t 7. WiFi password \t\t*"); 
	printf("\n\t*\t\t 8. Mqtt Server \t\t*"); 
	blankLine;
    blankLine;
	printf("\n");
    Tabholeline();
	printf("\n"); 

	// Function call for select options 
	selectMenu(); 
} 

// Driver Code 
int main() 
{ 
	// Function Call 
	systemMenu(); 
	return 0; 
}
