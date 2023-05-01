#include<conio.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<unistd.h>
#include<time.h>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include"payment.h"
#include<stdio.h>
using namespace std;

bool datecheck(int, int, int, int);
const char l_destination[5][20]={"TUNIS","SOUSSE","SFAX","DJERBA","TOUZER"};	//Destination local
const char i_destination[11][20]={"LONDON","BERLIN","DUBAI","RIYADH","CASABLANCA","PARIS","MARSEILLE","TOKYO","WASHINGTON","LYON","TUNIS" }; //Destination internationale

class client{
	private:
		const int bclasse;
		const int eclasse;
	protected:
		string nom,prenom, phone, mealtype, passport, Address;
		int bus, eco, datedep, payment;
		char origin[30];
		char destination[30];
	public:
		client(string f_name, string l_name, string phone_no, string add="N/A", string pass_no="N/A", int dd=000000): bclasse(50), eclasse(250)
		{
			datedep=dd;
			nom=f_name;
			prenom=l_name;
			Address=add;
			phone=phone_no;
			passport=pass_no;
			bus = bclasse;
			eco = eclasse;
		}

		virtual bool ldest()=0;
		virtual bool idest(string pass)=0;
		virtual void classe()=0;
		virtual void repas()=0;
		virtual void Registration()=0;
		virtual bool afficher()=0;
		virtual void conduire()=0;

};

class reservation:public client
{
	protected:
		int i,j,n,m,k,NoOfclasse,choice;
	public:

		reservation(string f,string l,string num,string add,string pass,int dd):client(f,l,add,num,pass,dd)
		{
			n=0;
			m=0;
		}

	bool ldest()
	{

		cout<<endl<<"Voici les destinations locales: \n";
		for(i=0;i<5;i++)
		{
			for(j=0;j<20;j++)
			{
				cout<<l_destination[i][j];
			}
			cout<<"\n";
		}

		again:
		cout<<endl<<"Entrez votre origine (en lettres majuscules) :";
		cin>>origin;
		cout<<endl<<"Entrez votre destination (en lettres majuscules) :";
		cin>>destination;
		if(strcmp(origin,destination)==0)
		{
			cout<<"Saisissez a nouveau l'origine et la destination non valides\n";
			goto again;
		}
		else
		{
			for(i=0;i<5;i++)
			{
				if(strcmp(l_destination[i],origin)==0)
					n++;
			}
			for(j=0;j<5;j++)
			{
				if(strcmp(l_destination[j],destination)==0)
					m++;
			}
			if(m==1&&n==1)
			{
				payment = lpayment(origin, destination);
				cout<<endl<<"prix: "<<payment<<" dt/classe"<<endl;
				return true;
			}
			else
				return false;

		}
	}

		bool idest(string pass)
	{
		passport = pass;
		cout<<endl<<"Voici les destinations internationales: \n";
		for(i=0;i<11;i++)
		{
			for(j=0;j<20;j++)
			{
				cout<<i_destination[i][j];
			}
			cout<<"\n";
		}
		again:
		cout<<endl<<"Entrez votre origine (en lettres majuscules) :";
		cin>>origin;
		cout<<endl<<"Enterz votre destination(en lettres majuscules): ";
		cin>>destination;
		if(strcmp(origin,destination)==0)
		{
			cout<<"Saisissez a nouveau l'origine, la destination non valides\n";
			goto again;
		}
		else
		{
			for(i=0;i<11;i++)
			{
				if(strcmp(i_destination[i],origin)==0)
					n++;
			}
			for(j=0;j<11;j++)
			{
				if(strcmp(i_destination[j],destination)==0)
					m++;
			}
			if(m==1&&n==1)
			{
				payment = ipayment(origin, destination);
				cout<<endl<<"prix: "<<payment<<" dt/classe"<<endl;
				return true;
			}
			else
				return false;
		}
	}


