/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif
extern char **environ;
int main(int argc,char* argv[]) {
  int i = 1;
  while(putenv(argv[i]) != -1){
    i++;
  }
  if(i == argc){
    for(int i = 0;environ[i]!=NULL;i++){
            printf("%s\n",environ[i]);
        }
  }
  else{
  execvp(argv[i],&argv[i]);
  perror(argv[i]);
  return 1;
  }
}

/* 実行例
./myenv PATH=/usr/bin:/bin ls
Makefile        README.pdf      myenv.c         myputenv.h
README.md       myenv           myputenv.c

./myenv LC_TIME=ru_RU.UTF-8 date
вторник, 30 июня 2026 г. 11:54:49 (JST)
ここに実行例を書く

./myenv LC_TIME=C date
Tue Jun 30 11:54:10 JST 2026

 ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--@ 1 tamurasota  staff     132  6月 29 22:28 Makefile
-rw-r--r--@ 1 tamurasota  staff    1268  6月 29 22:28 README.md
-rw-r--r--@ 1 tamurasota  staff  139098  6月 29 22:28 README.pdf
-rwxr-xr-x  1 tamurasota  staff   33608  6月 29 22:53 myenv
-rw-r--r--@ 1 tamurasota  staff     332  6月 29 22:52 myenv.c
-rwxr-xr-x@ 1 tamurasota  staff     216  6月 29 22:28 myputenv.c
-rw-r--r--@ 1 tamurasota  staff      93  6月 29 22:28 myputenv.h

 ./myenv date
Tue Jun 30 12:51:07 JST 2026

何も引数を持たないとき
% ./myenv 
COMMAND_MODE=unix2003
CONDA_EXE=/opt/miniconda3/bin/conda
CONDA_PYTHON_EXE=/opt/miniconda3/bin/python
CONDA_SHLVL=0
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
FPATH=/opt/homebrew/share/zsh/site-functions:/opt/homebrew/share/zsh/site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
HOME=/Users/tamurasota
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
LANG=C.UTF-8
LOCAL_GIT_DIRECTORY=/Applications/GitHub Desktop.app/Contents/Resources/app/git
LOGNAME=tamurasota
MACH_PORT_RENDEZVOUS_PEER_VALDATION=1
MallocNanoZone=0
OLDPWD=/Users/tamurasota/Documents/GitHub/kadai09-so12321
OSLogRateLimit=64
PATH=/opt/homebrew/opt/openjdk/bin:/Users/tamurasota/.pyenv/shims:/Users/tamurasota/.pyenv/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Users/tamurasota/Library/Application Support/Code/User/globalStorage/github.copilot-chat/debugCommand:/Users/tamurasota/Library/Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/Library/Frameworks/Python.framework/Versions/3.15/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/pkg/env/active/bin:/opt/pmk/env/global/bin:/Library/Apple/usr/bin:/Library/TeX/texbin:/usr/local/share/dotnet:~/.dotnet/tools:/opt/homebrew/opt/openjdk/bin:/Users/tamurasota/.pyenv/bin:/opt/miniconda3/condabin
PWD=/Users/tamurasota/Documents/GitHub/kadai09-so12321
PYENV_SHELL=zsh
SHELL=/bin/zsh
SSH_AUTH_SOCK=/var/run/com.apple.launchd.kkF8YvrSoP/Listeners
TMPDIR=/var/folders/zb/pw9d4hp50q9bxs1yntp3p8qh0000gn/T/
USER=tamurasota
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
_CONDA_EXE=/opt/miniconda3/bin/conda
_CONDA_ROOT=/opt/miniconda3
__CFBundleIdentifier=com.microsoft.VSCode
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.124.0
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/zb/pw9d4hp50q9bxs1yntp3p8qh0000gn/T/vscode-git-b458c402e7.sock
COPILOT_DEBUG_NONCE=4d063efb12b2d06e5d9792e948ef82f5
CLAUDE_CODE_SSE_PORT=31909
VSCODE_INJECTION=1
ZDOTDIR=/Users/tamurasota
USER_ZDOTDIR=/Users/tamurasota
TERM=xterm-256color
SHLVL=1
VSCODE_PROFILE_INITIALIZED=1
_CE_M=
_CE_CONDA=
PYENV_ROOT=/Users/tamurasota/.pyenv
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/tamurasota/Documents/GitHub/kadai09-so12321/./myenv

% ./myenv SHLVL=2
COMMAND_MODE=unix2003
CONDA_EXE=/opt/miniconda3/bin/conda
CONDA_PYTHON_EXE=/opt/miniconda3/bin/python
CONDA_SHLVL=0
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
FPATH=/opt/homebrew/share/zsh/site-functions:/opt/homebrew/share/zsh/site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
HOME=/Users/tamurasota
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
LANG=C.UTF-8
LOCAL_GIT_DIRECTORY=/Applications/GitHub Desktop.app/Contents/Resources/app/git
LOGNAME=tamurasota
MACH_PORT_RENDEZVOUS_PEER_VALDATION=1
MallocNanoZone=0
OLDPWD=/Users/tamurasota/Documents/GitHub/kadai09-so12321
OSLogRateLimit=64
PATH=/opt/homebrew/opt/openjdk/bin:/Users/tamurasota/.pyenv/shims:/Users/tamurasota/.pyenv/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Users/tamurasota/Library/Application Support/Code/User/globalStorage/github.copilot-chat/debugCommand:/Users/tamurasota/Library/Application Support/Code/User/globalStorage/github.copilot-chat/copilotCli:/Library/Frameworks/Python.framework/Versions/3.15/bin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/pkg/env/active/bin:/opt/pmk/env/global/bin:/Library/Apple/usr/bin:/Library/TeX/texbin:/usr/local/share/dotnet:~/.dotnet/tools:/opt/homebrew/opt/openjdk/bin:/Users/tamurasota/.pyenv/bin:/opt/miniconda3/condabin
PWD=/Users/tamurasota/Documents/GitHub/kadai09-so12321
PYENV_SHELL=zsh
SHELL=/bin/zsh
SSH_AUTH_SOCK=/var/run/com.apple.launchd.kkF8YvrSoP/Listeners
TMPDIR=/var/folders/zb/pw9d4hp50q9bxs1yntp3p8qh0000gn/T/
USER=tamurasota
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
_CONDA_EXE=/opt/miniconda3/bin/conda
_CONDA_ROOT=/opt/miniconda3
__CFBundleIdentifier=com.microsoft.VSCode
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.124.0
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/zb/pw9d4hp50q9bxs1yntp3p8qh0000gn/T/vscode-git-b458c402e7.sock
COPILOT_DEBUG_NONCE=4d063efb12b2d06e5d9792e948ef82f5
CLAUDE_CODE_SSE_PORT=31909
VSCODE_INJECTION=1
ZDOTDIR=/Users/tamurasota
USER_ZDOTDIR=/Users/tamurasota
TERM=xterm-256color
SHLVL=2
VSCODE_PROFILE_INITIALIZED=1
_CE_M=
_CE_CONDA=
PYENV_ROOT=/Users/tamurasota/.pyenv
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
_=/Users/tamurasota/Documents/GitHub/kadai09-so12321/./myenv
*/
