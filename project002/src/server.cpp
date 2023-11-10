#include<iostream>
#include <sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<cstring>
#include <string>

using namespace std;
const int port = 23333;
void logs(string message){
    cout<<message<<endl;
    exit(1);
}

int main(){
    int serv_sock = 0;
    int clnt_sock = 0;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1){
        logs("serv_sock error!"); 
        exit(1);   
    }else{
        cout << "serv_sock done"<<endl;
    }
    
    memset(&serv_addr,0,sizeof(serv_addr));  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if(bind(serv_sock,(struct sockaddr*) &serv_addr,sizeof(serv_addr)) == -1){
        logs("bind error!");
        exit(1);
    }else{
        cout << "bind done"<<endl;
    }
    if(listen(serv_sock,15) == -1){
        logs("listen error!");
        exit(1);
    }else{
        cout << "listen done"<<endl;
    }
    int num_cnt = 0;
    int num_op[256];

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock,(struct sockaddr*) &clnt_addr,&clnt_addr_size);
    if(clnt_sock == -1){
        logs("accept error!");
        exit(1);
    }    
    else{
        cout<<"accept success!"<<endl;
    }

    char a[9];
    read(clnt_sock,a,9);
    write(clnt_sock,a,9);
    
        

    close(clnt_sock);
    close(serv_sock);

    return 0;
}