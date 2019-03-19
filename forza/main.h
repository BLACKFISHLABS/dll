#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <ctype.h>
#include <string.h>
#include <ole2.h>
#include <oleauto.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

DLL_EXPORT BSTR sobreforza();
DLL_EXPORT BSTR statusforza(char* host);
DLL_EXPORT BSTR carga(char* host, char* json);
DLL_EXPORT BSTR buscacarga(char* host, char* cnpj);

DLL_EXPORT BSTR execute(char* dados, char* host, char* contentType, char* connection, char* keepAlive, char* userAgent, char* method);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