		void classe()
		{
			bus_eco:
				if(bus>0&&eco>0)
				{
					cout<<endl<<"1.Business Class\n2.Economy Class\n";
					k = getch();
					switch(k)
					{
						case 49:
						{
							cout<<endl<<"Classe affaire";
							cout<<endl<<"Entrer le nombre de classes: ";
							cin>>NoOfclasse;
							payment=(payment*NoOfclasse)+500;
							if(NoOfclasse<=bus)
							{
								cout<<endl<<"classe est valable.\n\n";
								bus=bus-NoOfclasse;
							}
							else
							{
								cout<<endl<<"classe est non valable.\n\n";
								cout<<"nous n'avons que "<<bus<<" classe disponible.\n"<<endl;
								cout<<"Souhaitez-vous reserver la classe restante\nAppuyez sur 1 pour OUI\nAppuyez sur 2 pour NON\n";
								k = getch();
								if(k==49)
								{
									NoOfclasse = bus;
									payment=(payment*NoOfclasse)+500;
								 	cout<<"la classe est reservee\n\n";
								 	bus=0;
								}
								else
								{
									cout<<endl<<"A la prochaine.\n";
									exit(0);
								}
							}
							break;
						}

					case 50:
						{
							cout<<endl<<"Classe economique";
							cout<<endl<<"Entre le nombre de classe: ";
							cin>>NoOfclasse;
							payment=(payment*NoOfclasse);
							if(NoOfclasse<=eco)
							{
								cout<<endl<<"classe est valable.\n\n";
								eco=eco-NoOfclasse;
							}
							else
							{
								cout<<endl<<"classe n'est pas valable.\n\n";
								cout<<"nous n'avons que"<<eco<<"classe disponible.\n"<<endl;
								cout<<"Souhaitez-vous reserver la classe restante\nAppuyez sur 1 pour OUI\nAppuyez sur 2 pour NON\n";
								k = getch();
								if(k==49)
								{
									NoOfclasse = eco;
									payment=(payment*NoOfclasse);
									cout<<endl<<"classe est reservee\n\n";
									eco=0;
								}
								else
								{
									cout<<endl<<"A la prochaine.\n";
									exit(0);
								}
							}
							break;
						}

					default:
						{
							cout<<"Errure!\n";
							goto bus_eco;
						}
				}
			}
			else
			{
				cout<<endl<<"Desole pas de classe disponible\nBonne journee !";
				exit(0);
			}
		}


		void repas()
		{
			meal:
			int n;
			cout<<endl<<"Types de repas disponibles :\n1.Vegetarien\n2.Non vegetarien\n";
			n = getch();
			if(n==49)
				mealtype="Vegetarien";
			else if(n==50)
				mealtype="Non Vegetarien";
			else
			{
				cout<<"ERRURE!!!"<<endl;
				goto meal;
			}
		}

		void Registration()
		{
			int tkt;
			srand (time(NULL));
			tkt = rand()%1000;
			if(k==49)
			{
				ofstream outfile;
				outfile.open("voyage .txt");
				outfile<<"| INFORMATIONS SUR LES BILLETS :"<<endl<<endl
				<<"Nom: "<<nom<<" "<<prenom<<endl
				<<"Adresse: "<<Address<<endl
				<<"Telephone: "<<phone<<endl
				<<"numero du Passport: "<<passport<<endl
				<<"Origine: "<<origin
				<<endl<<"Destination: "<<destination
				<<endl<<"Repas: "<<mealtype
				<<endl<<"Nombre de classe : "<<NoOfclasse
				<<endl<<"Classe : Affaires"
				<<endl<<"Date de depart: "<<datedep
				<<endl<<"Temps: 4.00 PM"
				<<endl<<"Ticket: HF"<<tkt
				<<endl<<"Facture(en dinars Tunisienne): "<<payment<<"/-"<<endl;
				outfile.close();
			}
			else if(k==50)
			{
				ofstream outfile;
				outfile.open("voyage .txt");
				outfile<<"| INFORMATIONS SUR LES BILLETS :"<<endl<<endl
				<<"Nom: "<<nom<<" "<<prenom<<endl
				<<"Adresse: "<<Address<<endl
				<<"Telephone: "<<phone<<endl
				<<"Nombre du Passport: "<<passport<<endl
				<<"Origine: "<<origin
				<<endl<<"Destination: "<<destination
				<<endl<<"Repas: "<<mealtype
				<<endl<<"Nombre de classe: "<<NoOfclasse
				<<endl<<"Class: Economie"
				<<endl<<"Date de depart: "<<datedep
				<<endl<<"Temps: 4.00 PM"
				<<endl<<"Ticket: HF"<<tkt
				<<endl<<"Facture(en dinars tunisienne): "<<payment<<"/-"<<endl;
				outfile.close();
			}
		}

		bool afficher()
		{
			bool ans;
			system("cls");
			string temp;
			ifstream infile;
			infile.open("voyage .txt");
			while(!infile.eof())
			{
				getline(infile,temp);
				cout<<temp<<endl;
			}
			ans = confirmer();
			return ans;
		}

