#include "libhashblade.hpp"

void splash ()
{
	system(CLEAR);
    cout << "  _   _           _     ____  _           _            "  << endl;
    cout << " | | | | __ _ ___| |__ | __ )| | __ _  __| | ___       "  << endl;
    cout << " | |_| |/ _` / __| '_ \\|  _ \\| |/ _` |/ _` |/ _ \\   "  << endl;
    cout << " |  _  | (_| \\__ \\ | | | |_) | | (_| | (_| |  __/    "  << endl;
    cout << " |_| |_|\\__,_|___/_| |_|____/|_|\\__,_|\\__,_|\\___|  "  << endl;
    cout << "                                           v1.0.0      "  << endl;
    cout << "   Encrypt files, texts perform Brute Force, etc.      "  << endl;
    cout << "      Through Hash MD5, SHA1, SHA256, SHA512.          "  << endl  << endl;
    cout << "        >>> Developer: Walderlan Sena <<<              "  << endl; 
    cout << "          contato@mentesvirtuaissena.com               "  << endl; 
    cout << "       https://www.MentesVirtuaisSena.com              "  << endl  << endl; 

}//end método splash

void help ()
{
	cout << "Usage: ./hashblade or hashblade.exe <OPTIONS>... <STRING>... 					"  	<< 	endl	<< endl;
    cout << "Options:                                                     					"  	<< 	endl	<< endl;
    cout << "\t-md5\t\t- to perform encryption with the MD5 algorithm       				"  	<< 	endl;
    cout << "\t-sha1\t\t- to perform encryption with the SHA1 algorithm     				"  	<< 	endl;
    cout << "\t-sha256\t\t- to perform encryption with the SHA256 algorithm 				"  	<< 	endl;
    cout << "\t-sha512\t\t- to perform encryption with the SHA512 algorithm 				"  	<< 	endl	<< endl;


    cout << "Commands for brute force: 														"	<< 	endl 	<< endl;
	cout << "\tUsage: <OPTIONS> <WORDLIST> <HASHMD5,SHA1,SHA256,SHA512>    					"  	<< 	endl	<< endl;
    cout << "\t-md5-brute\t- Perform brute force attack on md5 hashes 						" 	<< 	endl;
    cout << "\t-sha1-brute\t- Perform brute force attack on sha1 hashes  					" 	<< 	endl;
    cout << "\t-sha256-brute\t- Perform brute force attack on sha256 hashes 				" 	<< 	endl;
    cout << "\t-sha512-brute\t- Perform brute force attack on sha512 hashes 				" 	<< 	endl 	<< endl;
    
    cout << "Other commands: 																"	<< 	endl 	<< endl;
    cout << "\t-help\t\t- Displays this usage screen 			   							"	<<	endl;
    cout << "\t-version\t- Displays the software version  		   							"	<<	endl;
    cout << "\t-list\t\t- read a list of values from a file and encrypt     				"	<<	endl;
	cout << "\t Usage: -list < -all, -md5, -sha1, -sha256, -sha512 > <WORDLIST> 				"  	<< 	endl	<< endl;

}

void init (int argc, const char *argv[])
{
	switch (argc) {
		case 1:
			splash();
			help();
			break;
		case 2:
			{
				string arg = argv[1];

				if (arg == "-md5-brute") {
					splash();
					cout << "Usage: ./hashblade or hashblade.exe -md5-brute <WORDLIST>... <HASHMD5>..." << endl;
					break;
				} else if (arg == "-sha1-brute") {
					splash();
					cout << "Usage: ./hashblade or hashblade.exe -sha1-brute <WORDLIST>... <HASHSHA1>..." << endl;
				} else if (arg == "-sha256-brute") {
					splash();
					cout << "Usage: ./hashblade or hashblade.exe -sha256-brute <WORDLIST>... <HASHSHA256>..." << endl;
				} else if (arg == "-sha512-brute") {
					splash();
					cout << "Usage: ./hashblade or hashblade.exe -sha512-brute <WORDLIST>... <HASHSHA512>..." << endl;
				} else if (arg == "-help") {
					system(CLEAR);
					cout << "HashBlade - " << VERSION << endl;
					help();
				} else if (arg == "-version") {
					system(CLEAR);
					cout << "HashBlade - " << VERSION << endl;
					cout << "by: Walderlan Sena  - 2017" << endl;
				} else {
					string optionsHashs[] = {"-md5", "sha1", "sha256", "sha512"};
					//Traversing the array with the possibilities of hashes
					for (int i = 0; i < 4; i++) {
						if (arg == optionsHashs[i]) {
							splash();
							help();
							break;
						} else {
							//If no argument referring to hash is passed, it executes all possible hashes
							splash();
							cout << " [ Hash File or Text - " << argv[1] << " ]" << " DATE: " << __DATE__ << " HOUR: " << __TIME__ << endl << endl;
							cout << " + MD5    + >>> " << md5(arg)    << endl << endl;
							cout << " + SHA1   + >>> " << sha1(arg)   << endl << endl;
							cout << " + SHA256 + >>> " << sha256(arg) << endl << endl;
							cout << " + SHA512 + >>> " << sha512(arg) << endl << endl;
							break;
						}//end if
					}//end for
				}//end if
			}//end bloco
			break;
		
		case 3:
			{	
				string options[] = {"-md5", "-sha1", "-sha256", "-sha512", "-list"};
				string arg = argv[1];
				//Tie that checks which encryption algorithm was requested
				for (int i = 0; i < 5; i++) {
					if (arg == options[i]) {
						splash();
						cout << " [ Hash File or Text - " << argv[2] << " ]" << " DATE: " << __DATE__ << " HOUR: " << __TIME__ << endl << endl;
						if (arg == "-md5")
							cout << " + MD5 + => " << md5(argv[2]) << endl;
						else if (arg == "-sha1")
							cout << " + SHA1 + => " << sha1(argv[2]) << endl;
						else if (arg == "-sha256")
							cout << " + SHA256 + => " << sha256(argv[2]) << endl;
						else if (arg == "-sha512")
							cout << " + SHA512 + => " << sha512(argv[2]) << endl;			
						else
							help();
						break;
					} else {
						splash();
						help();
					}//end if verify options
				}//end for
				break;
			}
		case 4:
			{
				//Stores past arguments
				string arg  = argv[1];
				string arg2 = argv[2];
				//Verification of the request in the use of which brute-force algorithm
				if (arg == "-md5-brute") {
					splash();
					alg_forcebrute(argv[2], argv[3], "md5");
					break;
				} else if (arg == "-sha1-brute") {
					splash();
					alg_forcebrute(argv[2], argv[3], "sha1");
				} else if (arg == "-sha256-brute") {
					splash();
					alg_forcebrute(argv[2], argv[3], "sha256");
				} else if (arg == "-sha512-brute") {
					splash();
					alg_forcebrute(argv[2], argv[3], "sha512");
				} else if (arg == "-list") {
					//Passing the option to implement the encryption algorithm and the list
					openFile(argv[3], argv[2]);
				} else {
					splash();
					help();			
				}//end if		
			}//end bloco
			break;
		default:
			splash();
			help();
			break;
	}//end swicth
}//end verifyArguments

