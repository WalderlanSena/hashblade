/**
 *  HashBlade - Encrypted texts and perform Brute Force
 *  @Version  : v1.0.0
 *  @author   : Walderlan Sena <eu@walderlan.xyz>
 *  @site     : https://www.mentesvirtuaissena.com
 *  @code     : https://github.com/WalderlanSena/hashblade
 *	@license  : MIT <https://github.com/WalderlanSena/hashblade/blob/master/LICENSE>
 *  @describe : Encrypted texts and perform Brute Force. Through Hash MD5, SHA1, SHA256, SHA512.. In all operating systems Gnu/Linux, Windows, MacOs.
 *
 */ 
#ifndef LIBHASHBLADE_HPP
#define LIBHASHBLADE_HPP

//Importing standard operating system libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
//Importing encryption libraries
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha512.h"

//version of the program
#define VERSION "v1.0.0"

//operating system check
#ifdef WIN32
    #define PAUSE 1
    #define CLEAR "cls"
#else
    #define PAUSE 0
    #define CLEAR "clear"
#endif

using std::cout; 
using std::endl; 
using std::string; 
using std::fstream;
using std::ios;

/**
 *	Shows the banner related to the software
 */
void splash (void);

/**
 *	Displays help regarding program usage
 */
void  help (void);

/**
 *	Starts the Software, receives the main parameters
 *	@params argc (Number of parameters) - argv (Parameters passed)
 */
void init (int argc, const char *argv[]);

/**
 *	Performs the reading of a wordlist to perform encryption
 */
void openFile (char const *arq, string type);

/**
 *	Implementation of the brute-force algorithms
 */
void alg_forcebrute (char const *arq, string hash, string type);

#endif