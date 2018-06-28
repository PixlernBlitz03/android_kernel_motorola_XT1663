#!/bin/sh
echo ""
tput setaf 1;
tput bold;
echo "  _________________________ _____________________"
echo " /   _____/\__    ___/  _  \\______   \__    ___/"
echo " \_____  \   |    | /  /_\  \|       _/ |    |   "
echo " /        \  |    |/    |    \    |   \ |    |   "
echo "/_______  /  |____|\____|__  /____|_  / |____|   "
echo "        \/                 \/       \/           "

echo "Blitz Kernel By Ninad Patil Powered By Reignz"
PATH=${PATH}:~/toolchains/UBERTC/aarch64-linux-android-4.9/bin
export KBUILD_BUILD_USER="Ninad"
export KBUILD_BUILD_HOST="REIGNZ"
PATH=${PATH}:~/toolchains/UBERTC/aarch64-linux-android-4.9/bin
export ARCH=arm64
make kungfu_m_defconfig ARCH=arm64 CROSS_COMPILE=aarch64-linux-android-
make -j5 ARCH=arm64 CROSS_COMPILE=aarch64-linux-android-

#echo " ______ _______   __ _      ___________ _   _  ______ _     _____ ___________ "
#echo " | ___ \_   _\ \ / /| |    |  ___| ___ \ \ | | | ___ \ |   |_   _|_   _|___  /"
#echo " | |_/ / | |  \ V / | |    | |__ | |_/ /  \| | | |_/ / |     | |   | |    / / "
#echo " |  __/  | |  /   \ | |    |  __||    /|     | | ___ \ |     | |   | |   / /  "
#echo " | |    _| |_/ /^\ \| |____| |___| |\ \| |\  | | |_/ / |_____| |_  | | ./ /___"
#echo " \_|    \___/\/   \/\_____/\____/\_| \_\_| \_/ \____/\_____/\___/  \_/ \_____/"
#echo "                                                                             "
#echo "                                                                             "

echo ""
tput setaf 2;
tput bold
echo "       (     (               )  "
echo "   (   )\ )  )\ )  *   )  ( /(  "
echo " ( )\ (()/( (()/(` )  /(  )\()) "
echo " )((_) /(_)) /(_))( )(_))((_)\  "
echo "((_)_ (_))  (_)) (_(_())  _((_) "
echo " | _ )| |   |_ _||_   _| |_  /  "
echo " | _ \| |__  | |   | |    / /   "
echo " |___/|____||___|  |_|   /___|  "
