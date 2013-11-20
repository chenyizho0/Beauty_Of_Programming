#########################################################################
# File Name: git.sh
# Author: laixukai
# mail: laixukai@126.com
# Created Time: 2013年11月19日 星期二 20时54分19秒
#########################################################################
#!/bin/bash

git init
git commit -m "$(date)"
#git remote add origin git@github.com:chenyizho0/Beauty_Of_Programming.git
git add .
git push -u origin master
