#include "main.h"

/**
* BLACKFISH LABS
* PROJECT BY JEFERSON CRUZ
* LINKER -lws2_32 -lole32 -loleaut32
*/

DLL_EXPORT BSTR sobreforza()
{
    char* find = "FORZA DLL - BLACKFISH LABS";
    BSTR resultado;
    resultado = SysAllocStringByteLen(find, lstrlen(find));
    return resultado;
}

DLL_EXPORT BSTR statusforza(char* host)
{
    char* method = "GET /status/server HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[1];
    sprintf(dados, "%s", "");
    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

DLL_EXPORT BSTR carga(char* host, char* json)
{
    char* method = "POST /carga/upload HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("json=") + strlen(json)];
    sprintf(dados, "json=%s", json);
    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

DLL_EXPORT BSTR buscacarga(char* host, char* cnpj)
{
    char* method = "POST /carga/download HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("cnpj=") + strlen(cnpj)];
    sprintf(dados, "cnpj=%s", cnpj);
    return execute(dados, host, contentType, connection, keepAlive, userAgent, method);
}

DLL_EXPORT BSTR pedidofaturado(char* host, char* order)
{
    char* method = "POST /order/status/invoiced HTTP/1.1";
    char* userAgent = "\r\nUser-Agent: BLACKFISH DLL";
    char* keepAlive = "\r\nKeep-Alive: 300";
    char* connection = "\r\nConnection: keep-alive";
    char* contentType = "\r\nContent-Type: application/x-www-form-urlencoded";

    char dados[strlen("order=") + strlen(order)];
    sprintf(dados, "order=%s", order);
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
    server.sin_port = htons( 8185 );

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
