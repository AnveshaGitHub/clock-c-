#include<iostream> //cin,cout
#include<Windows.h> //GetAsyncKeyState()
#include<mmsystem.h> //music
#include<conio.h> //getch()
#include<iomanip> //setw()

#pragma comment(lib, "winmm.lib")

using namespace std;

//globle varible for color
int textc=FOREGROUND_GREEN;


//all use function defined here!
void rem();
void stopw();
int colr();


//main function
int main(){

    int x;
    system("cls");
    cout << "Enter the Number down below:\n";
    cout << "1.Alarm\t\t\t\t";
    cout << "2.Reminder\n";
    cout << "3.Stopwatch\n";

    cout << "---------------Down-Here!---------------------\n";
    cin >> x;

switch (x){

        case 1:
            
            break;

        case 2:

            rem();

            break;

        case 3:

            stopw();

            break;

        default:

            system("cls");
            cout << "+------------------------------+\n";
            cout << "|  PLEASE ENTER CORRECT NUMBER |\n";
            cout << "+------------------------------+\n";

            break;

}


        return 0;
}

//fUnction to set input TEXT colored / print

int colr(int hh,int mm,int ss) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the original text attributes
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalAttributes = consoleInfo.wAttributes;

    // Set text color to green
    SetConsoleTextAttribute(hConsole, textc);

    // Print colored text
    
    cout << setw(25) << hh << " : " << mm << " : " << ss << endl;

    // Reset text color to default
    SetConsoleTextAttribute(hConsole, originalAttributes);

    return 0;
}

// reminder function here
void rem() {

int hour,min,sec;
int h,m,s;
    hour=0;
    min=0;
    sec=0;

    
    cout << "Enter time in Hour Min Sec \n";

    cin >> h>>m>>s;

    int tsec = (h*3600) + (m*60) + s; //time into sec
    //cout << tsec;


for(int i=0; i<=tsec;i++){

            if(sec<=tsec){
        
            //cout << sec;
            Sleep(1000);
            system("cls");


            
                if(sec == 60){
                            sec = 0;
                    min++;
                    
                    }


                cout << "\n";
                


                if(min == 60){
                            min = 0;
                    hour++;
                
                 }
           
                if(tsec==i){
                    textc = FOREGROUND_RED;               
                 }
            

            colr(hour,min,sec);
            sec++;


            }

            
            
        }

    cout << "\nTIME OVER!";
    
    
}


//function for stopWatch

void stopw(){

int hour,min,sec;
    hour=0;
    min=0;
    sec=0;

while(true){

            
            Sleep(1000);
            system("cls");


            
                if(sec == 60){
                            sec = 0;
                    min++;
                    
                    }


                cout << "\n";
                


                if(min == 60){
                            min = 0;
                    hour++;
                
                 }
    
            colr(hour,min,sec);
            sec++;


    if(GetAsyncKeyState(VK_SPACE)){
            
            break;
         
        } 
    
    }
    
}