		bool confirmer()
		{
			char ch;
			confirmer:
			cout<<endl<<endl<<"Souhaitez-vous confirmer votre billet ? (o/n) : ";
			ch=getch();
			if(ch=='O'||ch=='o')
			{
				cout<<endl<<endl<<"|STATUT confirme";
				ofstream outfile;
				outfile.open("voyage .txt",ios::app);
				outfile<<endl<<"|STATUT confirme";
				outfile.close();
				return true;
			}
			else if(ch=='N'||ch=='n')
			{
				ofstream outfile;
				outfile.open("voyage .txt",ios::app);
				outfile<<endl<<"|reservation ANNULÉE";
				cout<<endl<<endl<<"|reservation ANNULÉE"
				<<endl<<"Retour a la page principale";
				sleep(3);
				outfile.close();
				return false;
			}
			else
			{
				cout<<endl<<"ERRURE!!!";
				goto confirmer;
			}
		}

		inline void conduire()
		{
			string pick;
			cout<<endl<<"Veuillez entrer votre point de retrait :";
			cin.ignore();
			getline(cin,pick);
			cout<<endl<<endl<<"Retour a la page principale"<<pick;
			cout<<endl<<"Deposer: "<<origin<<" Aeroport"
			<<endl<<"Tarif: 300/-";
			cout<<endl<<endl<<"Vous serez bientot contacte par notre conducteur\nBonne journee !";
			fstream ofile;
			ofile.open("voyage .txt",ios::app);
			ofile<<endl<<endl<<"Pick'n Drop : OUI"<<endl<<endl
			<<"Lieu de ramassage:"<<pick
			<<endl<<"Deposer: "<<origin<<" Aeroport"
			<<endl<<"Tarif: 300/-";
			ofile.close();
		}
};

class modification
{
	private:
		string temp,y,c2;
		int option;
	public:
		int change()
		{
			int i=0;

			ifstream file("voyage .txt");
			if(file.is_open())
			{
			cout<<endl<<"Entrez votre numero de billet ou appuyez sur 0 pour quitter\nNumero de billet : ";
			cin>>temp;
			if(temp=="0")
				return 1;
			string v("Ticket: "+temp);

			while(!file.eof())
			{
				getline(file,y);
				if(y==v)
				{
					file.seekg(0,ios::beg);
					while(!file.eof())
					{
						getline(file,temp);
						cout<<temp<<endl;
					}
					cout<<endl<<endl<<"1.Modifier la date\n2.Annuler le voyage \n3.Retourner\n";
					option = getch();
					switch(option)
					{
						case 49:
						{
							file.seekg(0,ios::beg);
							ofstream ofile("temp.txt");
							cout<<endl<<"Saisissez la nouvelle date de depart (JJMMAAAA) :";
							cin>>c2;
							string c1("date de depart: "+c2);
							while(!file.eof())
							{
								getline(file,y);
								if(i==11)
								{
									i++;
									ofile<<c1<<endl;
								}
								else
								{
									i++;
									ofile<<y<<endl;
								}
							}
							file.close();
							ofile.close();
							ofstream outfile;
							outfile.open("voyage .txt");
							ifstream readfile("temp.txt");
							while(!readfile.eof())
							{
								getline(readfile,y);
								outfile<<y<<endl;
							}
							outfile.close();
							readfile.close();
							remove("temp.txt");
							cout<<endl<<"Date changee!";
							return 1;
							break;
						}

						case 50:
						{
							file.close();
							ofstream ofli;
							ofli.open("voyage .txt",ios::trunc);
							ofli.close();
							remove("voyage .txt");
							system("cls");
							cout<<endl<<"reservation annulee !\n\n";
							return 1;
							break;
						}
						case 51:
							system("cls");
							return 1;
					}
				}
			}
		}
		else if(!file.is_open())
		{
			cout<<endl<<endl<<"impossible de trouver un enregistrement"<<endl;
			cout<<endl<<"retour a la page principale\n\n";
			file.close();
			return 1;
		}
	}
};


class apropos
{
	public:
		void aproposnous()
		{
			cout<<"La hauteur des cieux a ete touchee pour la premiere fois par notre compagnie aerienne en 1969. Depuis lors,\nHigh Fly est la première compagnie aerienne au monde avec 4 plus gros avions.\nNous sommes au service des clients en matiere de cuisine, de confort et de soins.\nAlors faites un plan et voler haut avec High Fly."<<endl<<endl;
			cout<<"Appuyez sur n'importe quelle touche pour continuer...";
		}

};

