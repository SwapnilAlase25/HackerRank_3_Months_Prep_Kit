#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
bool isPM;  // true if PM
string TimeIn24Hrs, temp=s;

if (s.find("PM") != std::string::npos) {  // Found out if the time is in PM or AM
    isPM = true;
}else{
    isPM = false;
}

size_t pos = 0;  
string hrs,delim=":";
   
while (( pos = temp.find (delim)) != std::string::npos) // As only the HH will be changed from HH:MM:SS, so extracted it 
{  
hrs = temp.substr(0, pos); // store the substring   
//cout << hrs << endl; 
break;  
}  
int hrsInt = stoi(hrs);   // converted the string HH to Int HH ( But the 02 will be converted to 2, need to take care later)
if(isPM){
    if(hrsInt < 12){  // if the time is less than 12 but its in PM then add 12 hours 
        hrsInt = hrsInt + 12;
    }
}else {
    if(hrsInt == 12){  // if its 12:00:00AM then, make it 00:00:00
        hrsInt = 00;
    }
}
// cout << "Hours in : " <<hrsInt<<endl;
string stringHrs = to_string(hrsInt); // Converting back the int to string
if(stringHrs.length()==1){      // handled the prefix 0 over here
    stringHrs = "0"+stringHrs;
}

TimeIn24Hrs = stringHrs +s[2]+s[3]+s[4]+s[5]+s[6]+s[7]; // attaching 24Hrs HH and remaining time from the original time
//cout << "TimeIn24Hrs  : " <<TimeIn24Hrs<<endl;

return TimeIn24Hrs;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
