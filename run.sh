#!/bin/sh
RED='\033[0;31m'
WHITE='\033[0;37m'
GREEN='\033[0;32m'
exp=$(echo "pickle rick" | md5) 
my=$(echo "pickle rick" | ./ft_ssl md5)
MD5="MD5"
md5="md5"
exp=${exp//$MD5/$md5}
echo "echo \"pickle rick\" | ./ft_ssl md5"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "Do not pity the dead, Harry." | md5 -p)
my=$(echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p)
exp=${exp//$MD5/$md5}
echo "echo \"Do not pity the dead, Harry.\" | ./ft_ssl md5 -p"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "Pity the living." | md5 -q -r)
my=$(echo "Pity the living." | ./ft_ssl md5 -q -r)
exp=${exp//$MD5/$md5}
echo "echo \"Pity the living.\" | ./ft_ssl md5 -q -r"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

echo "And above all," > file

exp=$(md5 file)
my=$(./ft_ssl md5 file)
exp=${exp//$MD5/$md5}
echo "/ft_ssl md5 file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(md5 -r file)
my=$(./ft_ssl md5 -r file)
exp=${exp//$MD5/$md5}
echo "./ft_ssl md5 -r file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$( md5 -s "pity those that aren't following baerista on spotify.")
my=$( ./ft_ssl md5 -s "pity those that aren't following baerista on spotify.")
exp=${exp//$MD5/$md5}
echo "./ft_ssl md5 -s \"pity those that aren't following baerista on spotify.\""
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "be sure to handle edge cases carefully" | md5 -p file)
my=$(echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file)
exp=${exp//$MD5/$md5}
echo "echo \"be sure to handle edge cases carefully\" | ./ft_ssl md5 -p file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "be sure to handle edge cases carefully" | md5 file)
my=$(echo "be sure to handle edge cases carefully" | ./ft_ssl md5 file)
exp=${exp//$MD5/$md5}
echo "echo \"be sure to handle edge cases carefully\" | ./ft_ssl md5 file"
echo $exp
echo $my 
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"

else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "but eventually you will understand" | md5 -p -r file)
my=$(echo "but eventually you will understand" | ./ft_ssl md5 -p -r file)
exp=${exp//$MD5/$md5}
echo "echo \"but eventually you will understand\" | ./ft_ssl md5 -p -r file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "GL HF let's go" | md5 -p -s "foo" file)
my=$(echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file)
exp=${exp//$MD5/$md5}
echo "echo \"GL HF let's go\" | ./ft_ssl md5 -p -s \"foo\" file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
echo "============================================"

exp=$(echo "just to be extra clear" | md5 -r -q -p -s "foo" file)
my=$(echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file)
exp=${exp//$MD5/$md5}
echo "echo \"just to be extra clear\" | ./ft_ssl md5 -r -q -p -s \"foo\" file"
echo $exp
echo $my
if [ "$my" = "$exp" ]
then
    echo "${GREEN}OK${WHITE}"
else
    echo "${RED}FAIL${WHITE}"
fi
