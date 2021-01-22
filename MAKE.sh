clear

#directory to store build/compiled files
buildDir=../untracked/build

#directory for source files
sourceDir=source

#directory for test files
testDir=test

#make build directory if it doesn't exist
mkdir -p -v $buildDir


t=0.25
# -g = debug, -Os = Optimize Size
Compile=(avr-gcc -Wall -g -Os -I "includes/" -mmcu=atmega1280 -c -o)
Link=(avr-gcc -Wall -g -mmcu=atmega1280 -o)
IHex=(avr-objcopy -j .text -j .data -O ihex)


echo -e ">> COMPILE: "${Compile[@]}" "$buildDir"/test.o " $testDir"/test.c"
"${Compile[@]}" $buildDir/test.o $testDir/test.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling TEST.C"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling TEST.C successful"
fi


echo -e ">> COMPILE: "${Compile[@]}" "$buildDir"/usart0.o "$sourceDir"/usart0.c"
"${Compile[@]}" $buildDir/usart0.o $sourceDir/usart0.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling USART0.C"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling USART0.C successful"
fi


echo -e "\n\r>> COMPILE: "${Compile[@]}" "$buildDir"/prints.o "$sourceDir"/prints.c"
"${Compile[@]}" $buildDir/prints.o $sourceDir/prints.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling PRINTS.C"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling PRINTS.C successful"
fi


echo -e "\n\r>> COMPILE: "${Compile[@]}" "$buildDir"/spi.o "$sourceDir"/spi.c"
"${Compile[@]}" $buildDir/spi.o $sourceDir/spi.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling SPI.C"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling SPI.C successful"
fi


echo -e "\n\r>> LINK: "${Link[@]}" "$buildDir"/test.elf "$buildDir"/test.o  "$buildDir"/spi.o "$buildDir"/usart0.o "$buildDir"/prints.o"
"${Link[@]}" $buildDir/test.elf $buildDir/test.o $buildDir/spi.o $buildDir/usart0.o $buildDir/prints.o
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error during linking"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Linking successful. Output in TEST.ELF"
fi


echo -e "\n\r>> GENERATE INTEL HEX File: "${IHex[@]}" "$buildDir"/test.elf "$buildDir"/test.hex"
"${IHex[@]}" $buildDir/test.elf $buildDir/test.hex
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error generating HEX file"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "HEX file successfully generated. Output in TEST.HEX"
fi



echo -e "\n\r>> DOWNLOAD HEX FILE TO AVR"
echo "avrdude -p atmega1280 -c dragon_jtag -U flash:w:test.hex:i -P usb"
avrdude -p atmega1280 -c dragon_jtag -U flash:w:$buildDir/test.hex:i -P usb
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error during download of HEX file to AVR"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Program successfully downloaded to AVR"
fi