void openFile (char const *arq, string type)
{
	//Open and read file
	FILE *fileOpen = fopen(arq, "r");
	FILE *outFile  = fopen("listOut.txt", "w");
	//check if the file could be opened
	if (fileOpen != NULL) {
		//Receives each line read in each loop execution
		char lineRead[250];
		//Tie that runs through each line and implement all of the encryption files
		while (fscanf(fileOpen, "%s", &lineRead) != EOF) {
			if (type == "-md5") {
				cout << "Md5 >>> " << md5(lineRead) << endl;
			} else if (type == "-sha1") {
				cout << "Sha1 >>> " << sha1(lineRead) << endl;
			} else if (type == "-sha256") {
				cout << "Sha256 >>> " << sha256(lineRead) << endl;
			} else if (type == "-sha512") { 
				cout << "Sha512 >>> " << sha512(lineRead) << endl;
			} else if (type == "-all") {
				cout << "Line : " << lineRead << endl;
				cout << "Md5    >>> " << md5(lineRead)    << endl;
				cout << "Sha1   >>> " << sha1(lineRead)   << endl;
				cout << "Sha256 >>> " << sha256(lineRead) << endl;
				cout << "Sha512 >>> " << sha512(lineRead) << endl;
				cout << "-----------------------------------------------" << endl;
			} else {
				splash();
				help();
				break;
			}//end if
		}//end while
		//Closes the file
		fclose(fileOpen);
	} else {
		cout << "Could not read past file..." << endl;
	}
}//end openFile 

void alg_forcebrute (char const *arq, string hash, string type)
{
	//Open and read file
	FILE *fileOpen = fopen(arq, "r");
	
	//check if the file could be opened
	if (fileOpen != NULL) {
		//Receives each line read in each loop execution
		char lineRead[250];
		while (fscanf(fileOpen, "%s", lineRead)) {
			if (type == "md5") {
				if (md5(lineRead) == hash) {
					cout << endl << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl;
					cout << "+        >>> SENHA ENCONTRADA COM SUCESSO <<<      +" << "  " << lineRead << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl << endl;
					exit(0);
				} else {
					cout << "[ FAILED ] " <<  md5(lineRead) << " != " << hash << " ( " << lineRead << " )" << endl;
				}
			} else if (type == "sha1") {
				if (sha1(lineRead) == hash) {
					cout << endl << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl;
					cout << "+        >>> SENHA ENCONTRADA COM SUCESSO <<<      +" << "  " << lineRead << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl << endl;
					exit(0);
				} else {
					cout << "[ FAILED ] " <<  sha1(lineRead) << " != " << hash << " ( " << lineRead << " )" << endl;
				}
			} else if (type == "sha256") {
				if (sha256(lineRead) == hash) {
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl;
					cout << "+        >>> SENHA ENCONTRADA COM SUCESSO <<<      +" << "  " << lineRead << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl << endl;
					exit(0);
				} else {
					cout << "[ FAILED ] " <<  sha256(lineRead) << " != " << hash << " ( " << lineRead << " )" << endl;
				}
			} else if (type == "sha512") {
				if (sha512(lineRead) == hash) {
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl;
					cout << "+        >>> SENHA ENCONTRADA COM SUCESSO <<<      +" << "  " << lineRead << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" 	 << endl << endl;
					exit(0);
				} else {
					cout << "[ FAILED ] " <<  sha512(lineRead) << " != " << hash << " ( " << lineRead << " )" << endl;
				}
			} else {
				exit(0);
			}
		}//end while
		fclose(fileOpen);
	} else {
		cout << "Error: Not found wordlist " << arq << endl;
	}//end if
}