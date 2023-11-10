#include<iostream>
#include <sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<cstring>
#include <string>

using namespace std;  
const int port = 23333;
const char* ip_addr = "127.0.0.1";
void logs(string message){
    cout<<message<<endl;
    exit(1);
}


int main(){
    int sock = 0;
    struct sockaddr_in serv_addr;

    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1){
        logs("socket creation failed");
        exit(1);
    }else{
        cout<<"socket created"<<endl;
    }   

    memset(&serv_addr,0,sizeof(serv_addr));  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port);

    
    if(connect(sock,(struct sockaddr*) &serv_addr,sizeof(serv_addr)) == -1){
        logs("connect error!");
        exit(1);
    }   
    else{
        cout<<"connect success!"<<endl;
    }

    char a[9];
    char b[9];
    cout<<"请输入你要传输的话(按q退出)：";
    cin>>a;
    cout<<endl;
    if(a[0] == 'q'){
        return 1;
    }
    write(sock,&a,sizeof(a));
    read(sock,&b,sizeof(a));
    cout<<"从服务器传来的消息为："<<b<<endl;  

    close(sock);

    return 0;
}