class reclamation
{
	private:
		string f_name, l_name, p_num;
		int choice;
		string sentence;
		string types;
		char ch;
	public:
		reclamation(string f,string l,string num)
		{
			f_name = f;
			l_name = l;
			p_num = num;
		}

	void type()
	{
		back:
		cout<<endl<<endl<<"Saisissez le type de reclamation que vous souhaitez enregistrer :\n1.Gestion a l'aeroport\n2.Livraison des bagages\n3.Reservation et billetterie\n4.Autre\n";
		choice = getch();
		cin.ignore();
		cout<<"Saisissez votre reclamation :\n";
		if(choice==49)
		{
			cout<<"Gestion de l'aeroport :";
			types = "Gestion de l'aeroport : ";
		}
		else if(choice==50)
		{
			cout<<"Livraison des bagages:";
			types = "Livraison des bagages:";
		}
		else if(choice==51)
		{
			cout<<"reservation et billetterie :";
			types = "reservation et billetterie :";
		}
		else if(choice==52)
		{
			cout<<"Autre: ";
			types = "Autre: ";
		}
		getline(cin,sentence);
		cout<<endl<<"Voulez-vous modifier votre reclamation (o/n) : ";
		ch=getch();
		if(ch=='O'||ch=='O')
			goto back;
		else
		{
			cout<<endl<<"Reclamation notee !\n";
			ofstream outfile;
			outfile.open("reclamation.txt");
			outfile<<"Name: "<<f_name<<" "<<l_name<<endl
			<<"Telephone: "<<p_num<<endl
			<<"Reclamation:\n"<<types<<sentence;
			outfile.close();
			sleep(3);
		}
	}
};



class routes{
	public:
		bool print()
		{
			int i,j;
			char ch;
			cout<<"\n\n\n\n\tVoici les voyages internationaux disponibles "<<endl;
			for(i=0;i<11;i++)
			{
				cout<<endl;
				for(j=0;j<11;j++)
				{
					if(i==j)
					{
						continue;
					}
					else
					{
						cout<<"depart de "<<i_destination[i]<<" a "<<i_destination[j]<<endl;
					}

				}
			}
			cout<<"\n\n\n\n\tVoici les voyages internationaux disponibles "<<endl;
			for(i=0;i<5;i++)
			{
				cout<<endl;
				for(j=0;j<5;j++)
				{
						if(i==j)
					{
						continue;
					}
					else
					{
						cout<<"depart de "<<l_destination[i]<<" a "<<l_destination[j]<<endl;
					}
				}
			}
			cout<<endl<<"Voulez-vous reserver un voyage (o/n)";
			ch=getch();
			if(ch=='O'||ch=='o')
			{
				cout<<endl<<endl;
				return true;
			}
			else
				return false;
		}

};


