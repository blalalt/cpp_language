#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

extern char** environ;

string get_env(string key)
{
  int key_len = key.size();
  int i;
  for (i=0; environ[i]; i++) {
    string _key = string(environ[i]);
    if (!key.compare(0, key_len, _key, 0, key_len))
    {
      string ret = _key.substr(key_len+1);
      return ret;
    }
  }
  return "Not found!";
}

int main(int argc, char* argv[])
{
  string key = string(argv[1]);
//  char* key = argv[1];
  printf("%s\n", get_env(key).c_str());
  return 0;
}
