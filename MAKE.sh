clear

#directory to store build/compiled files
testFile=test.c

#directory to store build/compiled files
buildDir=../untracked/build

#directory for source files
sourceDir=source

#directory for source files
hlprDir=source/hlprs

#directory for test files
testDir=test

#make build directory if it doesn't exist
mkdir -p -v $buildDir


t=0.25
# -g = debug, -Os = Optimize Size
Compile=(avr-gcc -Wall -g -Os -I "includes/" -I "includes/hlprs" -DF_CPU=16000000 -mmcu=atmega1280 -c -o)
Link=(avr-gcc -Wall -g -mmcu=atmega1280 -o)
IHex=(avr-objcopy -j .text -j .data -O ihex)


echo -e ">> COMPILE: "${Compile[@]}" "$buildDir"/avr_usart.o "$sourceDir"/avr_usart.c"
"${Compile[@]}" $buildDir/avr_usart.o $sourceDir/avr_usart.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling avr_usart.c"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling avr_usart.c successful"
fi

echo -e "\n\r>> COMPILE: "${Compile[@]}" "$buildDir"/avr_spi.o "$sourceDir"/avr_spi.c"
"${Compile[@]}" $buildDir/avr_spi.o $sourceDir/avr_spi.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling avr_spi.c"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling avr_spi.c successful"
fi

echo -e "\n\r>> COMPILE: "${Compile[@]}" "$buildDir"/adc.o "$sourceDir"/adc.c"
"${Compile[@]}" $buildDir/adc.o $sourceDir/adc.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling adc.c"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling adc.c successful"
fi

echo -e "\n\r>> COMPILE: "${Compile[@]}" "$buildDir"/prints.o "$hlprDir"/prints.c"
"${Compile[@]}" $buildDir/prints.o $hlprDir/prints.c
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling prints.c"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling prints.c successful"
fi

echo -e ">> COMPILE: "${Compile[@]}" "$buildDir"/test.o " $testDir"/"$testFile
"${Compile[@]}" $buildDir/test.o $testDir/$testFile
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error compiling" $testFile
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Compiling" $testFile "successful"
fi


echo -e "\n\r>> LINK: "${Link[@]}" "$buildDir"/test.elf "$buildDir"/test.o  "$buildDir"/avr_spi.o "$buildDir"/avr_usart.o "$buildDir"/prints.o "buildDir"/adc.o"
"${Link[@]}" $buildDir/test.elf $buildDir/test.o $buildDir/avr_spi.o $buildDir/avr_usart.o $buildDir/prints.o $buildDir/adc.o
status=$?
sleep $t
if [ $status -gt 0 ]
then
    echo -e "error during linking"
    echo -e "program exiting with code $status"
    exit $status
else
    echo -e "Linking successful. Output in test.elf"
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
    echo -e "HEX file successfully generated. Output in test.hex"
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