int main()
{


	system("COLOR 0f");
	cout<<"\n\t\t\t\tPROJET CPP\n\t\t SYSTEME DE GESTION DE VOLS";
	cout<<"\nAppuyez sur Entrer pour continuer :";
	getch();

	cout<<endl<<"\n\n\n\tBienvenue a la compagnie aerienne HIGH FLY"<<endl;
	string f_name, l_name, add, pass_no,phone_no;
	int choice, datedep, date, month, year;
	bool ans;
	char ch;
	time_t t= time(NULL);
	tm* timePtr=localtime(&t);
	date=(timePtr->tm_mday);
	month=(timePtr->tm_mon)+1;
	year=(timePtr->tm_year)+1900;

	back2:
	cout<<endl<<"Appuyez sur 1 pour reserver"
	<<endl<<"Appuyez sur 2 pour les lignes aeriennes"
	<<endl<<"Appuyez sur 3 pour les reclamations"
	<<endl<<"Appuyez sur 4 pour A propos"
	<<endl<<"Appuyez sur 5 pour modifier"
	<<endl<<"Appuyez sur 0 pour quitter\n";
	choice = getch();
	system("cls");
	switch(choice)
	{
		case 49:
			{
				my:
				cout<<">>>>>>>>>>reservation<<<<<<<<<<<\n";
				client *ptr;
				cout<<"Entrer votre nom: ";
				cin>>f_name;
				cin.ignore();
				cout<<"Entrer votre Prenom: ";
				getline(cin,l_name);
				cout<<"Entrer votre adresse: ";
				getline(cin,add);
				cout<<"Entrer votre telephone:  ";
				cin>>phone_no;
				date:
				cout<<"Entrez la date de depart (JJMMAAAA): ";
				cin>>datedep;
				reservation obj1(f_name,l_name,phone_no,add,pass_no,datedep);
				ptr = &obj1;
				back:
				cout<<endl<<"1.Destination locale\n2.Destination internationale\n3.Retour\n4.Quitter\n";
				choice = getch();

				if(choice==49)
				{

					if(ptr->ldest()==false)
					{
						cout<<endl<<"Nous ne desservons pas cet endroit\nVeuillez choisir a nouveau\n";
						goto back;
					}
					else
					{
						cout<<endl<<"Oui, nous volons\n";
						ptr->classe();
						ptr->repas();
						ptr->Registration();
						system("cls");
						ans = ptr->afficher();
						if(ans==false)
						{
							system("cls");
							goto back2;
						}
						else if(ans==true)
						{
							cout<<endl<<"Merci de voler avec nous"<<endl<<endl
							<<"Souhaitez-vous profiter de notre service Pick'n Drop ? (o/n)";
							ch = getch();
							if(ch=='o'||ch=='O')
								ptr->conduire();
							else if(ch=='n' || ch=='N')
							{
								ofstream ofile;
								ofile.open("voyage .txt", ios::app);
								ofile<<endl<<endl<<"Pick'n Drop: Non";
								ofile.close();
							}
							getch();
							system("cls");
							goto back2;
						}
					}
				}
				else if(choice==50)
				{
					cout<<endl<<"Entrez votre numero de passeport (sans \"-\") : ";
					cin>>pass_no;
					ans = ptr->idest(pass_no);
					if(ans==false)
					{
						cout<<endl<<"Nous ne volons pas vers cet endroit\n";
						goto back;
					}
					else
					{
						cout<<endl<<"Oui, nous volons\n";
						ptr->classe();
						ptr->repas();
						ptr->Registration();
						system("cls");
						ans = ptr->afficher();
						if(ans==false)
						{
							system("cls");
							goto back2;
						}
						else if(ans==true)
						{
							cout<<endl<<"Merci de voler avec nous"<<endl<<endl
							<<"Souhaitez-vous profiter de notre service Pick'n Drop ? (o/n)";
							ch = getch();
							if(ch=='o'||ch=='O')
								ptr->conduire();
							else if(ch=='n' || ch=='N')
							{
								ofstream ofile;
								ofile.open("voyage.txt", ios::app);
								ofile<<endl<<endl<<"Pick'n Drop: NO";
								ofile.close();
							}
							getch();
							system("cls");
							goto back2;
						}
					}
				}
				else if(choice==51)
				{
					system("cls");
					goto back2;
				}
				else
					exit(0);
				break;
			}

			case 50:	//choice = 2
				{
					cout<<">>>>>>>>>>ROUTES<<<<<<<<<<<\n";
					routes obj;
					ans = obj.print();
					if(ans==true)
						goto my;
					else if(ans==false)
					{
						cout<<endl;
						system("cls");
						goto back2;
					}
					break;
				}

			case 51:	//choice = 3
				{
					cout<<">>>>>>>>>>Reclamation<<<<<<<<<<<\n";
					cout<<"Entrer votre nom:";
					cin>>f_name;
					cin.ignore();
					cout<<"Entrer votre prenom: ";
					getline(cin,l_name);
					cout<<"Entrer votre telephone ";
					cin>>phone_no;
					reclamation obj(f_name,l_name,phone_no);
					obj.type();
					system("cls");
					goto back2;
					break;
				}

			case 52:	//choice = 4
				{
					cout<<"\t\t>>>>>>>>>>A PROPOS<<<<<<<<<<<\n";
					apropos obj;
					obj.aproposnous();
					getch();
					system("cls");
					goto back2;
					break;
				}
			case 53:
				{
					cout<<">>>>>>>>>>GERER<<<<<<<<<<<\n";
					modification pass;
					chnge:
					choice= pass.change();
					if (choice==1)
					{
						sleep(2);
						system("cls");
						goto back2;
					}
					else
					{
						cout<<"No record found\n";
						goto chnge;
					}

					break;
				}

			case 48:	//choice = 0
				{
					exit(0);
				}

			default:
				cout<<endl<<endl<<"ERROR!!!";
				goto back2;
	}
        return 0;
}

bool datecheck(int datedep, int date, int month, int year)
{
	if((datedep%10000)>2022&&(datedep%10000)==year)
		if(((datedep/10000)%100)>0 && ((datedep/10000)%100)<13&&((datedep/10000)%100)==month)
			if((datedep/1000000)>0 && (datedep/1000000)<32&&(datedep/1000000)>date&&(datedep/1000000)<(date+20))
				return true;
	else
		return false;
}
