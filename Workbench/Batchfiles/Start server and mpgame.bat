cd S:\Steam\steamapps\common\DayZserver\
start DayZDiag_x64.exe -server -filePatching "-config=serverDZ.cfg" "-port=2302" "-profiles=ServerProfile" -dologs -adminlog -freezecheck "-scriptDebug=true" "-cpuCount=4" "-mission=.\MPMissions\dayzOffline.chernarusplus" "-mod=@RB5;@CF;@Community-Online-Tools;@Code Lock"

cd S:\Steam\steamapps\common\DayZ
start DayZ_x64.exe "-mod=@RB5;@CF;@Community-Online-Tools;@Code Lock" -dologs -adminlog -freezecheck "-scriptDebug=true" -connect=127.0.0.1:2302
