#include<iostream>
#include<windows.h>
using namespace std;

int main(){


    int h,m,s;
    int hour,min,sec;
    hour=0;
    min=0;
    sec=0;

    cout << "Enter time in Hour Min Sec \n";

    cin >> h>>m>>s;

    int tsec = (h*3600) + (m*60) + s;
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
           
            cout << hour <<  " : " ;
            cout << min << " : " ;
            cout << sec;
            sec++;
            }

            
            
        }

return 0;
}
