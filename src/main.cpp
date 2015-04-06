#include <iostream>
#include <cys-engine/cys-engine.h>
#include <pthread.h>
#include <string>

using namespace std;

int __server_status;

void *thread_shell(void *data)
{
  std::string cmd;
  
  while(!__server_status) {
    
    cout << "Enter the command to execute. Type 'help' for a list of the availables commands" << endl;
    cin >> cmd;
    
    if(cmd == std::string("help")) {
      cout << "quit: quit cys-server" << endl;
    }
    else if(cmd == std::string("quit")) {
      __server_status = 1;
    }
  }
  
  return NULL;
}

int main(int argc, const char *argv[])
{
  pthread_t thread_shell_id;
  
  __server_status = 0;
  cout << "cys-server: start" << endl;
  
  // allow to use shell
  pthread_create(&thread_shell_id, NULL, thread_shell, NULL);
  
  // launch the server work code
  // ...
  while(!__server_status);
  
  // close shell
  pthread_cancel(thread_shell_id);
  
  cout << "cys-server: stop" << endl;
  
  return 0;
}

