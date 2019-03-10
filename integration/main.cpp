#include "main.h"

/**
* BLACKFISH LABS
* PROJECT BY JEFERSON CRUZ
* LINKER -lws2_32 -lole32 -loleaut32
*
*/

DLL_EXPORT BSTR sobre()
{
    char* find = "BLACKFISH DLL 1.0 - PROJECT BY JEFERSON CRUZ";
    BSTR resultado;
    resultado = SysAllocStringByteLen(find, lstrlen(find));
    return resultado;
}

// NFE
DLL_EXPORT BSTR emitir(char* nfe, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfe/emitir HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";
    char dados[strlen("nfe=") + strlen(nfe) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "nfe=%s&emitente=%s&senha=%s", nfe, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFE
DLL_EXPORT BSTR cancelar(char* chave, char* justificativa, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfe/cancelar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&justificativa=") + strlen(justificativa) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "chave=%s&justificativa=%s&emitente=%s&senha=%s", chave, justificativa, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFE
DLL_EXPORT BSTR inutilizarFaixaNFe(char* ano, char* serie, char* numInicial, char* numFinal, char* justificativa, char* emitente, char* host, char* senha)
{

    char* method = "POST /nfe/inutilizar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("ano=") + strlen(ano) + strlen("&serie=") + strlen(serie) +strlen("&inicio=") + strlen(numInicial) + strlen("&final=") + strlen(numFinal) +strlen("&justificativa=") + strlen(justificativa)+strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "ano=%s&serie=%s&inicio=%s&final=%s&justificativa=%s&emitente=%s&senha=%s", ano, serie, numInicial, numFinal, justificativa, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFE
DLL_EXPORT BSTR statusDocumento(char* chave, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfe/status HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "chave=%s&emitente=%s&senha=%s", chave, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);

}

// NFE
BSTR download(char* chave, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfe/download HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "chave=%s&emitente=%s&senha=%s", chave, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFCE
DLL_EXPORT BSTR emitirNfce(char* nfe, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfce/emitir HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";
    char dados[strlen("nfce=") + strlen(nfe) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "nfce=%s&emitente=%s&senha=%s", nfe, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFCE
DLL_EXPORT BSTR cancelarNfce(char* chave, char* justificativa, char* emitente, char* host, char* senha)
{
    char* method = "POST /nfce/cancelar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&justificativa=") + strlen(justificativa) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "chave=%s&justificativa=%s&emitente=%s&senha=%s", chave, justificativa, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// NFCE
DLL_EXPORT BSTR inutilizarFaixaNFce(char* ano, char* serie, char* numInicial, char* numFinal, char* justificativa, char* emitente, char* host, char* senha)
{

    char* method = "POST /nfce/inutilizar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("ano=") + strlen(ano) + strlen("&serie=") + strlen(serie) +strlen("&inicio=") + strlen(numInicial) + strlen("&final=") + strlen(numFinal) +strlen("&justificativa=") + strlen(justificativa)+strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "ano=%s&serie=%s&inicio=%s&final=%s&justificativa=%s&emitente=%s&senha=%s", ano, serie, numInicial, numFinal, justificativa, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// MDFE
DLL_EXPORT BSTR emitirMDFe(char* mdfe, char* emitente, char* host, char* senha)
{
    char* method = "POST /mdfe/emitir HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";
    char dados[strlen("mdfe=") + strlen(mdfe) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "mdfe=%s&emitente=%s&senha=%s", mdfe, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// MDFE
DLL_EXPORT BSTR cancelarMDFe(char* chave, char* justificativa, char* emitente, char* host, char* senha)
{
    char* method = "POST /mdfe/cancelar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&justificativa=") + strlen(justificativa) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "chave=%s&justificativa=%s&emitente=%s&senha=%s", chave, justificativa, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// MDFE
DLL_EXPORT BSTR encerrarMDFe(char* chave, char* protocolo, char* codigoMunicipio, char* dataEncerramento, char* UF, char* emitente, char* host, char* senha)
{
    char* method = "POST /mdfe/encerrar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&protocolo=") + strlen(protocolo) + strlen("&codigoMunicipio=") + strlen(codigoMunicipio) + strlen("&dataEncerramento=") + strlen(dataEncerramento) + strlen("&UF=") + strlen(UF) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha) ];

    sprintf(dados, "chave=%s&protocolo=%s&codigoMunicipio=%s&dataEncerramento=%s&UF=%s&emitente=%s&senha=%s", chave, protocolo, codigoMunicipio, dataEncerramento, UF, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// CCE
DLL_EXPORT BSTR enviarCCe(char* chave, char* texto, char* emitente, char* host, char* senha)
{
    char* method = "POST /cce/enviar HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("chave=") + strlen(chave) + strlen("&texto=") + strlen(texto) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "chave=%s&texto=%s&emitente=%s&senha=%s", chave, texto, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

// STATUS
DLL_EXPORT BSTR statusSefaz(char* uf, char* emitente, char* host, char* senha)
{
    char* method = "POST /sefaz/status HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("uf=") + strlen(uf) + strlen("&emitente=") + strlen(emitente) + strlen("&senha=") + strlen(senha)];

    sprintf(dados, "uf=%s&emitente=%s&senha=%s", uf, emitente, senha);

    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

DLL_EXPORT BSTR execute(char* dados, char* host, char* contentType, char* connection, char* keepAlive, char* userAgent, char* method)
{
    char request[100000];

    strcpy(request, method);
    strcat(request, "\r\nHost: ");
    strcat(request, host);
    strcat(request, "\r\nContent-Length: ");

    int contentLength = strlen(dados);
    char contentLengthString[4];

    sprintf(contentLengthString, "%d", contentLength);
    strcat(request, contentLengthString);
    strcat(request, userAgent);
    strcat(request, keepAlive);
    strcat(request, connection);
    strcat(request, contentType);
    strcat(request,"\r\n\r\n");
    strcat(request, dados);

    WSADATA wsa;
    SOCKET s;

    struct sockaddr_in server;
    char server_reply[100000];

    int recv_size;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        printf("Failed. Error Code : %d",WSAGetLastError());
    }

    // Create a socket
    if((s = socket(AF_INET, SOCK_STREAM, 0 )) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }

    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8182 );

    // Connect to remote server
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
    }

    if( send(s, request, strlen(request), 0) < 0) {
    }

    // Receive a reply from the server
    if((recv_size = recv(s, server_reply, 100000, 0)) == SOCKET_ERROR) {
        printf("recv failed");
    }

    // Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';

    BSTR response;
    response = SysAllocStringByteLen(server_reply, lstrlen(server_reply));

    closesocket(s);
    WSACleanup();

    return response;
}

DLL_EXPORT BSTR extrairChaveNFe(char* response)
{
    int i;
    char* chNfe = (char*) malloc(sizeof(char)* 45);
    int counter = 0;

    for(i = 0; i < strlen(response); i++) {
        if (isdigit(response[i])) {
            chNfe[counter] = response[i];
            //printf("%c",response[i]);
            counter++;
            if(counter == 44) {
                break;
            }
        } else if(counter < 43) {
            //zerar tudo
            counter = 0;
            //TODO: free memory
            chNfe = (char*) malloc(sizeof(char)* 45);
        }
    }

    //Convert char* to BSTR
    if(strlen(chNfe) != 44) {
        chNfe = "";
    }

    BSTR chaveNFeVb;
    chaveNFeVb = SysAllocStringByteLen(chNfe, lstrlen(chNfe));

    return chaveNFeVb;
}

DLL_EXPORT BSTR extrairNProt(char* response)
{
    int i;
    char* chNfe = (char*) malloc(sizeof(char)* 16);
    int counter = 0;

    for(i = 0; i < strlen(response); i++) {
        if (isdigit(response[i])) {
            chNfe[counter] = response[i];
            //printf("%c",response[i]);
            counter++;
            if(counter == 15) {
                break;
            }
        } else if(counter < 14) {
            //zerar tudo
            counter = 0;
            //TODO: free memory
            chNfe = (char*) malloc(sizeof(char)* 45);
        }
    }

    //Convert char* to BSTR
    if(strlen(chNfe) != 15) {
        chNfe = "";
    }

    BSTR chaveNFeVb;
    chaveNFeVb = SysAllocStringByteLen(chNfe, lstrlen(chNfe));

    return chaveNFeVb;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}
