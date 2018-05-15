@ECHO OFF
SETLOCAL
SET scriptpath=%~dp0
SET rootpath=%scriptpath%..\..

REM Get command line argument
IF "%1"=="" (SET CONN_VERSION=0.0.0
) ELSE (SET CONN_VERSION=%1)

IF NOT EXIST %rootpath%\sdk\s122 (
    ECHO "SDK 12 not downloaded, please run build_v3_win.bat first"
    EXIT /b 1
)

ECHO ON

@ECHO Run bootstrap script
cd %scriptpath%
"c:\program files\git\bin\bash.exe" bootstrap_sd_api_v3_usb.sh

@ECHO Workaround to reduce path length before build
cd %rootpath%\sdk
rename nRF5_SDK_15.0.0_a53641a s15

@ECHO Compile
cd %rootpath%\sdk\s15\examples\connectivity\ble_connectivity\pca10059\ser_s132v3_usb_hci\arm5_no_packs
\Keil_v5\UV4\UV4.exe -b ble_connectivity_s132v3_usb_hci_pca10059.uvprojx -j0 -o log_usb.txt

@ECHO Copy HEX only
cp _build\nrf52840_xxaa.hex %rootpath%\sdk\connectivity_%CONN_VERSION%_usb_for_s132_3.0.hex

@ECHO Merge hex
"c:\Program Files (x86)\Nordic Semiconductor\nrf5x\bin\mergehex.exe" -m _build\nrf52840_xxaa.hex %rootpath%\sdk\s122\components\softdevice\s132\hex\s132_nrf52_3.0.0_softdevice.hex -o %rootpath%\sdk\connectivity_%CONN_VERSION%_usb_with_s132_3.0.hex

@ECHO Checking that the output files exist
@IF NOT EXIST %rootpath%\sdk\connectivity_%CONN_VERSION%_usb_for_s132_3.0.hex EXIT /b 1
@IF NOT EXIST %rootpath%\sdk\connectivity_%CONN_VERSION%_usb_with_s132_3.0.hex EXIT /b 1
@ECHO Success