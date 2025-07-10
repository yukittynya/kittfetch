git pull origin main 

git add Makefile
git add notes
git add push.sh
git add README.md 

git add src/main.c 

# utils/
git add src/utils/result.h 

# info/
git add src/modules/modules.h
git add src/modules/distro.c
git add src/modules/kernel.c

echo "Message qt3.14?"
read msg 

git commit -m "${msg}"
git push origin main
