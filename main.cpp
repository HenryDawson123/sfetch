/* A Minimalist Fetch Program for the *nix terminal
Configuration can be done by editing this source code
Comment/Uncomment the lines in int main() to display or hide specifications,
currently the Arcitechture and Visual outputs are commented out.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <chrono>
using namespace std;

/* The majority of these classes and objects are pretty self explanatory so the notation/comments will probably be breif if at all present*/

class systemInfo {
public:
	string getOS() {
		/*This method could be seen as bad form will likely update and change this using popen() instead of system()*/
		system("lsb_release -sd >/tmp/distro.out");
		ifstream infile;
		filename = "/tmp/distro.out";
		infile.open(filename);
		if(infile.good()){
			getline(infile, distroLine);
		}
		infile.close();
		distroLine.erase(
		remove( distroLine.begin(), distroLine.end(), '\"' ),
		distroLine.end()
		);
		return distroLine;
	}
	string getHostname() {
		struct utsname sysinfo;
		uname(&sysinfo);
		hostname = sysinfo.nodename;
		return hostname;
	}
	string getUsername() {
		username = getenv("USER");
		return username;
	}
	int getUserHostLength() {
		hostnameLength = getHostname().length();
		usernameLength = getUsername().length();
		UserHostLength = usernameLength + hostnameLength;
		return UserHostLength;
	}
	string getDevice() {
		/* Depending on your device this may not work, but with my tests on my devices it works*/
		ifstream device;
		filename = "/sys/devices/virtual/dmi/id/product_family";
		device.open(filename);
		if(device.good()){
			getline(device, deviceName);
		}
		device.close();
		return deviceName;
	}
	string getUptime() {
		struct sysinfo info;
		sysinfo(&info);
		uptime = info.uptime;
		/* if its greater than 60 minutes we'll put it in hours*/
		if(uptime/60 >= 60) {
			uptimeHour = (uptime/60)/60;
			uptimeHourWhole = uptimeHour;
			uptimeMinutes = uptimeHour - uptimeHourWhole;
			uptimeMinutesWhole = uptimeMinutes * 60;
			/* if its greater than 24 hours we'll put it in days */
			if(uptimeHour >= 24) {
				uptimeDay = uptimeHour/24;
				uptimeDayWhole = uptimeDay;
				uptimeHour = uptimeDay - uptimeDayWhole;
				uptimeHour = uptimeHour * 24;
				uptimeStream << uptimeDayWhole << "d " << uptimeHourWhole << "h " << uptimeMinutesWhole << "m";
			}
			else {
				uptimeStream << uptimeHourWhole << "h " << uptimeMinutesWhole << "m";
			}
		}
		else {
			uptimeMinutes = uptime/60;
			uptimeMinutesWhole = uptimeMinutes;
			uptimeStream << uptimeMinutesWhole << "m";
		}
		uptimeString = uptimeStream.str();
		return uptimeString;
	}
	string getShell() {
		shell = getenv("SHELL");
		shell.erase(0,5); /* This line gets rid of the /bin/ part of the SHELL variable. I have noticed that in my debian VM with FISH the shell is in /usr/bin/ and in that case it removes the /usr/ */
		return shell;
	}
	string getTerm() {
		terminal = getenv("TERM");
		return terminal;
	}
	string getKernel() {
		struct utsname sysinfo;
		uname(&sysinfo);
		kernelVersion = sysinfo.release;
		return kernelVersion;
	}
	string getArch() {
		struct utsname sysinfo;
		uname(&sysinfo);
		architecture = sysinfo.machine;
		return architecture;
	}
	string getEditor() {
		editor = getenv("EDITOR");
		return editor;
	}
	string getVisual() {
		visual = getenv("VISUAL");
		return visual;
	}
private:
	string distroLine, filename, hostname, username, deviceName, uptimeString, shell, terminal, kernelVersion, architecture, editor, visual, lineOne;
	double uptime, uptimeMinutes, uptimeHour, uptimeDay;
	int initialUptime, uptimeMinutesWhole, uptimeHourWhole, uptimeDayWhole, usernameLength, hostnameLength, UserHostLength;
	stringstream uptimeStream;
};
class Colours {
public:
	string getColourBar() {
		ColourBar =colourZero + colourOne + colourTwo + colourThree + colourFour + colourFive + colourSix + colourSeven;
		return ColourBar;
	}
	string getFullColourBar() {
		FullColourBar = getColourBar() + "\n" + colourEight + colourNine + colourTen + colourEleven + colourTwelve + colourThirteen + colourFourteen + colourFifteen;
		return FullColourBar;
	}
	string getTextColourNeutral() {
		NeutralText = "\033[0;37m";
		return NeutralText;
	}
	string getTextColourRed() {
		RedText = "\033[0;31m";
		return RedText;
	}
	string getTextColourGreen() {
		GreenText = "\033[0;32m";
		return GreenText;
	}
	string getTextColourYellow() {
		YellowText = "\033[0;33m";
		return YellowText;
	}
	string getTextColourBlue() {
		BlueText = "\033[0;34m";
		return BlueText;
	}
	string getTextColourMagenta() {
		MagentaText = "\033[0;35m";
		return MagentaText;
	}
	string getTextColourCyan() {
		CyanText = "\033[0;36m";
		return CyanText;
	}
private:
	string colourZero = "\033[7;30m  ", colourOne = "\033[7;31m  ", colourTwo = "\033[7;32m  ", colourThree = "\033[7;33m  ",
	       colourFour = "\033[7;34m  ", colourFive = "\033[7;35m  ", colourSix = "\033[7;36m  ", colourSeven = "\033[7;37m  ",
	       colourEight = "\033[7;90m  ", colourNine = "\033[7;91m  ", colourTen = "\033[7;92m  ", colourEleven = "\033[7;93m  ",
	       colourTwelve = "\033[7;94m  ", colourThirteen = "\033[7;95m  ", colourFourteen = "\033[7;96m  ", colourFifteen = "\033[7;97m  ",
	       ColourBar, FullColourBar, NeutralText, RedText, GreenText, YellowText, BlueText, MagentaText, CyanText;
};
int main() {
	systemInfo systemInfo;
	Colours Colours;
	/*This is the string that underlines your hostname and username, if you have any other characters between them make sure to adjust the +1*/
	string underline((systemInfo.getUserHostLength()+1),'~');
	/* These are the lines referenced in the configuration instructions in the README.md comment or uncomment them to hide/show information */
	cout << Colours.getTextColourBlue() << systemInfo.getUsername() << Colours.getTextColourNeutral() <<"@" << Colours.getTextColourGreen() << systemInfo.getHostname() << endl;
	cout << Colours.getTextColourBlue() << underline << endl;
	cout << Colours.getTextColourGreen() << "OS:       " << Colours.getTextColourNeutral() << systemInfo.getOS() << endl;
	cout << Colours.getTextColourGreen() << "Host:     " << Colours.getTextColourNeutral() << systemInfo.getDevice() << endl;
	cout << Colours.getTextColourGreen() << "Kernel:   " << Colours.getTextColourNeutral() << systemInfo.getKernel() << endl;
//	cout << Colours.getTextColourGreen() << "Arch:     " << Colours.getTextColourNeutral() << systemInfo.getArch() << endl;
	cout << Colours.getTextColourGreen() << "Uptime:   " << Colours.getTextColourNeutral() << systemInfo.getUptime() << endl;
	cout << Colours.getTextColourGreen() << "Terminal: " << Colours.getTextColourNeutral() << systemInfo.getTerm() << endl;
	cout << Colours.getTextColourGreen() << "Shell:    " << Colours.getTextColourNeutral() << systemInfo.getShell() << endl;
	cout << Colours.getTextColourGreen() << "Editor:   " << Colours.getTextColourNeutral() << systemInfo.getEditor() << endl;
//	cout << Colours.getTextColourGreen() << "Visual:   " << Colours.getTextColourNeutral() << systemInfo.getVisual() << endl;
	cout << Colours.getColourBar() << endl;
//	cout << Colours.getFullColourBar() << endl;
}
