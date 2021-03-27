#include "mbed.h"
#include "console.h"
#include "Thread.h"

#define delay200ms     200ms
#define delay500ms     500ms
#define delay800ms     800ms

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
    int anyNum;
    clrscn;
    printf(
        "Mbed OS version %d.%d.%d\n",
        MBED_MAJOR_VERSION,
        MBED_MINOR_VERSION,
        MBED_PATCH_VERSION
    );
    printf("input 1 to 9 and hit enter");
    scanf("%d", &anyNum);
    systemMenu();	
}
void reBoot() {
	int anyN ;
	printf("\n input 1 to 9 and enter to reboot");
    scanf("%d", &anyN);
    NVIC_SystemReset();
    // Or
    //system_reset();
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
