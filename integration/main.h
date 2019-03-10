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

DLL_EXPORT BSTR sobre();
DLL_EXPORT BSTR execute(char* dados, char* host, char* contentType, char* connection, char* keepAlive, char* userAgent, char* method);
DLL_EXPORT BSTR extrairChaveNFe(char* response);
DLL_EXPORT BSTR extrairNProt(char* response);

// NFE
DLL_EXPORT BSTR emitir(char* nfe, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR cancelar(char* chave, char* justificativa, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR inutilizarFaixaNFe(char* ano, char* serie, char* numInicial, char* numFinal, char* justificativa, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR statusDocumento(char* chave, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR download(char* chave, char* emitente, char* host, char* senha);

// NFCE
DLL_EXPORT BSTR emitirNfce(char* nfe, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR cancelarNfce(char* chave, char* justificativa, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR inutilizarFaixaNFce(char* ano, char* serie, char* numInicial, char* numFinal, char* justificativa, char* emitente, char* host, char* senha);

// MDFE
DLL_EXPORT BSTR emitirMDFe(char* mdfe, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR cancelarMDFe(char* chave, char* justificativa, char* emitente, char* host, char* senha);
DLL_EXPORT BSTR encerrarMDFe(char* chave, char* protocolo, char* codigoMunicipio, char* dataEncerramento, char* UF, char* emitente, char* host, char* senha);

// CCE
DLL_EXPORT BSTR enviarCCe(char* chave, char* texto, char* emitente, char* host, char* senha);

// STATUS
DLL_EXPORT BSTR statusSefaz(char* uf, char* emitente, char* host, char* senha);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
