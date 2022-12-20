@echo off

cd /D "%~dp0"

IF exist "P:\RB5\" (
	echo Removing existing link P:\RB5
	rmdir "P:\RB5\"
)

echo mklink /J "P:\RB5\" "%~dp0"
mklink /J "P:\RB5\" "%~dp0"

echo Done
