#include<iostream>
#include<string.h>
using namespace std;

int payment;

int lpayment(char origin[30], char destination[30]){
	
if((strcmp(origin,"TUNIS")==0)||(strcmp(origin,"SOUSSE")==0)&&(strcmp(destination,"TUNIS")==0)||(strcmp(destination,"SOUSSE")==0))
	return payment=200;
else if((strcmp(origin,"TUNIS")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"TUNIS")==0)||(strcmp(destination,"SFAX")==0))
	return payment=237;
else if((strcmp(origin,"TUNIS")==0)||(strcmp(origin,"DJERBA")==0)&&(strcmp(destination,"TUNIS")==0)||(strcmp(destination,"DJERBA")==0))
	return payment=101;
else if((strcmp(origin,"TUNIS")==0)||(strcmp(origin,"TOUZER")==0)&&(strcmp(destination,"TUNIS")==0)||(strcmp(destination,"TOUZER")==0))
	return payment=101;
else if((strcmp(origin,"SOUSSE")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"SOUSSE")==0)||(strcmp(destination,"SFAX")==0))
	payment=30;
else if((strcmp(origin,"SOUSSE")==0)||(strcmp(origin,"DJERBA")==0)&&(strcmp(destination,"SOUSSE")==0)||(strcmp(destination,"DJERBA")==0))
	return payment=600;
else if((strcmp(origin,"SOUSSE")==0)||(strcmp(origin,"TOUZER")==0)&&(strcmp(destination,"SOUSSE")==0)||(strcmp(destination,"TOUZER")==0))
	return payment=98;
else if((strcmp(origin,"SFAX")==0)||(strcmp(origin,"DJERBA")==0)&&(strcmp(destination,"SFAX")==0)||(strcmp(destination,"DJERBA")==0))
	return payment=72;
else if((strcmp(origin,"SFAX")==0)||(strcmp(origin,"TOUZER")==0)&&(strcmp(destination,"SFAX")==0)||(strcmp(destination,"TOUZER")==0))
	return payment=22;
}

int ipayment(char origin[30], char destination[30]){
	
if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"BERLIN")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"BERLIN")==0))
	        return payment=1709;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"DUBAI")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"DUBAI")==0))
	        return payment=2412;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"RIYADH")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"RIYADH")==0))
	        return payment=4835;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"MARSEILLE")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"MARSEILLE")==0))
	        return payment=1058;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"PARIS")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"PARIS")==0))
	        return payment=1145;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1001;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=4781;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=3971;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"LYON")==0))
	        return payment=1762;
else if((strcmp(origin,"LONDON")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"LONDON")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1900;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"DUBAI")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"DUBAI")==0))
	        return payment=3567;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"RIYADH")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"RIYADH")==0))
	        return payment=6964;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"MARSEILLE")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"MARSEILLE")==0))
	        return payment=6227;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"PARIS")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"PARIS")==0))
	        return payment=1446;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1502;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=6670;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=2334;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"LYON")==0))
	        return payment=1607;
else if((strcmp(origin,"BERLIN")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"BERLIN")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1296;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"RIYADH")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"RIYADH")==0))
	        return payment=1354;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"MARSEILLE")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"MARSEILLE")==0))
	        return payment=1225;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"PARIS")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"PARIS")==0))
	        return payment=6104;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1859;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=6742;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=2049;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"LYON")==0))
	        return payment=1527;
else if((strcmp(origin,"DUBAI")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"DUBAI")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1439;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"MARSEILLE")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"MARSEILLE")==0))
	        return payment=3261;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"PARIS")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"PARIS")==0))
	        return payment=5182;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1525;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=8179;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=8616;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"LYON")==0))
	        return payment=3723;
else if((strcmp(origin,"RIYADH")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"RIYADH")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=4012;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"PARIS")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"PARIS")==0))
	        return payment=348;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1516;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=3342;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=8227;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"LYON")==0))
	        return payment=487;
else if((strcmp(origin,"MARSEILLE")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"MARSEILLE")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1810;
else if((strcmp(origin,"PARIS")==0)||(strcmp(origin,"CASABLANCA")==0)&&(strcmp(destination,"PARIS")==0)||(strcmp(destination,"CASABLANCA")==0))
	        return payment=1574;
else if((strcmp(origin,"PARIS")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"PARIS")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=3990;
else if((strcmp(origin,"PARIS")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"PARIS")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=5312;
else if((strcmp(origin,"PARIS")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"PARIS")==0)||(strcmp(destination,"LYON")==0))
	        return payment=3542;
else if((strcmp(origin,"PARIS")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"PARIS")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1464;
else if((strcmp(origin,"CASABLANCA")==0)||(strcmp(origin,"TOKYO")==0)&&(strcmp(destination,"CASABLANCA")==0)||(strcmp(destination,"TOKYO")==0))
	        return payment=7114;
else if((strcmp(origin,"CASABLANCA")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"CASABLANCA")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=1865;
else if((strcmp(origin,"CASABLANCA")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"CASABLANCA")==0)||(strcmp(destination,"LYON")==0))
	        return payment=1777;
else if((strcmp(origin,"CASABLANCA")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"CASABLANCA")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1229;
else if((strcmp(origin,"TOKYO")==0)||(strcmp(origin,"WASHINGTON")==0)&&(strcmp(destination,"TOKYO")==0)||(strcmp(destination,"WASHINGTON")==0))
	        return payment=7434;
else if((strcmp(origin,"TOKYO")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"TOKYO")==0)||(strcmp(destination,"LYON")==0))
	        return payment=3099;
else if((strcmp(origin,"TOKYO")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"TOKYO")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=1022;
else if((strcmp(origin,"WASHINGTON")==0)||(strcmp(origin,"LYON")==0)&&(strcmp(destination,"WASHINGTON")==0)||(strcmp(destination,"LYON")==0))
	        return payment=6361;
else if((strcmp(origin,"WASHINGTON")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"WASHINGTON")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=4989;
else if((strcmp(origin,"LYON")==0)||(strcmp(origin,"SFAX")==0)&&(strcmp(destination,"LYON")==0)||(strcmp(destination,"SFAX")==0))
	        return payment=796;
}
