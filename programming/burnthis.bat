REM Fix the offset number on the line below so that when a TSL is done being programmed it ends up with the right time. 
tsl-make-block tsl-eeprom-block.bin 6

REM Fix the path below to point to your `atprogram.exe`
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 program --chiperase --flash --format hex --verify --file tsl.hex program --eeprom --format bin --verify --file tsl-eeprom-block.bin

